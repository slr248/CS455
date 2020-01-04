import java.awt.image.BufferedImage;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class ImageSurface
{
  JLabel view;
  BufferedImage surface;
  Random rng = new Random();
  Graphics g;
  int xRes=512, yRes=512;
  
  public ImageSurface()
  {
    surface = new BufferedImage(xRes,yRes,BufferedImage.TYPE_INT_RGB);
    view = new JLabel(new ImageIcon(surface));
    g = surface.getGraphics();
    
    g.setColor(Color.GRAY);
    g.fillRect(0,0,xRes-1,yRes-1);

    doGraphics();
    g.dispose();
  }// ImageSurface constructor
  
  private void setPixel(int x, int y, int red, int grn, int blu) {
    Color c = new Color(red,grn,blu);
    g.setColor(c);
    g.drawLine(x,y,x,y);
  }// setPixel()
  private void DrawLine(int x0, int y0, int x1, int y1, int red, int grn, int blu){
    Color c = new Color(red,grn,blu);
    g.setColor(c);
    g.drawLine(x0,y0,x1,y1);
  }
  
  // do graphics here - any method from 
  // http://docs.oracle.com/javase/7/docs/api/java/awt/Graphics.html
  // can be used
  private void doGraphics() {
      
    for(int i=0;i<500;i++) {
      int px = rng.nextInt(xRes);
      int py = rng.nextInt(yRes);
      int px2 = rng.nextInt(xRes);
      int py2 = rng.nextInt(yRes);
      int r=rng.nextInt(255);
      int g=rng.nextInt(255);
      int b=rng.nextInt(255);
      
      // we want to set, at (x,y), a color value of
      // 255,255,255, ie.white color (the three values
      // signify red, green and blue components of a 
      // color specification)
      //setPixel(px,py,r,g,b);     
      DrawLine(px,py,px2,py2,r,g,b);
    }
  }// doGraphics()
  
  
  public static void main(String[] args)
  {
    ImageSurface img = new ImageSurface();
    JFrame frame = new JFrame();
    frame.setContentPane(img.view);
    frame.pack();
    frame.setVisible(true);
  }
  
}// ImageSurface