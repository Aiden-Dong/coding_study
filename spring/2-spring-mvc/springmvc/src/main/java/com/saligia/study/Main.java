package com.saligia.study;

import org.eclipse.jetty.annotations.AnnotationConfiguration;
import org.eclipse.jetty.plus.webapp.EnvConfiguration;
import org.eclipse.jetty.plus.webapp.PlusConfiguration;
import org.eclipse.jetty.server.Connector;
import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.server.ServerConnector;
import org.eclipse.jetty.server.handler.DefaultHandler;
import org.eclipse.jetty.server.handler.HandlerList;
import org.eclipse.jetty.servlet.DefaultServlet;
import org.eclipse.jetty.servlet.ServletHolder;
import org.eclipse.jetty.webapp.*;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-12-28
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Server server = new Server();

        // 链接管理
        ServerConnector serverConnector = new ServerConnector(server);
        serverConnector.setPort(8080);
        serverConnector.setReuseAddress(true);
        server.setConnectors(new Connector[]{serverConnector});

        WebAppContext context = new WebAppContext();

        String webDir = Main.class.getClassLoader().getResource("webapp/resource").toExternalForm();

        context.setResourceBase(webDir);
        context.setServer(server);
        context.setContextPath("/");

        context.setConfigurations(new Configuration[] {
                new AnnotationConfiguration(),
                new WebInfConfiguration(),
                new EnvConfiguration(),
                new WebXmlConfiguration(),
                new MetaInfConfiguration(),
                new PlusConfiguration(),
                new FragmentConfiguration(),
        });
        context.setAttribute("org.eclipse.jetty.server.webapp.ContainerIncludeJarPattern", ".*\\.jar");

        ServletHolder staticServlet = new ServletHolder(new DefaultServlet());
        context.addServlet(staticServlet, "/css/*");

        server.setHandler(context);

        server.start();
        server.dumpStdErr();
        server.join();
    }
}
