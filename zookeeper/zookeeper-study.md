### 1. 概述：

众所周知，分布式协调服务很难正确无误的实现，它们很容易在竞争条件和死锁上犯错误。如何在这方面节省力气？
Zookeeper是一个不错的选择。 Zookeeper背后的动机就是解除分布式应用在实现协调服务上的痛苦
。这里在介绍Zookeeper的基本理论基础上，用Zookeeper实现了一 个配置管理中心，利用Zookeeper将配置信息分发到各个服务节点上，
并保证信息的正确性和一致性。

引用官方的说法：“Zookeeper是一个高性能，分布式的，开源分布式应用协调服务。
它提供了简单原始的功能，分布式应用可以基于它实现更高级 的服务，比如同步，配置管理，集群管理，名空间。
它被设计为易于编程，使用文件系统目录树作为数据模型。服务端跑在java上，提供java和C的客户端 API”。

Zookeeper 从设计模式角度来看，是一个基于观察者模式设计的分布式服务管理框架，它负责存储和管理大家都关心的数据.
然后接受观察者的注册，一旦这些数据的状态发生变化，Zookeeper 就将负责通知已经在 Zookeeper 上注册的那些观察者做出相应的反应，
从而实现集群中类似 Master/Slave 管理模式.

### 2. Zookeeper 总结构：

Zookeeper服务自身组成一个集群(2n+1个服务允许n个失效)。Zookeeper服务有两个角色，一个是leader，负责写服务和数据同步，剩下的是follower，
提供读服务，leader失效后会在follower中重新选举新的leader。

- 逻辑图 ：

