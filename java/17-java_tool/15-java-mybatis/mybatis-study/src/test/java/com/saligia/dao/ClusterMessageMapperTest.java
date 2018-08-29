package com.saligia.dao;

import com.saligia.common.Propers;
import com.saligia.common.QueryManager;
import com.saligia.domain.ClusterMessage;
import com.typesafe.config.Config;
import org.apache.ibatis.session.SqlSession;
import org.junit.*;

import java.sql.SQLException;
import java.util.Date;
import java.util.List;
import java.util.Map;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-08-29
 */
public class ClusterMessageMapperTest {

    private static Config config = Propers.getPropers().getDataSource();
    private static QueryManager queryManager = QueryManager.createQueryManager(config);

    @BeforeClass
    public static void createDB() throws SQLException {
        SqlSession sqlSession = queryManager.getSession();
        String createClusterMessage =
                "CREATE TABLE cluster_manager(\n" +
                "    cluster_id int PRIMARY KEY AUTO_INCREMENT ,\n" +
                "    cluster_name VARCHAR(20) NOT NULL,\n" +
                "    cluster_time BIGINT NOT NULL ,\n" +
                "    cluster_address VARCHAR(50) NOT NULL,\n" +
                "    cluster_access_user VARCHAR(50) NOT NULL ,\n" +
                "    cluster_access_passwd VARCHAR(50) NOT NULL\n" +
                ")AUTO_INCREMENT=0";

        try{
            sqlSession.getMapper(UserAutoDefineMapper.class).action(createClusterMessage);
        }catch (Exception e){
            throw new SQLException("create cluster_manager error : " + e);
        }finally {
            sqlSession.close();
        }
    }

    @Before
    public void insertClusterMessage() throws SQLException {
        SqlSession sqlSession = queryManager.getSession();
        ClusterMessage clusterMessage = new ClusterMessage();

        clusterMessage.setClusterName("test");
        clusterMessage.setClusterTime(new Date().getTime());
        clusterMessage.setClusterAddress("localhost");
        clusterMessage.setClusterAccessUser("user");
        clusterMessage.setClusterAccessPasswd("test");

        try{
            sqlSession.getMapper(ClusterMessageMapper.class).insertClusterMessage(clusterMessage);
            System.out.println(clusterMessage);
        }catch (Exception e){
            throw new SQLException("insert cluster_manager error : " + e);
        }finally {
            sqlSession.close();
        }
    }

    @Test
    public void getClusterMessage() throws SQLException {
        SqlSession sqlSession = queryManager.getSession();

        System.out.println(">>>>> get cluster message");

        try{
            List<ClusterMessage> clusterMessages = sqlSession.getMapper(ClusterMessageMapper.class).getClusterMessage();
            for(ClusterMessage clusterMessage : clusterMessages){
                System.out.println(clusterMessage);
            }

            Map<Integer, ClusterMessage> cluster = sqlSession.getMapper(ClusterMessageMapper.class).getClusterMessageMapper();

            System.out.println(cluster.get(2));
        }catch (Exception e){
            throw new SQLException("get cluster_manager error : " + e);
        }finally {
            sqlSession.close();
        }
    }

    @Test
    public void updateClusterMessage() throws SQLException {
        SqlSession session = queryManager.getSession();

        System.out.println(">>>>>> update cluster message");

        ClusterMessage clusterMessage = new ClusterMessage();

        clusterMessage.setClusterId(1);
        clusterMessage.setClusterName("useName");
        clusterMessage.setClusterTime(new Date().getTime());
        clusterMessage.setClusterAddress("localhost");
        clusterMessage.setClusterAccessUser("user");
        clusterMessage.setClusterAccessPasswd("test");

        try{
            session.getMapper(ClusterMessageMapper.class).updateClusterMessage(clusterMessage);
            ClusterMessage cluster = session.getMapper(ClusterMessageMapper.class).getClusterMessageById(1);
            System.out.println(cluster);
        }catch (Exception e){
            throw new SQLException("delete cluster_manager error : " + e);
        }finally {
            session.close();
        }
    }

    @After
    public void deleteClusterMessage() throws SQLException {
        SqlSession sqlSession = queryManager.getSession();

        try{
            sqlSession.getMapper(ClusterMessageMapper.class).deleteClusterMessage(1);
        }catch (Exception e){
            throw new SQLException("delete cluster_manager error : " + e);
        }finally {
            sqlSession.close();
        }
    }



    @AfterClass
    public static void clearDB() throws SQLException {
        SqlSession sqlSession = queryManager.getSession();
        String clearClusterMessage = "DROP TABLE cluster_manager";

        try{
            sqlSession.getMapper(UserAutoDefineMapper.class).action(clearClusterMessage);
        }catch (Exception e){
            throw new SQLException("clear cluster_manager error : " + e);
        }finally {
            sqlSession.close();
        }
    }
}
