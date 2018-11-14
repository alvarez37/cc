#include <iostream>
using namespace std;
#include "polygon.h"

int main (){

  // rectangle r1(2,4);
  // triangle t1(23,4,52);
  //
  // rectangle *ptrr1=&r1;
  // triangle *ptrt1=&t1;
  //
  // ptrr1->area();
  // ptrr1->get_width();
  // ptrr1->get_height();
  //
  // ptrt1->area();
  // ptrt1->get_width();
  // ptrt1->get_height();

  // class templates

    Polygon <int> p(1, 3);
    Polygon <int> q(3, 3);
    Polygon <int> r(3, 1);

    Polygon <int > arr[] = {p, q , r};
    int size = sizeof(arr)/sizeof(arr[0]);

     PolygonArray pa2(arr, size);

    // PolygonArray pa = pa2;

    // cout << pa.getSize() << endl;
    // pa.push_back(p);
    // pa.print();
    // pa.insert(1, q);
    // pa.print();
    // pa.clear();
    // cout << pa.getSize() << endl;
   return 0;

}
