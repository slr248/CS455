#include<iostream>
#include "q3ec1.h"
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
	PGMimage *p=new PGMimage(750,500,"mandelbrot2.pgm");
	int xRes,yRes;
	float cxmin=-0.75,cymin=0.1;
	float cxmax=cxmin+0.001,cymax=cymin+0.001;
	int maxIter;
	int iter;
	p->getResolution(xRes,yRes);
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
