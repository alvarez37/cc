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
        int contador=0;

        void show();
        void remover(T dato);

};


template <class T>
bool lista_enlazada<T>::find(T valor,nodo <T> * &ptr){
    ptr=NULL;
    int i=0;
    for ( nodo<T> *p=head; p and p->valor<=valor and i<contador ; ptr=p , p=p->next,i++) {
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
      contador++;
      head= new nodo<T>(dato,head);
      head->next=head;
      std::cout << "veces  " << '\n';
      }
    else{
      contador++;
      pos->next=new nodo<T>(dato,pos->next);
      }
    }
  }

template <class T>
void lista_enlazada<T>::show() {

  std::cout  << '\n';
  // for (nodo <T> *p=head; p ; p=p->next) {
  int i=0;
  for (nodo <T> *p=head ; p && i<contador ; p=p->next, i++) {

      std::cout << i<< "     [ id: " << p<< " valor: " << p->valor << " apunta  " << p->next<<  " ]"<<" "<< endl;
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
          contador--;
          pos->next=pos->next->next;
          delete pos->next;
        }

        else{

          contador--;
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

        p1.show();
        p1.add(100);
        p1.show();
        p1.add(1000);
        p1.add(1);
        p1.show();
        p1.add(10);
        p1.show();

        // p1.remover(10);
        // p1.add(101);
        p1.add(1001);
        p1.show();


        std::cout << p1.contador << '\n';

        p1.show();

    return 0;
}
