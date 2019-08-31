#include <iostream>
using namespace std;

template <class T2>
class nodo{
  public:
    int contador;
    T2 valor;
    nodo * next;
    ~nodo(){
      // std::cout << " adios  " << valor << '\n';
    }

    nodo (T2 v_valor, nodo * n_next=NULL){
      valor=v_valor;
      next= n_next;
  //  std::cout << " hola  " << valor << '\n';

    }
};


template <class T>
class lista_enlazada{

    public:

        void get_tam();
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);
        bool buscar (T dato);

        void show();
        void remover(T dato);
        ~lista_enlazada(){
          while ( head ) {  remover(head->valor);  }
        }
};

template <class T>
void  lista_enlazada<T>::get_tam() {
  int i=0;
  for (nodo <T> *p=head; p ; p=p->next, i++);
  head->contador=i;
}


template <class T>
bool lista_enlazada<T>::find(T valor,nodo <T> * &ptr){
    ptr=NULL;
    for (nodo<T> *p=head; p and p->valor<=valor ; ptr=p , p=p->next) {
      if (p->valor==valor) {

        return true;
         }
       }

      return false;
}

template <class T>
bool lista_enlazada<T>::buscar(T valor){
  for (nodo<T> *p=head; p and p->valor<=valor ; p=p->next) {
    if (p->valor==valor) {
      return true;
       }
     }
    return false;

}


template <class T>
void lista_enlazada<T>::add(T dato){
  nodo<T> *pos;

  if (!find(dato,pos)) {
    if (!pos) {
      head= new nodo<T>(dato,head);
      }
    else{
      pos->next=new nodo<T>(dato,pos->next);
      }
    }
    get_tam();
  }

template <class T>
void lista_enlazada<T>::show() {

  std::cout  << '\n';
  for (nodo <T> *p=head; p ; p=p->next) {
      std::cout <<  "     [ id: " << p<< " valor: " << p->valor << " apunta  " << p->next<<  " ]"<<" "<< endl;
    }
  std::cout  << '\n';
}

template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *pos;
  nodo<T> *pos2;

      if (find(dato,pos)) {
        if(pos!=0){
          pos2= pos->next ;
          pos->next=pos->next->next;
          delete pos2;
        }

        else{
          pos2= head ;

          head=head->next;
          delete pos2;
        }
      }
      else{
        std::cout << "ese elemento no existe " << '\n';
      }
}

template <class T>
void  merge( nodo  <T> * a, nodo <T> * b){

  int menor = (b->contador < a->contador ) ? b->contador : a->contador;
  int mayor = (b->contador > a->contador ) ? b->contador : a->contador;

  std::cout << menor  << '\n';
  nodo<T> *temp3 = a;

  for (size_t i = 0; i < menor-1; i++ ) {

    if (a->valor < b->valor   ) {

      std::cout << "a: " << a->valor <<  " b: " << b->valor <<'\n';
      nodo<T> *temp = a->next;
      // std::cout << temp <<" "<< a->next << '\n';
      a->next = b;
      b=b->next;
      a=a->next;

      a->next=temp;
      a=a->next;

      std::cout << " a " << a->valor  << '\n';
      std::cout << " b " << b->valor  << '\n';

    }

    // else{
    //   nodo<T> *temp = a->next;
    //   std::cout << b->valor << '\n';
    // }
  // }

  }

  nodo<T> *temp4 = a->next;
  a->next = b;
  if (menor != mayor )  {
    a->next->next = temp4;
  }
  a=temp3;


}
int main(){


  lista_enlazada <int> p1;
  lista_enlazada <int> p2;

  p1.add(1);
  p1.add(3);
  p1.add(5);
  p1.add(7);
  p1.add(9);
  p1.add(11);
  p1.add(13);
  p1.add(15);
  p1.add(17);
  p1.add(19);
  p1.add(21);
  p1.add(23);


  p2.add(2);
  p2.add(4);
  p2.add(6);
  p2.add(8);
  p2.add(10);
  p2.add(12);

  p2.show();
  std::cout << ".........." << '\n';
  p1.show();
  merge(  p1.head , p2.head );
  p1.show();


    return 0;
  }
