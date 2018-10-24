#include "clase.h"

punto::punto(int a,int b){
  x=a;
  y=b;

}

punto::punto(){
  x=0;
  y=0;

}

void  punto::print(){
  std::cout << "x " << x<< '\n';
  std::cout << "y " << y<< '\n';
}

void punto::offset(int a,int b){
  x+=a;
  y+=b;
}

punto::punto(punto &o){
  y=o.y;
  x=o.x;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
