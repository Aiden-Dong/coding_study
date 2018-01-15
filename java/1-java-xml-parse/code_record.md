## java 解析 xml 文件

转载自 ：

```
http://www.cnblogs.com/lanxuezaipiao/archive/2013/05/17/3082949.html
```

众所周知，现在解析XML的方法越来越多，但主流的方法也就四种，即：DOM、SAX、JDOM和DOM4J

* 来源

```
DOM：在现在的Java JDK里都自带了，在xml-apis.jar包里

SAX：http://sourceforge.net/projects/sax/

JDOM：http://jdom.org/downloads/index.html

DOM4J：http://sourceforge.net/projects/dom4j/
```


## 介绍及优缺点分析

### 1. DOM（Document Object Model)

DOM是用与平台和语言无关的方式表示XML文档的官方W3C标准。DOM是以层次结构组织的节点或信息片断的集合。这个层次结构允许开发人员在树中寻找特定信息。分析该结构通常需要加载整个文档和构造层次结构，然后才能做任何工作。由于它是基于信息层次的，因而DOM被认为是基于树或基于对象的。

* 优点 :

```
① 允许应用程序对数据和结构做出更改。
② 访问是双向的，可以在任何时候在树中上下导航，获取和操作任意部分的数据。
```

* 缺点 :

```
① 通常需要加载整个XML文档来构造层次结构，消耗资源大。
```

### 2. SAX（Simple API for XML)

SAX处理的优点非常类似于流媒体的优点。分析能够立即开始，而不是等待所有的数据被处理。而且，由于应用程序只是在读取数据时检查数据，因此不需要将数据存储在内存中。这对于大型文档来说是个巨大的优点。事实上，应用程序甚至不必解析整个文档；它可以在某个条件得到满足时停止解析。一般来说，SAX还比它的替代者DOM快许多。

选择DOM还是选择SAX？ 对于需要自己编写代码来处理XML文档的开发人员来说， 选择DOM还是SAX解析模型是一个非常重要的设计决策。 DOM采用建立树形结构的方式访问XML文档，而SAX采用的是事件模型。

DOM解析器把XML文档转化为一个包含其内容的树，并可以对树进行遍历。用DOM解析模型的优点是编程容易，开发人员只需要调用建树的指令，然后利用navigation APIs访问所需的树节点来完成任务。可以很容易的添加和修改树中的元素。然而由于使用DOM解析器的时候需要处理整个XML文档，所以对性能和内存的要求比较高，尤其是遇到很大的XML文件的时候。由于它的遍历能力，DOM解析器常用于XML文档需要频繁的改变的服务中。

SAX解析器采用了基于事件的模型，它在解析XML文档的时候可以触发一系列的事件，当发现给定的tag的时候，它可以激活一个回调方法，告诉该方法制定的标签已经找到。SAX对内存的要求通常会比较低，因为它让开发人员自己来决定所要处理的tag.特别是当开发人员只需要处理文档中所包含的部分数据时，SAX这种扩展能力得到了更好的体现。但用SAX解析器的时候编码工作会比较困难，而且很难同时访问同一个文档中的多处不同数据。

* 优势 :

```
① 不需要等待所有数据都被处理，分析就能立即开始。
② 只在读取数据时检查数据，不需要保存在内存中。
③ 可以在某个条件得到满足时停止解析，不必解析整个文档。
④ 效率和性能较高，能解析大于系统内存的文档。
```

* 缺点 :

```
① 需要应用程序自己负责TAG的处理逻辑（例如维护父/子关系等），文档越复杂程序就越复杂。
② 单向导航，无法定位文档层次，很难同时访问同一文档的不同部分数据，不支持XPath。
```

 ### 3. JDOM(Java-based Document Object Model)

 JDOM的目的是成为Java特定文档模型，它简化与XML的交互并且比使用DOM实现更快。由于是第一个Java特定模型，JDOM一直得到大力推广和促进。正在考虑通过“Java规范请求JSR-102”将它最终用作“Java标准扩展”。从2000年初就已经开始了JDOM开发。

 JDOM与DOM主要有两方面不同。首先，JDOM仅使用具体类而不使用接口。这在某些方面简化了API，但是也限制了灵活性。第二，API大量使用了Collections类，简化了那些已经熟悉这些类的Java开发者的使用。

 JDOM文档声明其目的是“使用20%（或更少）的精力解决80%（或更多）Java/XML问题”（根据学习曲线假定为20%）。JDOM对于大多数Java/XML应用程序来说当然是有用的，并且大多数开发者发现API比DOM容易理解得多。JDOM还包括对程序行为的相当广泛检查以防止用户做任何在XML中无意义的事。然而，它仍需要您充分理解XML以便做一些超出基本的工作（或者甚至理解某些情况下的错误）。这也许是比学习DOM或JDOM接口都更有意义的工作。

 JDOM自身不包含解析器。它通常使用SAX2解析器来解析和验证输入XML文档（尽管它还可以将以前构造的DOM表示作为输入）。它包含一些转换器以将JDOM表示输出成SAX2事件流、DOM模型或XML文本文档。JDOM是在Apache许可证变体下发布的开放源码。

* 优点
```
① 使用具体类而不是接口，简化了DOM的API。
② 大量使用了Java集合类，方便了Java开发人员。
```
* 缺点
```
① 没有较好的灵活性。
② 性能较差。
```

### 4. DOM4J(Document Object Model for Java)

