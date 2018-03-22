import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


public class SessionInfo extends HttpServlet{

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doGet(req, resp);

		// 获取 Session
		HttpSession mySession = req.getSession(true);
		// true ---- 如果没有session则创建一个session
		// false -- 如果没有则不创建

		Integer count = (Integer)mySession.getAttribute("AccessCount");
		if(count == null){
			count = new Integer(0);
		}
		mySession.setAttribute("AccessCount", count+1);

		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();
		out.println("<html><head><title>SessionInfo</title></head><body>");
		out.println("<h3>Session Infomation</h3>");
		out.println("New Session : " + mySession.isNew() + "<br/>");								// 判断session是否是刚创建
		out.println("Session ID : " + mySession.getId() + "<br/>");									// 获取session ID
		out.println("Access Count : " + count + "<br/>");														// 访问次数
		out.println("Session Create Time "+  new Date(mySession.getCreationTime()) + "<br/>");		// 获取 Session 的创建时间
		out.println("Session Last Accessed Time : " + new Date(mySession.getLastAccessedTime()) + "<br/>");	// 获取 最后访问 Session 的时间


		out.println("<h3>  Request Information </h3>");
		out.println("Session ID from Request : " + req.getRequestedSessionId()+"<br/>");			// 从请求报文中获得 session id
		out.println("Session ID via Cookie :" + req.isRequestedSessionIdFromCookie()+"<br/>");		// 返回 是否是从 cookie 中获得
		out.println("Session ID via Rewirite URL : " + req.isRequestedSessionIdFromURL() + "<br/>");// 返回是否从URL中获得的
		out.println("Valid Session Id : " + req.isRequestedSessionIdValid() + "<br/>");	//

		out.println("<a href = '" + resp.encodeURL("SessionInfo") +"' > reflush </a>");		// 如果 cookies 被禁用， 则使用 添加 url 的方式
		out.println("</body></html>");
		out.close();
	}
}
