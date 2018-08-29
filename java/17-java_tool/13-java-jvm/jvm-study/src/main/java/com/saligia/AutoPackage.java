package com.saligia;

import com.sun.tools.corba.se.idl.IncludeGen;

/***
 * <pre>
 * </pre>
 * @user : saligia
 * @date : 2018-08-07
 */
public class AutoPackage {
    public static void main(String [] args){
        Integer a = 1;  // Integer.valueOf()  // 自动装箱
        Integer b = 2;
        Integer c = 3;
        Integer d = 3;
        Integer e = 321;
        Integer f = 321;
        Long g = 3L;

        System.out.println(c == d);  // true  -- true(小于 125使用同一个存储空间)
        System.out.println(e == f);  // false  -- 大于一个字符使用不同空间
        System.out.println(c == (a+b)); // 遇到运算符进行拆箱过程 Interger.intValue 将结果进行 Interger.valueOf() 然后在进行比较  true
        System.out.println(c.equals(a+b)); // true
        System.out.println(g == (a+b)); // true
        System.out.println(g.equals(a+b)); // false -- equal 不处理数值类型转化关系
    }
}
