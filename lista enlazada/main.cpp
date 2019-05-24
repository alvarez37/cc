#include <iostream>
using namespace std;

template <class T2>
class nodo{
  public:
    T2 valor;
    nodo * next;
    nodo (T2 v_valor, nodo * n_next=NULL){
      valor=v_valor;
      next= n_next;
    }


};

template <class T>
class lista_enlazada{

    public:
        int tamanio=0;
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);
        void show();

};

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
void lista_enlazada<T>::add(T dato){
  nodo<T> *pos;

  if (!find(dato,pos)) {
    if (!pos) {
      tamanio++;
      head= new nodo<T>(dato,head);
      }
    else{
      tamanio++;
      pos->next=new nodo<T>(dato,pos->next);
      }
    }
  }

template <class T>
void lista_enlazada<T>::show() {
  nodo<T> *p=head;
  for (int i=0; p and i <=  tamanio ; p=p->next) {
      std::cout << p->valor << '\n';
    }
}

int main(){

    // nodo<int> a(4);
    // nodo<int> *b=&a;
    // nodo<int> c(23,b);
    //
    // std::cout << b->valor << '\n';
    lista_enlazada <int> p1;
    p1.add(3);
    p1.add(23);
    p1.add(13);
    p1.show();

    return 0;
}
