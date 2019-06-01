#include <iostream>
using namespace std;

template <class T2>
class nodo{
  public:
    static int contador;
    T2 valor;
    nodo * next;
    ~nodo(){
      std::cout << " adios  " << valor << '\n';

      contador--;
    }
    nodo (T2 v_valor, nodo * n_next=NULL){

      contador++;
      valor=v_valor;
      next= n_next;
      std::cout << " hola  " << valor << '\n';
    }


};

template <class T2>
int nodo<T2>::contador=0;

template <class T>
class lista_enlazada{

    public:
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);
        bool buscar (T dato);

        void show();
        void remover(T dato);
        ~lista_enlazada(){

          while ( head ) {
              remover(head->valor);
            }
        }


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





int main(){

        lista_enlazada <int>  *p1 = new lista_enlazada<int> ;

        p1->add(3);
        p1->add(1);
        p1->add(5);
        p1->show();
        p1->add(2);
        p1->add(4);
        p1->show();
        // p1->remover(3);
        // p1->remover(1);
        // p1->remover(5);
        p1->show();
        // p1->remover(2);
         p1->remover(4);
        p1->show();
        delete   p1;
        p1->add(2);
        p1->add(4);

        std::cout << "..........." << '\n';

        p1->show();

    return 0;
}
