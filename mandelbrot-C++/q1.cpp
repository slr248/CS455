#include <iostream>
#include <string.h>
using namespace std;
class array2D{
	protected:
		int xRes,yRes;
		float **xtable;
	public:
		array2D(int x,int y){
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
	void setValue(int a,int b,float val);	
	float getValue(int i,int j);
};
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

int main(){
	array2D *a = new array2D(5,2);
    int xRes, yRes;
    a->getSize(xRes,yRes);

   for(int i=0;i < yRes;i++){
      for(int j=0;j < xRes;j++){
            a->setValue(i,j,100); 
        }
   }
   for(int i=0;i < yRes;i++){
      for(int j=0;j < xRes;j++){
            cout << a->getValue(i,j) << " "; 
        }
    cout << endl;
    }

delete a;
}
