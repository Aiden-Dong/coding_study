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
