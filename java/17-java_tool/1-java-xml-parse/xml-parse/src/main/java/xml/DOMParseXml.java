package xml;

import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

/**
 * Created by saligia on 17-6-15.
 *
 * 使用 DOM 的方式解析 xml 说明 :
 *  1. 工具自带在 JDK 中， 无需要重新导入工具包
 */
public class DOMParseXml extends ParseXmlAbstruct{

    /*
     *   创建解析器过程， 首先创建工厂实例， 通过工厂实例来创建一个xml解析器实例。
     *   通过xml 解析器实例解析 xml 文件来构建 DOM.
     *
     *   常用的解析方式是 :
     *    从根节点获取它的所有的子节点，然后遍历子节点。
     *    节点类型(getNodeType)根据具体对象如 : 元素， 注释， 文本， 属性等种类较多。
     *    我们较多关注的为 :
     *               元素  :
     *                     当节点类型为元素时，我们可以通过 getNodeType == Node.ELEMENT_NODE  判断。
     *                     元素类型的节点可能具有属性在里面: 我们可以通过 getAttributes 来获取
     *                     元素节点还可能具有子节点 : 我们可以通过 getChildNodes 来获取。
     *               属性  :
     *                      当节点为属性时， 我们可以通过 getNodeName 获取属性名， 通过 getNodeValue 过去属性值。
     *                      getNodeType == Node.ATTRIBUTE_NODE
     *               文本  :
     *                      当节点为文本时， 我们可以通过 getNodeType == Node.TEXT_NODE
     *                      可以通过getNodeValue 获取 文本内容。
    */

    @Override
    public void parseXml()  {

        DocumentBuilderFactory builderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = null;

        File templateFile = getXmlFile();

        try{
             documentBuilder = builderFactory.newDocumentBuilder();
        }catch (ParserConfigurationException e) {
            throw new IllegalArgumentException("DocumentBuilder create error : " + e);
        }

        Document document = null;

        try{
            document = documentBuilder.parse(templateFile);
        } catch (SAXException e) {
            throw new IllegalArgumentException("Document parse error and invalid xml file : "  + e);
        } catch (IOException e) {
            throw new IllegalArgumentException("Document Parse error and read xml file : " + e);
        }

        NodeList nodeList = document.getChildNodes();   // 获取所有的 node 节点

        int flags = 0;

        // 遍历所有的 node 节点
        for(int i = 0; i < nodeList.getLength(); i++){
            Node node = nodeList.item(i);
            if(node.getNodeType() != Node.ELEMENT_NODE){
                continue;
            }

            NodeList list = node.getChildNodes();

            for(int x = 0; x <list.getLength(); x++){
                Node children = list.item(x);

                if(children.getNodeType() !=  Node.ELEMENT_NODE){
                    continue;
                }

                System.out.println(children.getNodeName());

                /*
                *  获取属性
                 */

                NamedNodeMap map = children.getAttributes();

                Node id = map.getNamedItem("id");


                if(id != null){
                    System.out.println(id.getNodeName() + " = " + id.getNodeValue());
                }

                NodeList propertys = children.getChildNodes();

                for(int y = 0; y < propertys.getLength(); y++){
                    Node property = propertys.item(y);

                    if(property.getNodeType() != Node.ELEMENT_NODE){
                        continue;
                    }

                    if(property.getNodeName().equals("name")){
                        Node text = property.getFirstChild();
                        if(text.getNodeValue().equals("yarn.resourcemanager.address")){
                            flags = 1;
                        }
                    }else if(property.getNodeName().equals("value") && flags == 1){
                        Node text = property.getFirstChild();
                        System.out.println(text.getNodeValue());
                        flags = 0;
                    }
                }

            }
        }
    }
}
