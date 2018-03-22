
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletTest extends HttpServlet{

	// get 方式 ： 直接在 url地址里敲 入服务器的地址
	// post 方式 ： 在form里设置 post 方式，并且点击提交
	
	// HttpServletRequest req 是封装了客户端到服务端的一系列请求的内容
	// HttpServletResponse resp 服务器段给客户端的应答信息
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		// TODO 自动生成的方法存根
		System.out.println("doGet");
//		super.doGet(req, resp);
		resp.getWriter().write("Hello world");
	}
	
	
}
