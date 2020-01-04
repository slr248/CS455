class ComplexNumber{
  double real,imag;
  public ComplexNumber(double real,double imag){
    this.real=real;
    this.imag=imag;
  }
  public ComplexNumber(){real=0;imag=0;}
  ComplexNumber add(ComplexNumber c){
    double temp1,temp2;
    temp1=real+c.real;
    temp2=imag+c.imag;
    ComplexNumber x=new ComplexNumber(temp1,temp2);
    return x;
  }
  ComplexNumber squared(){
    ComplexNumber x=new ComplexNumber();
    x.real=Math.pow(real,2)-Math.pow(imag,2);
    x.imag=2*real*imag;
    return x;
  }
  double abs(){
    return Math.sqrt(Math.pow(real,2)+Math.pow(imag,2));
  }
  public static void main(String[] args){
    ComplexNumber c=new ComplexNumber(4,3);
    ComplexNumber a=c.squared();
    System.out.println(c.abs()+" "+a.imag);
  }
}   
    