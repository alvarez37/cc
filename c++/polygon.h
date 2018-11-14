#include <iostream>
using namespace std;

template <class myT  >
class Polygon {

protected:
  myT width, height;

public:

  Polygon (myT a, myT b)  {
    width=a, height=b;
  }
  Polygon ();
  myT area (){};
  void print(){
    std::cout << "(" << width << ","<< height << ")"<<'\n';
  }
  void printarea(){
    cout << area() <<endl;
    }
  };

//********************************************

  // class triangle : public Polygon {
  //
  // public:
  //   triangle(int,int,int);
  //   int area();
  //   void printarea();
  //   void get_width();
  //   void get_height();
  //
  // private:
  //   int x;
  //
  // };
  //
  // class rectangle : public Polygon {
  //
  // public:
  //   rectangle(int,int);
  //   int area();
  //   void printarea();
  //   void get_width();
  //   void get_height();
  //
  //
  // private:
  //   int width1, height1;
  //
  // };

//+++++++++++++++++++++++++++++


class PolygonArray{
    public:
        PolygonArray();
        PolygonArray(const Polygon pts[], const int size);

    private:
        int size;
        Polygon<myT2> *Polygons<int>;
	      void resize(int);
};
