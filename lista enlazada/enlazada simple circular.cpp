#include <iostream>
using namespace std;

template <class T2>
class nodo{
  public:
    static int contador;
    T2 valor;
    nodo * next;
    ~nodo(){
      contador--;
    }
    nodo (T2 v_valor, nodo * n_next=NULL){
      contador++;
      valor=v_valor;
      next= n_next;
    }
};

template <class T2>
int nodo<T2>::contador=0;


template <class T>
class lista_enlazada{

    public:
        ~lista_enlazada(){
         std::cout << "elimidano por jean"<<endl;
        }
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void apuntar_al_final(nodo <T> * &ptr);

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
  for (nodo <T> *p=head ; p && i<contador ; p=p->next, i++) {
      std::cout << i<< "     [ id: " << p<< " valor: " << p->valor << " apunta  " << p->next<<  " ]"<<" "<< endl;
      // std::cout <<  p->valor <<'\t';
    }
    std::cout << "cantidad de elementos: " << head->contador<< '\n';

  std::cout  << '\n';
  std::cout  << '\n';


}

template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *pos;
  nodo<T> *temp;

      if (find(dato,pos)) {
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
        if (contador>0) {
          apuntar_al_final(temp);
          temp->next=head;
        }
      }
      else{
        std::cout << "ese elemento no existe " << '\n';
      }

}

int main(){

    lista_enlazada <int> p1;

        p1.show();
        p1.add(1);
        p1.show();
        p1.add(9);
        p1.add(5);
        p1.show();
        p1.add(3);
        p1.add(8);


        p1.show();
        p1.remover(5);
        p1.remover(1);
        p1.remover(9);
        p1.show();


    return 0;
}
