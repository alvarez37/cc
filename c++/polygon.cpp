 #include "polygon.h"

 template <class myT  >
 polygon<myT=int>Polygon (){
   width=0, height=0;

 }


//
// triangle::triangle(int a, int b, int ab) : Polygon( a, b){
//   x=ab;
// }
//
// int triangle::area(){
//   return (width*height)/2;
// }
//
// void triangle::printarea(){
//   Polygon::printarea();
// }
//
//
// void triangle::get_width(){
//   std::cout << "triangle width " <<width << '\n';
// }
// void triangle::get_height(){
//   std::cout<< "triangle height "  << height << '\n';
// }
//
//
//   rectangle::rectangle(int a,int b):Polygon(a,b){
//     width1=a, height1=b;
//
//   }
//
//   void rectangle::get_width(){
//     std::cout << "rectangle width " << width<< '\n';
//   }
//   void rectangle::get_height(){
//     std::cout << "rectangle height " << height << '\n';
//   }
//
//   int rectangle::area(){
//     return (width*height);
//   }
//
//   void rectangle::printarea(){
//     Polygon::printarea();
//   }



  PolygonArray::PolygonArray()
  {
      this->size = 0;
      this->Polygons = new Polygon[size];
  }

  PolygonArray::PolygonArray(const Polygon pts[], const int size) {
      this->size = size;
      this->Polygons = new Polygon[size];
      for(int i = 0; i < size; i++)
          Polygons[i] = pts[i];
  }

  // PolygonArray::PolygonArray(PolygonArray &o){
  //     this->size = o.size;
  //     this->Polygons = new Polygon[size];
  //     for(int i = 0; i < size; i++)
  //         Polygons[i] = o.Polygons[i];
  // }
  //
  // void PolygonArray::resize(int newSize) {
  // 	Polygon *pts = new Polygon[newSize];
  // 	int minsize = (newSize > size) ? size : newSize;
  //     for(int i = 0; i < minsize; i++)
  //         pts[i] = Polygons[i];
  // 	delete[] Polygons;
  // 	size = newSize;
  // 	Polygons = pts;
  // }
  //
  // void PolygonArray::print() {
  // 	for(int i = 0; i < size; i++)
  // 		Polygons[i].print();
  // }
  //
  // void PolygonArray::push_back(const Polygon &p){
  // 	resize(size+1);
  // 	Polygons[size-1] = p;
  // }
  //
  // void PolygonArray::insert(const int pos, const Polygon &p) {
  // 	resize(size+1);
  //     for(int i = size-1; i < pos; i--)
  //         Polygons[i] = Polygons[i-1];
  // 	Polygons[pos] = p;
  // }
  //
  // void PolygonArray::clear() {
  // 	resize(0);
  // }
  //
  // int PolygonArray::getSize(){
  //     return size;
  // }
  //
  // PolygonArray::~PolygonArray()
  // {
  //     delete[] Polygons;
  // }
