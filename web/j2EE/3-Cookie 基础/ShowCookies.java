import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class ShowCookies extends HttpServlet{

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doGet(req, resp);

		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();
		out.println("<html><head><title>ShowCookies</title></head><body>");
		out.println("<table border='2px'>");

		// 获取 cookies
		Cookie[] cookies = req.getCookies();
		 if(cookies != null){
			 for(Cookie it : cookies){
				 out.println("<tr>");
				 out.println("<td> " + it.getName() + "</td>");
				 out.println("<td>" + it.getValue() + "</td>");
				 out.println("</tr>");
			 }
		 }

		 out.println("</table></body></html>");
	}


}
