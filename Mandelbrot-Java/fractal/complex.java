import java.lang.Math;

class complex{
  public double real,img;
  complex(double real,double img){
    this.real=real;
    this.img=img;
  }
  public static complex squared(complex c){
    double r=Math.pow(c.real,2)-Math.pow(c.img,2);
    double i=2*c.real*c.img;
    return complex a(r,i);
}
}
    