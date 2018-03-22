import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ApplicationServlet extends HttpServlet{

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		
		// TODO Auto-generated method stub
		//super.doGet(req, resp);
		
		ServletContext application = this.getServletContext();
		Integer countValue = (Integer)application.getAttribute("AccessCount");
		
		if(countValue == null){
			countValue = new Integer(0);
		}
		application.setAttribute("AccessCount", countValue.intValue()+1);
		
		resp.setContentType("text/html");
		PrintWriter out = resp.getWriter();
		out.println("<html><head><meta charset='utf-8'><title>Application</title></head><body>");
		out.println("<p> Access Count :" + countValue.intValue() + "</p>");
		out.close();
	}
}
