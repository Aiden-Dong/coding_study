import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class ServletInterface extends HttpServlet{

	// 接受客户端的get 方法
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doGet(req, resp);
		
		PrintWriter pw = resp.getWriter();
		System.out.println("用户的 get 方法登录");
		System.out.println("name" + " : " + req.getParameter("name"));
		System.out.println("passwd" + " : " + req.getParameter("passwd"));
		System.out.println("message" + " : " + req.getParameter("message"));
	}
	
	
	// 接受客户端的 post 方法
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doPost(req, resp);
		PrintWriter pw = resp.getWriter();
		System.out.println("用户的Post方法登录");
		System.out.println("name" + " : " + req.getParameter("name"));
		System.out.println("passwd" + " : " + req.getParameter("passwd"));
		System.out.println("message" + " : " + req.getParameter("message"));
	}
}
