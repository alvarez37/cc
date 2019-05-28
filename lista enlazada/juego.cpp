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
        nodo<T> *iterador;

        bool find(T valor,nodo <T> * &ptr);
        void apuntar_al_final(nodo <T> * &ptr);

        void add (T dato);
        bool buscar (T dato);
        bool una_vez=true;
        int contador=0;

        void show();
        void remover(T dato);
        void adicionar(T soldados,T posicion);


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
void lista_enlazada<T>::apuntar_al_final(nodo <T> * &ptr){
    ptr=NULL;
    int i=0;
    for ( nodo<T> *p=head;  i<contador ; ptr=p , p=p->next,i++) {
        // std::cout <<  p->valor <<'\t';
      }
}

template <class T>
void lista_enlazada<T>::add(T dato){
  nodo<T> *pos;
  nodo<T> *temp;

  if (!find(dato,pos)) {
    if (!pos) {
      contador++;
      head= new nodo<T>(dato,head);
      }
    else{
      contador++;
      pos->next=new nodo<T>(dato,pos->next);

      }
    }
    apuntar_al_final(temp);
    temp->next=head;
  }

template <class T>
void lista_enlazada<T>::show() {

  std::cout  << '\n';
  int i=0;
  for (nodo <T> *p=head ; p && i<contador; p=p->next, i++) {
      std::cout << i<< "     [ id: " << p<< " valor: " << p->valor << " apunta  " << p->next<<  " ]"<<" "<< endl;
      // std::cout <<  p->valor <<'\t';
    }
  std::cout  << '\n';
  std::cout  << '\n';


}

template <class T>
void lista_enlazada<T>::adicionar(T soldados,T posicion) {
    for (int i = 1; i < soldados+1; i++) {
      add(i);
    }
    std::cout << "lista enlazada" << '\n';
    show();
    while (contador>2) {
      remover(posicion);
      show();
      }
      std::cout << "final" << '\n';
      show();
  }




template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *temp;
  nodo<T> *pos;

      int i=1;
      contador--;


      for ( ;  i<dato ; iterador=iterador->next,i++){
        if (una_vez) {
          i++;
          iterador=head;
          una_vez=false;
        }
      }
       dato=iterador->next->valor;
       iterador=iterador->next;
       std::cout << "eliminar " << dato << '\n';

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
         if (contador>0) {
           apuntar_al_final(temp);
           temp->next=head;
         }
       }

}

int main(){

    lista_enlazada <int> p1;

        p1.adicionar(40,3);

    return 0;
}
