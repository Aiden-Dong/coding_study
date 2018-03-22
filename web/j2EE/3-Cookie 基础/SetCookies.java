import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class SetCookies extends HttpServlet{

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doGet(req, resp);

		System.out.println("DoGet Message");

		for(int i = 0; i < 3; i++){
			// 临时性Cookie
			Cookie cookie = new Cookie("Session-Cookie-" + i, "Cookie-values-$"+i);
			resp.addCookie(cookie);

			// 时间限制性cookie
			cookie = new Cookie("Persistent-Cookie-" + i, "Cookie-Value-$" +i);
			cookie.setMaxAge(3600);			// 以 秒为单位
			resp.addCookie(cookie);
		}
		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();

		out.println("<html><head><title>Setting Cookies</title></head>");
		out.println("<body>");
		out.println("<h1>Setting Cookies</h1>");
		out.println("<p>Show Cookies please clicked <a href='showcookies'>here</a></p>");
		out.println("</body></html>");

	}

}
