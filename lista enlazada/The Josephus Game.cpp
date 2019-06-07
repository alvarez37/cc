#include <iostream>
using namespace std;


template <class T2>
class nodo{
  public:
    static int contador;
    T2 valor;
    nodo * next;
    ~nodo(){
      // std::cout << " adios  " << valor << '\n';
      contador--;
    }

    nodo (T2 v_valor, nodo * n_next=NULL){
      contador++;
      valor=v_valor;
      next= n_next;
      // std::cout << " hola  " << valor << '\n';
    }
};


template <class T2>
int nodo<T2>::contador=0;


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

        void show();
        void remover(T dato);
        void adicionar(T soldados,T posicion);


};


template <class T>
bool lista_enlazada<T>::find(T valor,nodo <T> * &ptr){
    ptr=NULL;
    int i=0;
      for ( nodo<T> *p=head; p and p->valor<=valor and i<head->contador ; ptr=p , p=p->next,i++) {
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
    for ( nodo<T> *p=head;  i<head->contador ; ptr=p , p=p->next,i++) {
        // std::cout <<  p->valor <<'\t';
      }
}

template <class T>
void lista_enlazada<T>::add(T dato){
  nodo<T> *pos;
  nodo<T> *temp;

  if (!find(dato,pos)) {
    if (!pos) {
      head= new nodo<T>(dato,head);
      }
    else{
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
  for (nodo <T> *p=head ; p && i<head->contador; p=p->next, i++) {
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
    while (head->contador>2) {
      remover(posicion);

      }
      std::cout << "final" << '\n';
      show();
  }




template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *temp;
  nodo<T> *pos;
  nodo<T> *pos2;

      int i=1;

      for ( ;  i<dato ; iterador=iterador->next,i++){
        if (una_vez) {
          i++;
          iterador=head;
          una_vez=false;
        }
      }

       pos2=iterador->next;
       dato=iterador->next->valor;
       iterador=iterador->next;
       // std::cout << "eliminar " << dato << '\n';

       if (find(dato,pos)) {
         find(dato,pos);
         if(pos!=0){
           pos->next=pos->next->next;
           delete pos2;
         }
         else{
           head=head->next;
           delete head;
         }
         if (head->contador>0) {
           apuntar_al_final(temp);
           temp->next=head;
         }
       }
}

int main(){

    lista_enlazada <int> p1;

        p1.adicionar(300,5);

    return 0;
}
