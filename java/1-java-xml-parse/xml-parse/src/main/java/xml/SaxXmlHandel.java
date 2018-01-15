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
