import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.server.handler.ContextHandler;
import org.eclipse.jetty.server.handler.ResourceHandler;

/**
 * <pre>
 *     一个简单的 jetty 服务
 * </pre>
 *
 * @author saligia
 * @date 17-10-10
 */
public class MyServer {
    public static void main(String [] args) throws Exception {
        Server server = new Server(8080);  // 创建一个 jetty 服务

        ContextHandler contextHandler = new ContextHandler();

        ResourceHandler resourceHandler = new ResourceHandler();

        //配置ResourceHandler，设置哪个文件应该被提供给请求方
        //这个例子里，配置的是当前路径下的文件，但是实际上可以配置长任何jvm能访问到的地方
        resourceHandler.setDirectoriesListed(true);
        resourceHandler.setWelcomeFiles(new String[] { "index.html" });
        resourceHandler.setResourceBase("src/main/web");

        contextHandler.setContextPath("/test");
        contextHandler.setHandler(resourceHandler);

        server.setHandler(contextHandler);

        server.start();
        server.join();
    }
}
