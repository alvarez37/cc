#include <iostream>
using namespace std;

template <class T2>
class nodo{
  public:
    static int contador;
    T2 valor;
    nodo * next;
    nodo * prev;
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
        nodo<T> *head=NULL;
        bool find(T valor,nodo <T> * &ptr);
        void add (T dato);
        bool buscar (T dato);
        void apuntar_al_final(nodo <T> * &ptr);


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
  nodo<T> *pos2;

  if (!find(dato,pos)) {
    if (!pos) {
      pos2=pos;
      head= new nodo<T>(dato,head);
      if (head->contador>2) {
        head->next->prev=head;
      }
    }
    else{


      pos->next=new nodo<T>(dato,pos->next);
      pos->next->prev=pos;
      }
    }
    head->prev=NULL;

  }

template <class T>
void lista_enlazada<T>::show() {

  std::cout  << '\n';
  int i=0;
  for (nodo <T> *p=head; p and i < head->contador;i++, p=p->next) {
      std::cout << i << "     [ id: " << p<< "    valor: " << p->valor <<"    prev->  " << p->prev <<"    next->  " << p->next<<  " ]"<<" "<< endl;
    }

    std::cout << "cantidad de elementos: " << head->contador<< '\n';
  std::cout  << '\n';

}

template <class T>
void lista_enlazada<T>::remover(T dato){
  nodo<T> *pos;
  nodo<T> *pos2;
  nodo<T> *pos3;


      if (find(dato,pos)) {
        find(dato,pos);
        if(pos!=0){
          apuntar_al_final(pos2);

          pos->next=pos->next->next;
          if ((pos->next == pos2) ) {
            pos3=pos->next;
            pos->next->prev=pos;

          }
          else{
            // pos->next->prev=pos;
          }


          delete pos3;
        }

        else{
          std::cout << "  QUI   "<< head->valor  << '\n';
          pos2=head;

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
        p1.show();
        p1.add(10);
        p1.show();
        p1.add(11);
        p1.add(12);
        p1.add(14);
        p1.show();

       p1.remover(14);
        p1.show();
        p1.add(8);
        p1.add(78);

        p1.show();
        std::cout << "esta: " << p1.buscar(5) << '\n';

        p1.show();

    return 0;
}
