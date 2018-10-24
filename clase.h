#include<iostream>
using namespace std;


class punto{
public:

  punto(int ,int);
  punto();
  punto(punto &o);
  void print();
  void offset(int,int);

private:
  double x,y;

};
