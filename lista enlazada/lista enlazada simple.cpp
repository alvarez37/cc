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
  std::cout << "numero de elementos: " << head->contador<< '\n';
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

    lista_enlazada <int> p1;

    int x;
    int y;

    while (true) {
      std::cout << '\n';
      std::cout << "-------------------------------------------" << '\n';
      std::cout << "1 para agregar dato" << '\n';
      std::cout << "2 para quitar dato" << '\n';
      std::cout << "3 para mostrar datos" << '\n';
      std::cout << "-------------------------------------------" << '\n';
      std::cin >> x;
      if (x==1) {
        std::cout << "que dato agregar dato" << '\n';
        std::cin >> y;
          p1.add(y);
      }
      if (x==2) {
        std::cout << "que dato quitar dato" << '\n';
        std::cin >> y;
        p1.remover(y);
      }
      if (x==3) {
        p1.show();

      }
      if (x==4) {
          break;
      }
    }


    return 0;
}
