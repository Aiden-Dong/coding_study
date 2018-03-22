<%@page language="java" import="bean.*" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>人员评估</title>
    <link rel="stylesheet" href="css/property.css" charset="utf-8">
  </head>
  <body id="body_id">
    <%!
      String name = "name";
      String age = "age";
      String high = "high";
      String weight = "bweight";
    %>
    <jsp:useBean id="one" class="bean.PropertyBean" />
    <jsp:setProperty name="one" property="name" param="name" />
    <jsp:setProperty name="one" property="age" param="age" />
    <jsp:setProperty name="one" property="high" param="high"/>
    <jsp:setProperty name="one" property="bweight" param="weight"/>
    
    <div id="div_id">
      <div id="table_div">
        <table id="table_id">
          <tr>
            <td>姓名</td>
            <td>年龄</td>
            <td>身高</td>
            <td>体重</td>
            <td>综合</td>
          </tr>
          <tr>
            <td><jsp:getProperty name="one" property="name"/></td>
            <td><jsp:getProperty name="one" property="age"/></td>
            <td><jsp:getProperty name="one" property="high"/></td>
            <td><jsp:getProperty name="one" property="bweight"/></td>
            <td><jsp:getProperty name="one" property="sum"/></td>
          </tr>
          </table>
      </div>
    </div>

  </body>
</html>
