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

class Julia{
  int xRes,yRes;
  float cxmin,cymin,cxmax,cymax;
  int xtable[][];//=new int[yRes][xRes];
  ColorList color=new ColorList();
  public Julia(int xRes,int yRes,float cxmin,float cymin,float cxmax,float cymax){
    this.xRes=xRes;
    this.yRes=yRes;
    this.cxmin=cxmin;
    this.cymin=cymin;
    this.cxmax=cxmax;
    this.cymax=cymax;
    xtable=new int[yRes][xRes];
    ComplexNumber c=new ComplexNumber(-0.7,0.27015);
    for(int i=0;i<yRes;i++){
      for(int j=0;j<xRes;j++){
        ComplexNumber z=new ComplexNumber(cxmin + ((float)j)/((float)(xRes-1))*(cxmax-cxmin),cymin + ((float)i)/((float)(yRes-1))*(cymax-cymin));
       // ComplexNumber z=new ComplexNumber(0,0);
        int maxIter=200;
        int iter=0;
        while(iter < maxIter && z.abs() < 2){
          z=c.add(z.squared());
          iter++;
        }
        if(z.abs()>2){
          xtable[i][j]=iter;
        }
        else{
          xtable[i][j]=0;
        }
      }
    }
  }
  public static void setPixel(Graphics g,int i,int j,int red,int grn,int blu){
    Color c=new Color(red,grn,blu);
    g.setColor(c);
    g.drawLine(i,j,i,j);
  }
  void displayFractal(Graphics g){
    for(int i=0;i<yRes;i++){
      for(int j=0;j<xRes;j++){
        Color c=color.colList.get(xtable[i][j]);
        setPixel(g,j,i,c.getRed(),c.getGreen(),c.getBlue());
      }
    }
  }
  void saveFractal(String Filename) throws IOException{
    File f=new File(Filename.toString());
    FileOutputStream fout=new FileOutputStream(f);
    PrintStream out=new PrintStream(fout);
    out.println("P3\r\n" + xRes + " " + yRes + "\r\n255\r\n");
    for(int i=0;i<yRes;i++){
      for(int j=0;j<xRes;j++){
        Color c=color.colList.get(xtable[i][j]);
        out.println(c.getRed() + " " + c.getGreen() + " " + c.getBlue());
       // setPixel(g,i,j,c.getRed(),c.getGreen(),c.getBlue());
      }
    }
    out.close();
}
  public static  void main(String[] args) throws IOException{
    int xRes=Integer.parseInt(args[0]);
    int yRes=Integer.parseInt(args[1]);
    JFrame frame=new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    JPanel p=new JPanel();
    p.setPreferredSize(new Dimension(xRes,yRes));
    frame.add(p);
    BufferedImage pb1 = new BufferedImage(xRes,yRes,BufferedImage.TYPE_INT_RGB);
    JLabel pi1 = new JLabel(new ImageIcon(pb1));
    pi1.setPreferredSize(new Dimension(xRes,yRes));
    pi1.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
    p.add(pi1);
    Graphics g1 = pb1.createGraphics();
    Julia j=new Julia(xRes,yRes,(float)-1.5,(float)-1,(float)1.5,(float)1);
    j.displayFractal(g1);
    j.saveFractal("C:\\Users\\sanil\\Desktop\\CS455Java\\fractal\\julia.ppm");
    frame.pack();
    frame.setVisible(true);
    
  }
}
    