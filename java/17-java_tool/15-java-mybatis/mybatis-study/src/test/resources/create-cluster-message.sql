-- cluster-manger table message
-- version (1.0.0)
-- -----------------------------------

/*! controller form cluster message */
/*! character utf-8 */
/*! author tao.dong */
/*! date 2018-08-22 */

/*!
**************************************************
cluster_id	            string, primary key	    集群ID
cluster_name	        string	                集群名称
cluster_address	        string	                集群地址
cluster_access_user	    string	                集群认证用户名
cluster_access_passwd	string	                集群认证密码
***************************************************
*/

CREATE TABLE cluster_manager(
    cluster_id int PRIMARY KEY AUTO_INCREMENT ,
    cluster_name VARCHAR(20) NOT NULL,
    cluster_time BIGINT NOT NULL ,
    cluster_address VARCHAR(50) NOT NULL,
    cluster_access_user VARCHAR(50) NOT NULL ,
    cluster_access_passwd VARCHAR(50) NOT NULL
)AUTO_INCREMENT=0;
