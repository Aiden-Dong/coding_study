package xml;

import java.io.File;

/**
 * Created by saligia on 17-7-3.
 */
public abstract class ParseXmlAbstruct {

    public abstract void parseXml();

    public File  getXmlFile(){
        return new File(DOMParseXml.class.getClassLoader().getResource("template.xml").getPath());
    }
}
