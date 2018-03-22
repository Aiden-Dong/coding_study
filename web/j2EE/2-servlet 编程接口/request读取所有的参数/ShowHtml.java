import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ShowHtml extends HttpServlet{
//	Enumeration 
//	boolean hasMoreElements()	 测试此枚举是否包含更多的元素。 
//	E nextElement() ; 			如果此枚举对象至少还有一个可提供的元素，则返回此枚举的下一个元素。 

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {	
		
		Enumeration<String> gather = req.getParameterNames();
		PrintWriter out = resp.getWriter();
		resp.setContentType("text/html");
		out.println("<!DOCTYPE html>");
		out.println("<html>");
		out.println("<head>");
		out.println("<meta charset='utf-8'/>");
		out.println("<title>Message</title>");
		out.println("</head>");
		out.println("<body>");
		out.println("<table border='1px'>");
		out.println("<thead stylesheet='background-color=green'>");
		out.println("<td>Property</td><td>value</td>");
		out.println("</thead>");
		
		while(gather.hasMoreElements()){
			String param = gather.nextElement();
			//System.out.println(param.toString() + " : " + req.getParameter(param.toString()));
			// 获取同一个名字下的多个值
			
			String []formValues = req.getParameterValues(param);
			for(String itemValue : formValues){
				out.println("<tr>");
				out.println("<td>" + param + "</td>" + "<td>" + itemValue + "</td>");
//				System.out.println(param + " : " + itemValue);
				out.println("</tr>");
			}
		}
		
		// Map getParameterMap() || 获取键值对属性
		
		out.println("</table>");
		out.println("</body>");
		out.println("</html>");
		
		// TODO 自动生成的方法存根
		//super.doPost(req, resp);
	}

}
