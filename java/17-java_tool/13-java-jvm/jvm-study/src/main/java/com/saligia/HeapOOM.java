package com.saligia;

import java.util.LinkedList;
import java.util.List;

/***
 * <pre>
 *     -Xms20m -Xmx20m -XX:+HeapDumpOnOutOfMemoryError
 *
 *     java -Xmx20m -Xms20m -XX:+HeapDumpOnOutOfMemoryError -cp jvm-study-1.0.jar com.saligia.HeapOOM
 *     java.lang.OutOfMemoryError: GC overhead limit exceeded
 *     Dumping heap to java_pid1530.hprof ...
 *     Heap dump file created [36732326 bytes in 0.165 secs]
 *     Exception in thread "main" java.lang.OutOfMemoryError: GC overhead limit exceeded
 * 	    at java.util.LinkedList.linkLast(LinkedList.java:142)
 * 	    at java.util.LinkedList.add(LinkedList.java:338)
 * 	    at com.saligia.HeapOOM.main(HeapOOM.java:23)
 * </pre>
 * @user : saligia
 * @date : 2018-05-09
 */
public class HeapOOM {
    static class OOMObject{

    }

    public static void main(String[]  args){

        List<OOMObject> list = new LinkedList<OOMObject>();

        while(true){
            list.add(new OOMObject());
        }

    }
}
