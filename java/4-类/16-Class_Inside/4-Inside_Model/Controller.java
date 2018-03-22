import java.util.*;

// 事件控制
public class Controller
{
    private List<Event> eventlist = new ArrayList<Event>();
    
    public void addEvent(Event c)
    {
        eventlist.add(c);
    }
    public void run()
    {
        while(eventlist.size() > 0)
        {
            for(Event e: new ArrayList<Event>(eventlist))
            {
                if(e.ready())
                {
                    System.out.println(e);
                    e.action();
                    e.start();  // 重启
                }
            }
        }
    }
}