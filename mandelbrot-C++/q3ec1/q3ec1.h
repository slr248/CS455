#ifndef Q3EC1_H // include guard
#define Q3EC1_H
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class array2D{
	protected:
		int xRes,yRes;
		float **xtable;
	public:
		array2D(int x,int y){
			cout<<"initializing array2D first"<<endl;
			xRes=x;
			yRes=y;
			xtable=new float*[yRes];
			for(int i=0;i<yRes;i++){
				xtable[i]=new float[xRes];
			}
			for(int i=0;i<yRes;i++){
				for(int j=0;j<xRes;j++){
					xtable[i][j]=45;
		        }
			}
		}
		~array2D(){
			for(int i=0;i<yRes;i++){
				delete []xtable[i];
			}
			delete []xtable;
		}
    void getSize(int &xresolution,int &yresolution);	
	void setValue(int i,int j,float val);	
	float getValue(int i,int j);
		
};
class PGMimage: public array2D{  //class pgm gets all of array2D's members and methods
	private:
		string filename;
	public:
	    PGMimage(int x,int y,string s) : array2D(x,y){
	    	cout<<"now initializing pgm image"<<endl;
	    	filename=s;
		}	
	    void getResolution(int &x,int &y);  
//	    int* getResolution();              
		void setPixel(int i,int j,float val);
		float getpixel(int i,int j);
		void writefile();
};

class ComplexNumber{
	private:
		double real,imag;
	public:
		ComplexNumber(double i,double j){
			real=i;
			imag=j;
		}
		ComplexNumber add(ComplexNumber c);
		ComplexNumber squared();
        void getVals(double &a,double &b){
        	a=real;
        	b=imag;
		}
		double abs();
		void prt();
};
		
#endif 
