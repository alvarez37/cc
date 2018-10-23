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


punto::~punto(punto &o){
  x=o.y;
  y=o.x;

}
