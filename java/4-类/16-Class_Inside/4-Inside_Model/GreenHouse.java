// 控制对象与可控制事件 ------------- 内部类模型
public class GreenHouse extends Controller
{
    private boolean light = false;
    public class Light extends Event
    {
        public Light(long delayTime)
        {
            super(delayTime);
        }
        public void action()
        {
            
            light = (light == true ? false : true);
        }
        public String toString()
        {
            return "Light is " + (light == true ? "Open" : "Down");
        }
    }
    
    private boolean weater = false;
    public class Water extends Event
    {
        public Water(long delayTime)
        {
            super(delayTime);
        }
        public void action()
        {
            weater = (weater == true ? false : true);
        }
        public String toString()
        {
            return "weater is " + (weater == true ? "Open" : "Down");
        }
    }
    
    private String nowstat = "Day";
    public class NowStat extends Event
    {
        public NowStat(long delayTime)
        {
            super(delayTime);
        }
        public void action()
        {
            nowstat = (nowstat == "Day" ? "Night" : "Day");
        }
        public String toString()
        {
            return "NowStat is " + nowstat;
        }
    }
    
    public class Bell extends Event
    {
        public Bell(long delayTime)
        {
            super(delayTime);
        }
        public void action()
        {
            
        }
        public String toString()
        {
            return "Bing !!";
        }
    }
    
    public static class Terminate extends Event
    {
        public Terminate (long delayTime)
        {
            super(delayTime);
        }
        public void action()
        {
            System.exit(0);
        }
        public String toString()
        {
            return "Terminating";
        }
    }
}