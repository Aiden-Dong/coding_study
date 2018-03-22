package xml;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import java.util.List;

/**
 * Created by saligia on 17-7-3.
 */
public class DOM4JParseXml extends ParseXmlAbstruct {

    @Override
    public void parseXml() {
        SAXReader saxReader = new SAXReader();
        Document document = null;

        try{
            document = saxReader.read(getXmlFile());
        } catch (DocumentException e) {
            throw new IllegalArgumentException("parse xml file failth : " + e);
        }

        Element element = document.getRootElement();

        List<Element> propertys = element.elements("property");

        for(Element property : propertys){
            if(property.element("name").getText().equals("yarn.resourcemanager.address")){
                System.out.println("id = " + property.attributeValue("id"));
                System.out.println("name = " + property.element("name").getText());
                System.out.println("value = " + property.element("value").getText());

                /*
                 *    添加新元素
                  */
                property.addElement("description");
                property.element("description").addText("yarn address message");
                property.element("description").addAttribute("user","test");
            }
        }

        System.out.println(document.asXML());
    }
}
