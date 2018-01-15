package study;

import org.apache.zookeeper.CreateMode;
import org.apache.zookeeper.KeeperException;
import org.junit.Test;

import java.io.IOException;

/**
 * Created by saligia on 17-7-13.
 */
public class ZkWathcherTest {

    @Test
    public void testCreateSqenNode() throws IOException, InterruptedException, KeeperException {
        ZkWatcher zk = new ZkWatcher();
        zk.connect("localhost:2181");

        zk.list("/test");

        Thread.sleep(1);

        String node = zk.create("/test/uniq-" , CreateMode.EPHEMERAL_SEQUENTIAL);

        System.out.println(node);

        Thread.sleep(5000);

        zk.close();
    }
}
