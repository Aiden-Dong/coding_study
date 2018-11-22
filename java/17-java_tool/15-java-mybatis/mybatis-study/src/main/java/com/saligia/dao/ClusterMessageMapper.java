package com.saligia.dao;

import com.saligia.domain.ClusterMessage;
import org.apache.ibatis.annotations.*;
import org.apache.ibatis.type.JdbcType;

import java.util.List;
import java.util.Map;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-08-29
 */
public interface ClusterMessageMapper {

    // Insert
    @Insert("insert into cluster_manager(cluster_name, cluster_time, cluster_address, cluster_access_user, cluster_access_passwd) " +
            "values(#{clusterName}, #{clusterTime}, #{clusterAddress}, #{clusterAccessUser}, #{clusterAccessPasswd})")
    @Options(useGeneratedKeys = true, keyColumn = "cluster_id", keyProperty = "clusterId") // 自增
    public void insertClusterMessage(ClusterMessage clusterMessage);

    // select
    @Select("select * from cluster_manager")
    @Results(

            id = "clusterMessage",
            value = {
                    @Result(column = "cluster_name", property = "clusterName", javaType = String.class, jdbcType = JdbcType.VARCHAR),
                    @Result(column = "cluster_time", property = "clusterTime", javaType = Long.class, jdbcType = JdbcType.BIGINT),
                    @Result(column = "cluster_address", property = "clusterAddress", javaType = String.class, jdbcType = JdbcType.VARCHAR),
                    @Result(column = "cluster_access_user", property = "clusterAccessUser", javaType = String.class, jdbcType = JdbcType.VARCHAR),
                    @Result(column = "cluster_access_passwd", property = "clusterAccessPasswd", javaType = String.class, jdbcType = JdbcType.VARCHAR)
            }
    ) // 显式映射
    public List<ClusterMessage> getClusterMessage();

    // cluster_id
    // cluster_name
    @Select("select * from cluster_manager")
    @MapKey("clusterId")
    public Map<Integer, ClusterMessage> getClusterMessageMapper();


    @Select("select * from cluster_manager where cluster_id=#{clusterId}")
//    @ResultMap("clusterMessage")
    public ClusterMessage getClusterMessageById(@Param("clusterId") int clusterId);


    // update
    @Update("update cluster_manager set cluster_name=#{clusterName} where cluster_id=#{clusterId}")
    public void updateClusterMessage(ClusterMessage clusterMessage);

    // delete
    @Delete("delete from cluster_manager where cluster_id=#{clusterId}") // (delete ... ? ) , (clusterId)
    public void deleteClusterMessage(@Param("clusterId")int clusterId);
}
