import java.io.IOException;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class ServletCycle extends HttpServlet{

	@Override
	public void destroy() {
		// TODO 自动生成的方法存根
		//super.destroy();
		System.out.println("Destroy");
	}

	public ServletCycle(){
		System.out.println("Constructor");
	}
	
	@Override
	public void init(ServletConfig config) throws ServletException {
		// TODO 自动生成的方法存根
		//super.init(config);
		System.out.println("Init");
	}

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		// TODO 自动生成的方法存根
		//super.doGet(req, resp);
		System.out.println("Do Get");
	}
	
}
