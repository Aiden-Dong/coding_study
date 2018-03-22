public abstract class Event
{
    private long eventTime;         // 设置终止时间
    protected final long delayTime;      // 设置时延
    
    public Event(long delayTime)
    {
        System.out.printf("delayTime : %d\n", delayTime);
        this.delayTime = delayTime;
        start();
       // while(true);
    }
    
    public void start()
    {
        eventTime = System.currentTimeMillis() + delayTime;
    }
    public boolean ready()
    {
        return System.currentTimeMillis() >= eventTime;
    }
    public abstract void action();
}