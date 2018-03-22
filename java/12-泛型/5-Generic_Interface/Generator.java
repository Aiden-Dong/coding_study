/*
*     工厂方法设计模式： 生成器（泛型接口）
*/

public interface Generator<T>
{
    T next();
}
