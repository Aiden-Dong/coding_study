package study;

import org.apache.zookeeper.*;

import java.io.IOException;
import java.util.List;
import java.util.concurrent.CountDownLatch;

/**
 * Created by saligia on 17-7-13.
 */
public class ZkWatcher implements Watcher {

    private static final int SESSION_TIMEOUT = 5000;
    private ZooKeeper zk = null;
    private CountDownLatch countDownLatch  = new CountDownLatch(1);

    // 连接　zookeeper 服务器
    public void connect(String hostName) throws IOException, InterruptedException {
        zk = new ZooKeeper(hostName, SESSION_TIMEOUT, this);
        /*
        *  连接　zookeeper 服务器 :
        *     host            : zookeeper 服务器地址 (可以添加端口如：localhost:2181)
        *     SESSION_TIMEOUT : 链接的时间超时
        *     Watcher 对象　　　: 用来接受来自　zookeeper 的回调，以获取各种事件的通知．
         */
        countDownLatch.await();
        // 使用　CountDownLatch 是防止　zk 客户端在连接到服务器之前就返回．
    }

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
