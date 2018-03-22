import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Snake
{
  Node head ;//= new Node(20, 40, Dir.L);
  Node tail = null;
  int size = 0;

  public Snake(Node node)
  {
    head = node;
    tail = node;
    size = 1;
  }

  public Snake()
  {
    head = new Node(20, 40, Dir.L);
    tail = head;
    size = 1;

  }
  public void addToTail()
  {
      Node node = null;
      // 首先判断他的动向
      switch(tail.dir)
      {
        // 向左运动
        case L :
          node = new Node(tail.row, tail.col + 1, tail.dir);
        // 向上运动
        case U :
          node = new Node (tail.row +1, tail.col, tail.dir);
        // 向右运动
        case R :
          node = new Node(tail.row, tail.col - 1, tail.dir);
        // 向下运动
        case D :
          node = new Node(tail.row-1, tail.col, tail.dir);
      }
      // 重新定义节点
      tail.next = node;
      tail = node;
      size++;
  }

  public void addtoHead()
  {
    Node node = null;

    switch(head.dir)
    {
      case L :
        node = new Node(head.row, head.col - 1, head.dir);
      case U :
        node = new Node (head.row -1, head.col, head.dir);
      case R :
        node = new Node(head.row, head.col - 1, head.dir);
      case D :
        node = new Node(head.row+1, head.col, head.dir);
    }

    node.next = head;
    head = node;
    size ++;
  }
  public void draw(Graphics g)
  {
      if(size <= 0)
        return;
      for(Node n = head; n != null; n = n.next)
      {
        n.draw(g);
      }
  }
  private class Node{
    int w = Yard.BLOCK_SIZE;
    int h = Yard.BLOCK_SIZE;
    int row, col;               //  判断节点的位置
    Dir dir ;                   // 判断每一个节点的动向
    Node next = null;

    Node(int row, int col, Dir dir){
        this.row = row;
        this.col = col;
        this.dir = dir;
        //System.out.println("创建一个 Node ：" + row + " : " + col);
    }

    void draw(Graphics g)
    {
       Color c = g.getColor();
       g.setColor(Color.BLACK);
       g.fillRect(Yard.BLOCK_SIZE*row, Yard.BLOCK_SIZE*col, w, h);
       g.setColor(c);
    }
  }
}
