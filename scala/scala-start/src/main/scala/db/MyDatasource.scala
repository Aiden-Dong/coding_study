package db

import javax.sql.DataSource

import org.apache.commons.dbcp.BasicDataSource


object MyDatasource {
  def getDataSource(url:String):DataSource = {
    val dataSource:BasicDataSource = new BasicDataSource()

    dataSource.setDriverClassName("com.mysql.jdbc.Driver")
    dataSource.setUsername("saligia")
    dataSource.setPassword("360628836989")
    dataSource.setUrl(url)

    dataSource
  }
}
