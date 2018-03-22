/*
*     创建一个 注解  关键字 @interface
*     使用 元注解来说明 自定义注解的生存阶段
*     @Retention | RetionPolicy.SOURCE(源文件阶段) | RetentionPolicy.CLASS（CLASS阶段） | RetinPolicy.RUNTIME（运行阶段）
*/
import java.lang.annotation.*;

// 自定义注解 -- 1
// 元注解
@Retention(RetentionPolicy.RUNTIME)// 指明此注解保留到运行时
@Target({ElementType.TYPE}) // 指明此注解的应用范围
@interface ItCastAnnotation
{
  // 为接口实现属性
  String color() default "black";   // 设置缺省属性
}

// 自定义注解 ----- 2
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface MyAnnotation
{
  // 属性可以添加 基本类型， 类， 数组， 注解
  int it()default 3 ;
  double[] one() default {12.3, 13.4 , 11.1};
  String value(); // 特殊的属性
}