虽然DOM4J代表了完全独立的开发结果，但最初，它是JDOM的一种智能分支。它合并了许多超出基本XML文档表示的功能，包括集成的XPath支持、XML Schema支持以及用于大文档或流化文档的基于事件的处理。它还提供了构建文档表示的选项，它通过DOM4J API和标准DOM接口具有并行访问功能。从2000下半年开始，它就一直处于开发之中。

为支持所有这些功能，DOM4J使用接口和抽象基本类方法。DOM4J大量使用了API中的Collections类，但是在许多情况下，它还提供一些替代方法以允许更好的性能或更直接的编码方法。直接好处是，虽然DOM4J付出了更复杂的API的代价，但是它提供了比JDOM大得多的灵活性。

在添加灵活性、XPath集成和对大文档处理的目标时，DOM4J的目标与JDOM是一样的：针对Java开发者的易用性和直观操作。它还致力于成为比JDOM更完整的解决方案，实现在本质上处理所有Java/XML问题的目标。在完成该目标时，它比JDOM更少强调防止不正确的应用程序行为。

DOM4J是一个非常非常优秀的Java XML API，具有性能优异、功能强大和极端易用使用的特点，同时它也是一个开放源代码的软件。如今你可以看到越来越多的Java软件都在使用DOM4J来读写XML，特别值得一提的是连Sun的JAXM也在用DOM4J.

* 优点 :
```
① 大量使用了Java集合类，方便Java开发人员，同时提供一些提高性能的替代方法。
② 支持XPath。
③ 有很好的性能。
```

* 缺点 :
```
① 大量使用了接口，API较为复杂。
```


## 比较

1. DOM4J性能最好，连Sun的JAXM也在用DOM4J。目前许多开源项目中大量采用DOM4J，例如大名鼎鼎的Hibernate也用DOM4J来读取XML配置文件。如果不考虑可移植性，那就采用DOM4J.

2. JDOM和DOM在性能测试时表现不佳，在测试10M文档时内存溢出，但可移植。在小文档情况下还值得考虑使用DOM和JDOM.虽然JDOM的开发者已经说明他们期望在正式发行版前专注性能问题，但是从性能观点来看，它确实没有值得推荐之处。另外，DOM仍是一个非常好的选择。DOM实现广泛应用于多种编程语言。它还是许多其它与XML相关的标准的基础，因为它正式获得W3C推荐（与基于非标准的Java模型相对），所以在某些类型的项目中可能也需要它（如在JavaScript中使用DOM）。

3. SAX表现较好，这要依赖于它特定的解析方式－事件驱动。一个SAX检测即将到来的XML流，但并没有载入到内存（当然当XML流被读入时，会有部分文档暂时隐藏在内存中）。

我的看法：如果XML文档较大且不考虑移植性问题建议采用DOM4J；如果XML文档较小则建议采用JDOM；如果需要及时处理而不需要保存数据则考虑SAX。但无论如何，还是那句话：适合自己的才是最好的，如果时间允许，建议大家讲这四种方法都尝试一遍然后选择一种适合自己的即可。


## 实例 :

* 样例　xml

```
<?xml version="1.0"?>

<!--
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License. See accompanying LICENSE file.
-->
<configuration>

    <!-- Site specific YARN configuration properties -->
    <property id="1">
        <name>yarn.resourcemanager.address</name>
        <value>localhost:8032</value>
    </property>

    <property id="2">
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
    <property id="3">
        <name>yarn.nodemanager.resource.memeory-mb</name>
        <value>1024</value>
    </property>
</configuration>
```

* DOM

```
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
```

* JDOM

```
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
```

* SAX

```
package xml;

import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by saligia on 17-7-3.
 */
public class SAXParseXml extends ParseXmlAbstruct{

    @Override
    public void parseXml(){

        SAXParserFactory saxParserFactory = SAXParserFactory.newInstance();

        SAXParser saxParser = null;
        InputStream fin = null;

        try{
            saxParser = saxParserFactory.newSAXParser();
            fin = new FileInputStream(getXmlFile());
            saxParser.parse(fin, new SaxXmlHandel());
        } catch (SAXException e) {
            throw new IllegalArgumentException("SaxParse get instance error");
        } catch (ParserConfigurationException e) {
            throw new IllegalArgumentException("Parse Configuration error");
        }catch (IOException e){
            throw new IllegalArgumentException("template xml file error");
        }
    }
}


package xml;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

/**
 * Created by saligia on 17-7-3.
 */
public class SaxXmlHandel extends DefaultHandler {

    private Attributes attributes;
    private Boolean hasAttribute;
    private Boolean nameFlag = false;
    private Boolean valueFlag = false;
    private String qName ;

    @Override
    public void startDocument() throws SAXException {
        System.out.println("-------start Document--------");
    }

    @Override
    public void endDocument() throws SAXException {
        System.out.println("-------end Document---------");
    }

    /*
     *  读取到一个元素开始时候触发。
      */
    @Override
    public void startElement(String uri, String localName, String qName,
                             Attributes attributes) throws SAXException {

        this.qName = qName;
        System.out.println("start element : " + qName);

        if (attributes.getLength() > 0) {
            this.attributes = attributes;
            this.hasAttribute = true;
        }
    }

    /*
    *  当一个元素结束时候触发
     */
    public void endElement(String uri, String localName, String qName)
            throws SAXException {

        System.out.println("> end element : " + qName);
        this.qName = "";
    }

    /*
    *  获取文本信息 ： 当 startElement 跟 endElement 结束后触发
     */
    public void characters(char[] ch, int start, int length)
            throws SAXException {
        if(qName.equals("name")){
            System.out.println(new String(ch, start, length));
        }
    }

}
```

* DOM4J

```
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
```
