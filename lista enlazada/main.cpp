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
        nodo<T> head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);

};

template <class T>
bool lista_enlazada<T>::find(T valor,nodo <T> * &ptr){
    ptr=NULL;
    for (nodo<T> *p=head; p and p->valor<=valor , ptr=p; p=p->next) {
      if (p->valor==valor) {
        return true;
      }
      return false;
    }
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
  }


int main()
{
    lista_enlazada<int> p1();
    p1.add(<int> 5);

    return 0;
}
