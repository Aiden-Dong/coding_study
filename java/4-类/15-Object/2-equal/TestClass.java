class BaseClass
{
    public int i;
    public BaseClass(int i)
    {
        this.i =i;
    }
    // 重写 equals 
    public boolean equals(Object ob)
    {
        BaseClass one = (BaseClass)ob;
        if(this.i == one.i)
            return true;
        return false;
    }
}

class MainClass
{
    public static void main(String args[])
    {
        BaseClass one = new BaseClass(2);
        BaseClass two = new BaseClass(2);
        BaseClass three = two;
        
        System.out.println(one);
        System.out.println(two);
//        BaseClass@7f6ee240
//        BaseClass@514ae5cd
        
        // 法一：
        if(one == two)  // 直接比较两个对象是否相等
            System.out.printf("两个类相等\n");
        else
            System.out.printf("两个类不相等\n");
        // 法二：
        if(one.equals(two)) // 比较两个对象是否相等
            System.out.printf("两个类相等\n");
        else
            System.out.printf("两个类不想等\n");
        
        if(three.equals(two)) // 比较两个对象是否相等
            System.out.printf("两个类相等\n");
        else
            System.out.printf("两个类不想等\n");
        
        String str1 = "Hello";
        String str2 = "Hello";
        
        if(str1.equals(str2))               // equals 重写， 代表的是指向的内容
            System.out.printf("两个变量相等\n");
        
        if(str1 == str2)
            System.out.println("str1 == str2"); // 两值相等 ， 因为 str1 与 str2 指向的内容在常量区， 只有一份拷贝
        else
            System.out.println("str1 != str2");
        
        String str3 = new String("Hello");
        String str4 = new String("Hello");
        if(str3 == str4)                        // 两个不相等， == 表示指向的本身
            System.out.println("str3 == str4"); 
        else
            System.out.println("str3 != str4");

    }
}