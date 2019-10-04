#ifndef LISTAT_H
#define LISTAT_H


#include <iostream>
#include <stdlib.h>
#include "NodoT.h"
using namespace std;

template<typename T>
class ListaT{
private:
    NodoT<T>* ini;
public:
    ListaT(void);
    ~ListaT(void);
    void eliminaLista(void);
    bool estaVacia(void);
    void insertaNodo(T d);
    bool eliminaNodo(T d);
    T eliminaPrimero(void);
    T eliminaUltimo(void);
    bool buscaNodo(T d);
    void muestraLista(void);
    void muestraListaInvertida(void);
    T dameDatoIni(void);
    T dameDatoFin(void);
    bool invierteNodos(T n1, T n2);
    bool invierteAlPrimero(T n2);
    void copiaEnListaMayoresQue(ListaT<T>& Lcopia, T n);
    void fusiona(ListaT<T>& A, ListaT<T>& B);
};



template<typename T>
ListaT<T>::ListaT(void){
    ini = NULL;
}
template<typename T>
ListaT<T>::~ListaT(void){
    eliminaLista();
}
template<typename T>
bool ListaT<T>::estaVacia(void){
    return ini == NULL;
}
template<typename T>
void ListaT<T>::eliminaLista(void){
    while(!estaVacia()){
        //cout<<eliminaPrimero()<<endl;
        eliminaPrimero();
    }
}
template<typename T>
void ListaT<T>::insertaNodo(T d){
    NodoT<T>* aux=ini;
    if(estaVacia())
        ini = new NodoT<T>(d,ini);
    else if(d <= ini->dameDato())
        ini = new NodoT<T>(d,ini);
    else if(d >= dameDatoFin()){
        while(aux->dameSig() != NULL){
            aux = aux->dameSig();
        }
        aux->modificaSig(new NodoT<T>(d,NULL));
    }
    else{
        NodoT<T>* aux2;
        aux2 = aux->dameSig();
        while(d > aux2->dameDato()){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        aux->modificaSig(
            new NodoT<T>(d,aux2)
        );
    }
}
template<typename T>
bool ListaT<T>::eliminaNodo(T d){
    if(estaVacia())
        return false;
    else if(d == ini->dameDato()){
        eliminaPrimero();
        return true;
    }
    else{
        NodoT<T>* aux=ini, *aux2=ini->dameSig();
        while(aux2!=NULL && d != aux2->dameDato()){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        if(aux2==NULL)
            return false;
        else{
            aux->modificaSig(aux2->dameSig());
            delete aux2;
            return true;
        }
    }
}
template<typename T>
T ListaT<T>::eliminaPrimero(void){
    NodoT<T>* aux;
    T d;
    if(estaVacia()){
        cout<<"ListaT<T> vacia... =("<<endl;
        exit(-3);
    }
    aux = ini->dameSig();
    d = ini->dameDato();
    delete ini;
    ini = aux;
    return d;
}
template<typename T>
T ListaT<T>::eliminaUltimo(void){
    T d;
    if(estaVacia()){
        cout<<"ListaT<T> vacia... =("<<endl;
        exit(-4);
    }
    else if(ini->dameSig()==NULL){
        d = ini->dameDato();
        delete ini;
        ini = NULL;
    }
    else {
        NodoT<T>*aux=ini, *aux2=ini->dameSig();
        while(aux2->dameSig() != NULL){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        d = aux2->dameDato();
        delete aux2;
        aux->modificaSig(NULL);
    }
    return d;
}
template<typename T>
bool ListaT<T>::buscaNodo(T d){
    NodoT<T>* aux = ini;
    while(aux!=NULL){
        if(d == aux->dameDato())
            return true;
        aux = aux->dameSig();
    }
    return false;
}
template<typename T>
void ListaT<T>::muestraLista(void){
    NodoT<T>* aux = ini;
    while(aux!=NULL){
        aux->muestraDato();
        aux = aux->dameSig();
    }
}
template<typename T>
T ListaT<T>::dameDatoIni(void){
    if(estaVacia()){
        cout<<"ListaT<T> vacia... =("<<endl;
        exit(-1);
    }
    return ini->dameDato();
}
template<typename T>
T ListaT<T>::dameDatoFin(void){
    NodoT<T>* aux = ini;
    if(estaVacia()){
        cout<<"ListaT<T> vacia... =("<<endl;
        exit(-2);
    }
    while(aux->dameSig() != NULL){
        aux = aux->dameSig();
    }
    return aux->dameDato();
}
template<typename T>
bool ListaT<T>::invierteNodos(T n1, T n2){
    NodoT<T>* a1,*a2;
    NodoT<T>* a3,*a4;
    NodoT<T>* intermedio;

    if(estaVacia())//No hay nodos
        return false;
    else if(ini->dameSig()==NULL)//Hay solo un nodo
        return false;
    else if(n1 == ini->dameDato()){//Hay mas de un nodo, y n1 es el primero.
        return invierteAlPrimero(n2);
    }
    else if(n2==ini->dameDato()){//Hay mas de un nodo, y n2 es el primero.
        return invierteAlPrimero(n1);
    }
    else{//Hay mas de un nodo, y ni n1 ni n2 es el primero. Se buscan los nodos.
        a1=ini;
        a2=ini->dameSig();
        while(a2!=NULL && n1 != a2->dameDato()){//Se busca el primer numero.
            a1=a1->dameSig();
            a2=a2->dameSig();
        }
        if(a2==NULL)//Si el primer numero no esta.
            return false;
        else{//El primer numero esta.
            a3=ini;
            a4=ini->dameSig();
            while(a4!=NULL && n2 != a4->dameDato()){//se busca el segundo numero.
                a3=a3->dameSig();
                a4=a4->dameSig();
            }
            if(a4==NULL)//Si el segundo numero no esta.
                return false;
            else{//Ambos numeros estan, se intercambian.
                a1->modificaSig(a4);
                a3->modificaSig(a2);
                intermedio = a2->dameSig();
                a2->modificaSig(a4->dameSig());
                a4->modificaSig(intermedio);
                return true;
            }
        }
    }
}
template<typename T>
bool ListaT<T>::invierteAlPrimero(T n2){
    NodoT<T>* a1;
    NodoT<T>* a3,*a4;
    NodoT<T>* intermedio;

    if(estaVacia())
        return false;
    if(ini->dameSig()!=NULL){//Si hay mas de un nodo
        a1=ini;
        a3=ini;
        a4=a3->dameSig();
        while(a4!=NULL && a4->dameDato()!=n2){//Se busca n2
            a3 = a3->dameSig();
            a4 = a4->dameSig();
        }
        if(a4==NULL)//Si no encontro n2
            return false;
        else{//Si encontro n2, lo intercambia con el primero.
            a3->modificaSig(a1);
            ini = a4;
            intermedio = a1->dameSig();
            a1->modificaSig(a4->dameSig());
            a4->modificaSig(intermedio);
            return true;
        }
    }
    else//Si solo hay un nodo.
        return false;
}
template<typename T>
void ListaT<T>::copiaEnListaMayoresQue(ListaT<T>& Lcopia, T n){
    NodoT<T>* aux=ini;
    while(aux!=NULL){
        if(aux->dameDato()>=n)
            Lcopia.insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
}
template<typename T>
void ListaT<T>::fusiona(ListaT<T>& A, ListaT<T>& B){
    NodoT<T>* aux;

    aux = A.ini;
    while(aux!=NULL){
        insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
    aux = B.ini;
    while(aux!=NULL){
        insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
}
template<typename T>
void ListaT<T>::muestraListaInvertida(void){
    if(!estaVacia()){
        NodoT<T>* a1=ini;
        NodoT<T>* a2=NULL;
        while(a2!=ini){
            while(a1->dameSig() != a2){
                a1 = a1->dameSig();
            }
            cout << "|" << a1->dameDato() << "|";
            if(a1!=ini)
                cout<< " -> ";
            a2=a1;
            a1=ini;
        }
    }
}



#endif // LISTAT_H
