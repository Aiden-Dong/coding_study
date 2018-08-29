package com.saligia.common;

import com.typesafe.config.Config;
import org.apache.commons.dbcp.BasicDataSource;
import org.apache.ibatis.mapping.Environment;
import org.apache.ibatis.session.Configuration;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.apache.ibatis.transaction.TransactionFactory;
import org.apache.ibatis.transaction.jdbc.JdbcTransactionFactory;

import javax.sql.DataSource;

/***
 * <pre>
 *     数据库查询工具
 * </pre>
 * @user : saligia
 * @date : 2018-08-23
 */
public class QueryManager {

    private static final String DATASOURCE_DRIVER = "driver";
    private static final String DATASOURCE_URL = "url";
    private static final String DATASOURCE_USER = "userName";
    private static final String DATASOURCE_PASSWD = "passWord";


    private static final String DEVELOPMENT = "development";

    private DataSource dataSource = null;
    private SqlSessionFactory sqlSessionFactory = null;

    private static QueryManager queryManager = null;

    private QueryManager(){
        throw new IllegalArgumentException("invalid data config error");
    }


    private QueryManager(Config dataConfig) {
        initDataSource(dataConfig);
        initSQLSessionFaction();
    }


    /**
     * <pre>
     *   初始化数据库连接池
     * </pre>
     *
     * @param dataConfig 数据库配置信息
     */
    private void initDataSource(Config dataConfig){

        BasicDataSource dataSource = new BasicDataSource();

        if (!dataConfig.hasPath(DATASOURCE_DRIVER)){
            throw new IllegalArgumentException("Init datasource error : driver invalid");
        }
        dataSource.setDriverClassName(dataConfig.getString(DATASOURCE_DRIVER));

        if(!dataConfig.hasPath(DATASOURCE_URL)){
            throw new IllegalArgumentException("Init datasource error : url invalid");
        }
        dataSource.setUrl(dataConfig.getString(DATASOURCE_URL));

        if(!dataConfig.hasPath(DATASOURCE_USER)){
            throw new IllegalArgumentException("Init datasource error : user invalid");
        }
        dataSource.setUsername(dataConfig.getString(DATASOURCE_USER));

        this.dataSource = dataSource;
    }

    /**
     * <pre>
     *     初始化 SQLSession
     * </pre>
     *
     * @param
     */
    private void initSQLSessionFaction(){
        TransactionFactory transactionFactory = new JdbcTransactionFactory();
        Environment environment = new Environment(DEVELOPMENT, transactionFactory, dataSource);
        Configuration configuration = new Configuration(environment);
        configuration.setMapUnderscoreToCamelCase(true);

        configuration.addMappers("com.saligia.dao");
        this.sqlSessionFactory = new SqlSessionFactoryBuilder().build(configuration);
    }

    /**
     * <pre>
     *     构建 QueryManager 过程
     * </pre>
     *
     * @param dataSource 数据库连接池配置信息
     */
    public static QueryManager createQueryManager(Config dataSource){
        if(queryManager == null){
            queryManager = new QueryManager(dataSource);
        }
        return  queryManager;
    }

    /**
     * <pre>
     *     获取 sql 执行session
     *     -----------------------
     *     使用结束后必须 close
     * </pre>
     *
     * @param
     */
    public SqlSession getSession(){
        return sqlSessionFactory.openSession(true);
    }


    public DataSource getDataSource(){
        return this.dataSource;
    }

}