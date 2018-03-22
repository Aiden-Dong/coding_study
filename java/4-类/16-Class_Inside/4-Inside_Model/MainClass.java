public class MainClass
{
    public static void main(String[] args)
    {
        GreenHouse one = new GreenHouse();
        one.addEvent(one.new Bell(1000));
        one.addEvent(one.new Light(130));
        one.addEvent(one.new Water(400));
        one.addEvent(one.new NowStat(750));
        if(args.length == 1)
            one.addEvent(new GreenHouse.Terminate(new Integer(args[0])));
        one.run();
    }
}