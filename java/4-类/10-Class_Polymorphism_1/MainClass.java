class Glyph
{
    public Glyph()
    {
        System.out.printf("Glyph before draw()\n");
        draw();
        System.out.printf("Glyph after draw()\n");
    }
    void draw()
    {
        System.out.printf("Glyph.draw()\n");
    }
}
class RoundGlyph extends Glyph
{
    private int radius = 1;
    public RoundGlyph(int r)
    {
        radius = r;
        System.out.println("RoundGlyph.RoundGlyph. radius = " + radius);
    }
    void draw()
    {
        System.out.println("RoundGlyph.RoundGlyph. radius = " + radius);
    }
}
class MainClass
{
    public static void main(String[] args)
    {
        new RoundGlyph(5);
    }
}
/*
// 程序输出结果
Glyph before draw()
RoundGlyph.RoundGlyph. radius = 0
Glyph after draw()
RoundGlyph.RoundGlyph. radius = 5
*/