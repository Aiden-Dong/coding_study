import org.eclipse.jetty.server.Handler;
import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.server.handler.ContextHandler;
import org.eclipse.jetty.server.handler.ContextHandlerCollection;
import org.eclipse.jetty.server.handler.ResourceHandler;
import org.eclipse.jetty.servlet.ServletContextHandler;
import org.eclipse.jetty.servlet.ServletHandler;
import servlet.TestServlet;

import java.io.File;

/**
 * <pre>
 * </pre>
 *
 * @author saligia
 * @date 17-10-12
 */
public class MyServletHandle {
    public static void main(String[] args) throws Exception {
        Server server = new Server(8080);

        ContextHandler  contextHandler = new ContextHandler();

        ResourceHandler resourceHandler = new ResourceHandler();

        //配置ResourceHandler，设置哪个文件应该被提供给请求方
        //这个例子里，配置的是当前路径下的文件，但是实际上可以配置长任何jvm能访问到的地方
        resourceHandler.setDirectoriesListed(true);
        resourceHandler.setWelcomeFiles(new String[] { "index.html" });
        resourceHandler.setResourceBase("src/main/web");

        contextHandler.setContextPath("/");
        contextHandler.setHandler(resourceHandler);

        ServletContextHandler servletHandler = new ServletContextHandler(ServletContextHandler.SESSIONS);
        servletHandler.setContextPath("/test/");

        //ServletHandler servlets =  new ServletHandler();

        servletHandler.addServlet(TestServlet.class, "/testServlet");

        ContextHandlerCollection collection = new ContextHandlerCollection();

        collection.setHandlers(new Handler[]{contextHandler, servletHandler});

        server.setHandler(collection);

        server.start();
        server.join();
    }
}
