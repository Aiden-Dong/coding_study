<%@page language="java" import="bean.*" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>JSP Bean</title>
  </head>
  <body>

    <%!
      CounterBean one = new CounterBean();
    %>
    <jsp:useBean id="cb" class="bean.CounterBean">
    </jsp:useBean>
    <h2>
    <!--调用的是 setCount方法-->
    <jsp:setProperty name="cb" property="count" value="23"/>
    <!--调用的是 getCount 方法-->
    <jsp:getProperty name="cb" property="count" />

    <br/>
    <%=
      one.getCount()
    %>

    </h2>
  </body>
</html>
