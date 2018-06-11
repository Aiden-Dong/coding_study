package com.saligia;

/***
 * <pre>
 *     java -Xss128k
 *
 *     java -Xss256k -cp jvm-study-1.0.jar com.saligia.JavaVMStackSOF
 *     stack length : 2293
 *      Exception in thread "main" java.lang.StackOverflowError
 * 	      at com.saligia.JavaVMStackSOF.stackLeak(JavaVMStackSOF.java:14)
 * 	      at com.saligia.JavaVMStackSOF.stackLeak(JavaVMStackSOF.java:14)
 * 	      at com.saligia.JavaVMStackSOF.stackLeak(JavaVMStackSOF.java:14)
 * 	      at com.saligia.JavaVMStackSOF.stackLeak(JavaVMStackSOF.java:14)
 * 	      at com.saligia.JavaVMStackSOF.stackLeak(JavaVMStackSOF.java:14)
 * </pre>
 * @user : saligia
 * @date : 2018-05-09
 */
public class JavaVMStackSOF {
    private int stackLength = 1;

    public void stackLeak(){
        stackLength ++;
        stackLeak();
    }

    public static void main(String [] args) throws Throwable {
        JavaVMStackSOF oom  = new JavaVMStackSOF();

        try{
            oom.stackLeak();
        }catch (Throwable e){
            System.out.println("stack length : " + oom.stackLength);
            throw e;
        }
    }
}
