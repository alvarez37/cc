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
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);
        bool buscar (T dato);

        void show();
        void remover(T dato);

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
  }

template <class T>
void lista_enlazada<T>::show() {

  std::cout  << '\n';
  for (nodo <T> *p=head; p ; p=p->next) {
      std::cout << "[ id: " << p<< " valor: " << p->valor << " ]"<<" ";
      // std::cout <<  p->valor <<'\t';

    }
  std::cout  << '\n';
  std::cout  << '\n';


}

template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *pos;
      if (find(dato,pos)) {
        find(dato,pos);
        if(pos!=0){
          pos->next=pos->next->next;
          delete pos->next;
        }

        else{
          head=head->next;
          delete head;
        }
      }
      else{
        std::cout << "ese elemento no existe " << '\n';
      }

}



int main(){

    lista_enlazada <int> p1;
        p1.add(1);
        p1.add(10);
        p1.add(100);
        p1.add(1000);

        p1.show();
        p1.remover(10);
        p1.show();
        std::cout << p1.buscar(1) << '\n';

        p1.show();

    return 0;
}
