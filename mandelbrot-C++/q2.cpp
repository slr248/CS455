#include <iostream>
#include <string.h>
#include <fstream>
#include "q2.h"
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
	ofstream pgmFile(filename.c_str());
	pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; 
    pgmFile << 255 << endl; 
    
	for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
            pgmFile << xtable[i][j] << " ";
        }// next column
        pgmFile << endl;
    }// next row
    pgmFile.close();
};			






int main(){
	PGMimage *a = new PGMimage(1000,500,"test.pgm");
    int xRes, yRes;
    a->getResolution(xRes,yRes);

 //NOTE the j,i ordering below (twice), since we specify coords as (x,y) [not (y,x)]
   for(int i=0;i < yRes;i++){
      for(int j=0;j < xRes;j++){
            a->setPixel(i,j,128); // constant value of 100 at all locations
        }
   }
  /* for(int i=0;i < yRes;i++){
      for(int j=0;j < xRes;j++){
            cout << a->getpixel(j,i) << " "; 
        }
    cout << endl;
    }*/
a->writefile();
delete a;
}
