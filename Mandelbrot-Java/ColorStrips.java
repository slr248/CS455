import java.awt.Color;
import java.awt.GridLayout;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.util.Random;

public class ColorStrips {


  public static void main(String[] args) {

    ColorList cols = new ColorList(); 

    JFrame frame = new JFrame(); 
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    frame.setLayout(new GridLayout(256,1)); 
    Random rng=new Random();

    JPanel p;
    Color c;
    for(int i=0;i<256;i++){
      p=new JPanel();
      c=cols.colList.get(rng.nextInt(255));
      p.setBackground(c);
      p.setPreferredSize(new Dimension(100,4));
      frame.add(p);
    }
  /*  JPanel p;
    Color c;
 
    p = new JPanel();
    c = cols.colList.get(4); 
    p.setBackground(c); 
    p.setPreferredSize(new Dimension(100,4)); 
    frame.add(p); 
    p = new JPanel(); 

    c = cols.colList.get(66); 
    p.setBackground(c);
    p.setPreferredSize(new Dimension(100,4)); 
    frame.add(p); */

   
    frame.pack(); 
    frame.setVisible(true); 
  }
}