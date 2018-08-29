package com.saligia.domain;

/***
 * <pre>
 *     集群管理信息
 * </pre>
 * @user : saligia
 * @date : 2018-08-27
 */
public class ClusterMessage {
    int clusterId = 0;                     // 集群ID
    String clusterName = "";               // 集群名称
    Long clusterTime = 0l;                 // 集群上线时间
    String clusterAddress = "";            // 集群内网访问地址
    String clusterAccessUser = "";         // 集群访问用户
    String clusterAccessPasswd = "";       // 集群访问密码

    public int getClusterId() {
        return clusterId;
    }
    public void setClusterId(int clusterId) {
        this.clusterId = clusterId;
    }
    public String getClusterName() {
        return clusterName;
    }
    public void setClusterName(String clusterName) {
        this.clusterName = clusterName;
    }
    public Long getClusterTime() {
        return clusterTime;
    }
    public void setClusterTime(Long clusterTime) {
        this.clusterTime = clusterTime;
    }
    public String getClusterAddress() {
        return clusterAddress;
    }
    public void setClusterAddress(String clusterAddress) {
        this.clusterAddress = clusterAddress;
    }
    public String getClusterAccessUser() {
        return clusterAccessUser;
    }
    public void setClusterAccessUser(String clusterAccessUser) {
        this.clusterAccessUser = clusterAccessUser;
    }
    public String getClusterAccessPasswd() {
        return clusterAccessPasswd;
    }
    public void setClusterAccessPasswd(String clusterAccessPasswd) {
        this.clusterAccessPasswd = clusterAccessPasswd;
    }

    @Override
    public String toString() {
        return "ClusterMessage{" +
                "clusterId='" + clusterId + '\'' +
                ", clusterName='" + clusterName + '\'' +
                ", clusterTime=" + clusterTime +
                ", clusterAddress='" + clusterAddress + '\'' +
                ", clusterAccessUser='" + clusterAccessUser + '\'' +
                ", clusterAccessPasswd='" + clusterAccessPasswd + '\'' +
                '}';
    }
}
