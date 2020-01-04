import java.awt.Color;
import java.awt.Graphics;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.IOException;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.image.BufferedImage;
import java.awt.Dimension;
import javax.swing.BorderFactory;
import java.awt.Color;

class X{
  public static void main(String args[]){
    JFrame frame=new JFrame();
    JPanel p=new JPanel();
    p.setPreferredSize(new Dimension(500,500));
    BufferedImage surface=new BufferedImage(500,500,BufferedImage.TYPE_INT_RGB);
    JLabel view=new JLabel(new ImageIcon(surface));
    Graphics g=surface.createGraphics();
    g.setColor(Color.RED);
    g.fillRect(30,30,,469);
    g.drawOval(100,100,3,3);
    p.add(view);
    frame.add(p);
    frame.pack();
    frame.setVisible(true);
  }
}
    
  