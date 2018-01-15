package xml;

import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;

import java.io.IOException;
import java.util.List;

/**
 * Created by saligia on 17-7-3.
 */
public class JDOMParseXml extends ParseXmlAbstruct {

    @Override
    public void parseXml() {

        // 创建解析实例
        SAXBuilder builder = new SAXBuilder();
        Document document = null;

        try {
            document = builder.build(getXmlFile());
        } catch (JDOMException e) {
            throw new IllegalArgumentException("JDOM parse failth : " + e);
        } catch (IOException e) {
            throw new IllegalArgumentException("File open to reader error : " + e);
        }

        Element rootElement = document.getRootElement();  // 获取根节点信息

        System.out.println("root message : " + rootElement.getName());

        List<Element> elements = (List<Element>) rootElement.getChildren("property");

        for(Element element : elements){
            if(element.getChild("name").getText().equals("yarn.resourcemanager.address")){
                System.out.println("id = " + element.getAttribute("id").getValue());
                System.out.println("name = " + element.getChild("name").getText());
                System.out.println("value = " + element.getChild("value").getText());
            }
        }
        System.out.println(elements.size());

    }
}
