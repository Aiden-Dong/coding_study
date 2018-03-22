package io;

import org.junit.Test;

/**
 * Created by saligia on 17-8-15.
 */
public class TypeEnumTest {

    @Test
    public void testEnum(){
        TypeEnum type = TypeEnum.valueOf("READ");
        System.out.println(type);
    }
}
