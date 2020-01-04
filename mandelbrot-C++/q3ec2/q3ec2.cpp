#include<iostream>
#include "q3ec2.h"
#include<math.h>

using namespace std;

void array2D::getSize(int &xresolution,int &yresolution){
	xresolution=xRes;
	yresolution=yRes;
}
void array2D::setValue(int i,int j,float val){
	xtable[i][j]=val;
}
float array2D::getValue(int i,int j){
	return xtable[i][j];
}


void PGMimage::getResolution(int &x,int &y){         
	    	x=xRes;
	    	y=yRes;
		}

void PGMimage::setPixel(int i,int j,float val){
			xtable[i][j]=val;
		}
float PGMimage::getpixel(int i,int j){
	return xtable[i][j];
};	
void PGMimage::writefile(){
	string s=filename;
	ofstream pgmFile(s.c_str());
	pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
    pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)

	for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
            pgmFile << xtable[i][j] << " ";
        }// next column
        pgmFile << endl;
    }// next row
    pgmFile.close();
};			
ComplexNumber ComplexNumber :: add(ComplexNumber c){
	double j,k;
	c.getVals(j,k);
	ComplexNumber a(j+real,k+imag);
	return a;
}
ComplexNumber ComplexNumber :: squared(){
	double temp=real;
	ComplexNumber c(pow(real,2)-pow(imag,2),2*temp*imag);
	return c;
}
double ComplexNumber::abs(){
	double abs;
	abs=sqrt(pow(real,2)+pow(imag,2));
	return abs;
}
void ComplexNumber::prt(){
	if(imag<0){
	    cout<<real<<imag<<"j"<<endl;
    }
    else{
    	cout<<real<<"+"<<imag<<"j"<<endl;
	}
}


int main(){
	PGMimage *p=new PGMimage(750,500,"mandelbrot.pgm");
	int xRes,yRes;
	float cxmin=-2,cymin=-1;
	float cxmax=1,cymax=1;
	string s[24]={"1.pgm","2.pgm","3.pgm","4.pgm","5.pgm","6.pgm","7.pgm","8.pgm","9.pgm","10.pgm","11.pgm","12.pgm","13.pgm","14.pgm","15.pgm","16.pgm","17.pgm","18.pgm","19.pgm","20.pgm","21.pgm","22.pgm","23.pgm","24.pgm"};
	int maxIter;
	int iter;
	p->getResolution(xRes,yRes);
	for(int k=0;k<24;k++){
		PGMimage *p=new PGMimage(xRes,yRes,s[k]);
		cxmin+=0.02;
		cymin+=0.02;
		cxmax-=0.02;
		cymax-=0.02;
    	for(int i=0;i<yRes;i++){
		    for(int j=0;j<xRes;j++){
				ComplexNumber c(cxmin + (double)j/(xRes-1)*(cxmax-cxmin),cymin + (double)i/(yRes-1)*(cymax-cymin));
				ComplexNumber z(0,0);
				maxIter=255;
				iter=0;
				while(iter<maxIter && z.abs()<2){
					z=c.add(z.squared());
					iter++;
				}
				if(z.abs()>=2){
					p->setPixel(i,j,iter);
				}
				else{
					p->setPixel(i,j,0);
				}
			}
		}
		p->writefile();
	}
}