![image](http://ww1.sinaimg.cn/mw1024/e91aafadjw1fadcyo2r6pj20gr058dgc.jpg)

```
- 客户端可以连接到每个server，每个server的数据完全相同。
- 每个follower都和leader有连接，接受leader的数据更新操作。
- Server记录事务日志和快照到持久存储。
- 大多数server可用，整体服务就可用。
```

在同步状态时, 一旦半数以上的 follower已经将其状态与leader 同步, 则表明这个集群状态已经同步.

所有的写操作都会被转发给leader, 再由leader将更新广播给follower, 当半数以上的follower已经将这个修改持久化后, leader 才会提交这个更新, 客户端才会提交这个响应.

- 数据模型 ：

Zookeeper 表现为一个分层的文件系统目录树结构（不同于文件系统的是，节点可以有自己的数据，而文件系统中的目录节点只有子节点）。

![image](http://ww1.sinaimg.cn/mw1024/e91aafadjw1faddap3t46j20c706yaad.jpg)

Zookeeper 维护着一个树形层次结构， 输的节点被称为 **znode** 可以用户存储数据， 并且有一个与之相关的 ACL.
Zookeeper 被设计用来实现协调服务(这类服务通常使用小数据文件)，而不是用于大容量数据存储。

Zookeeper的数据访问具有原子性,客户端在读取一个 znode 的数据时,要么将读取到所有的内容，要么读取失败，
不会只有部分数据被读取，同样，一个写操作将替换znode中的所有内容，zookeeper会保证写操作不成功就失败，
不会只出现部分写的情况（不能追加操作）。

### 3. Zookeeper API

- 建立连接 :

zookeeper 建立与服务器的连接可以通过创建　**ZooKeeper** 实例来实现 `Zookeeper zk = new ZooKeeper(hostName, SESSION_TIMEOUT, this);`
创建　Zookeeper 需要三个参数　: **zookeeper服务地址** ， **连接的超时时间** ，　**Watcher对象**.

watcher 对象用来接受来自　zookeeper的回调，用来获取各种来自 zookeeper服务器的消息通知．

- 创建节点 :　

zk.create(path, data, acl, model);

创建节点可以携带数据，　并且需要指定节点的类型．

```
- CreateMode.PERSISTENT 　              持久znode
- CreateMode.EPHEMERAL　　              暂时 znode
- CreateMode.EPHEMERAL_SEQUENTIAL       顺序号
```

- 删除节点 :

zk.delete(path, version);

删除节点需要指定　`version`, 因为每一个node 都有一个版本号，　当版本号与指定的version相一致的时候，node 才会被删除．

注：　

```
- version 为　-1 ，将忽略node的版本匹配
- delete 方法不能递归删除，这意味着如果存在子节点，则删除失败．
```

- 列出子节点 :

zk.getChildren(path, isWatcher);

> 实例：

```
public class ZkWatcher implements Watcher {

    private static final int SESSION_TIMEOUT = 5000;
    private ZooKeeper zk = null;
    private CountDownLatch countDownLatch  = new CountDownLatch(1);

    // 连接　zookeeper 服务器


    // 连接后的　zookeeper 的回调信息
    /*
    * 当客户端已经与 Zookeeper 服务建立连接后，　Watcher 的　process() 方法会被调用．
     */
    public void process(WatchedEvent watchedEvent) {

        System.out.println("== trigger : " + watchedEvent.getState().getIntValue());

        if(watchedEvent.getState() == Event.KeeperState.SyncConnected){
            countDownLatch.countDown();
        }
    }

    // 创建节点
    public String create(String path, CreateMode model) throws KeeperException, InterruptedException {
        /*
        * 创建节点有两种类型　: 暂时性的跟持久性的．
        * 　CreateMode.PERSISTENT
        *   CreateMode.EPHEMERAL
         */
        return zk.create(path,null, ZooDefs.Ids.OPEN_ACL_UNSAFE, model);

    }

    // 列出子节点
    /*
    * 获取指定节点的子节点信息
     */
    public List<String> list(String path) throws KeeperException, InterruptedException {

        List<String> childs = zk.getChildren(path, false);

        return childs;
    }

    // 删除组
    public void delete(String groupName) throws KeeperException, InterruptedException {
        List<String> childs = this.list(groupName);
        /**
         *  zookeeper 要删除一个组，必须提供两个参数，　路径名+版本号. 如果所提供的版本号跟　znode 的版本号保持一致,
         *  则　zk 将删除这个　znode .通过将版本号设置成　-1 , 可以绕开这个版本检测机制．
         *
         *  zookeeper 不支持递归的删除操作，因此删除父节点钱必须先删除子节点.
         */
        for(String child : childs){
            zk.delete(groupName + "/" + child, -1 );
        }

        zk.delete(groupName, -1);
    }
    // 关闭连接
    public void close() throws InterruptedException {
        zk.close();
    }
}
```

### ４.Zookeeper 服务

- 短暂 znode 类型:

```
1. 在创建短暂znode的客户端会话结束时，此znode将被删除。

2. 短暂znode 不允许有子节点， 即使是一个短暂子节点。

3. 虽然每个短暂 znode 都会被绑定到一个客户端会话， 但它们对所有的客户端还是可见的（符合 acl 权限）。
```

- 持久 znode :

```
持久znode 不依赖于客户端会，而且只有当客户端明确要删除该持久znode 时才会被删除。
```

- Sequence Nodes :

```
Sequence Nodes 是指名称中包括Zookeeper 指定顺序号的znode 。如果在创建znode 时设置了顺序表示，
那么该znode 名称之后便会附加一个值， 这个值是由一个单调递增的计数器所添加的。
```

- Watches :

```
ZooKeeper中的Watch是只能触发一次。
也就是说，如果客户端在指定的ZNode设置了Watch，如果该ZNode数据发生变更，ZooKeeper会发送一个变更通知给客户端，同时触发设置的Watch事件。
如果ZNode数据又发生了变更，客户端在收到第一次通知后没有重新设置该ZNode的Watch，则ZooKeeper就不会发送一个变更通知给客户端。
ZooKeeper异步通知设置Watch的客户端。但是ZooKeeper能够保证在ZNode的变更生效之后才会异步地通知客户端，然后客户端才能够看到ZNode的数据变更。
由于网络延迟，多个客户端可能会在不同的时间看到ZNode数据的变更，但是看到变更的顺序是能够保证有序一致的。
```

watcher 触发类型 :

```
类型         |  CreateNode , CreateChildrenNode , setData , DeleteChildrenNode, DeleteNode
--------------------------------------------------------------------------------------------
exists       |  CreateNode                        setData                       DeleteNode
getChildren  |               CreateChildrenNode             DeleteChildrenNode  DeleteNode
getData      |                                     setData                      DeleteNode
```


- ACL 列表

```
scheme : id : permissions
schema      : 使用哪一种机制
id          : 用户
permissions ：表示相关权限（如只读，读写，管理等）
```
**schema:**

- world: 它下面只有一个id, 叫anyone,  world:anyone代表任何人，zookeeper中对所有人有权限的结点就是属于world:anyone

- auth: 它不需要id, 只要是通过authentication的user都有权限（zookeeper支持通过kerberos来进行authencation, 也支持username/password形式的authentication)

- digest: 它对应的id为username:BASE64(SHA1(password))，它需要先通过username:password形式的authentication

- ip: 它对应的id为客户机的IP地址，设置的时候可以设置一个ip段，比如ip:192.168.1.0/16, 表示匹配前16个bit的IP段

- super: 在这种scheme情况下，对应的id拥有超级权限，可以做任何事情(cdrwa）

**Permission :**
```
CREATE(c): 创建权限，可以在在当前node下创建child node

DELETE(d): 删除权限，可以删除当前的node

READ(r): 读权限，可以获取当前node的数据，可以list当前node所有的child nodes

WRITE(w): 写权限，可以向当前node写数据

ADMIN(a): 管理权限，可以设置当前node的permission
```

> #### Zookeeper 特点：

- 顺序一致性：按照客户端发送请求的顺序更新数据。
- 原子性：更新要么成功，要么失败，不会出现部分更新。
- 单一性 ：无论客户端连接哪个server，都会看到同一个视图。
- 及时性：客户端会在一个确定的时间内得到最新的数据。
- 松耦合交互 ：不同进程间的交互不需要了解彼此，甚至可以不必同时存在，某进程在zookeeper中留下消息后，该进程结束后其它进程还可以读这条消息。
- 高可靠：Zookeeper支持集群模式，可以很容易的解决单点故障问题。

> #### Zookeeper运用场景:

**名空间服务:**
分布式命名服务，创建一个节点后，节点的路径就是全局唯一的，可以作为全局名称使用。

**分布式锁：**
Zookeeper能保证数据的强一致性，用户任何时候都可以相信集群中每个节点的数据都是相同的。一个用户创建一个节点作为锁，另一个用户检测该节点，如果存在，代表别的用户已经锁住，如果不存在，则可以创建一个节点，代表拥有一个锁。

**集群管理：**
每个加入集群的机器都创建一个节点，写入自己的状态。监控父节点的用户会受到通知，进行相应的处理。离开时删除节点，监控父节点的用户同样会收到通知。
