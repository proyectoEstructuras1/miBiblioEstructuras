#ifndef COLAT_H
#define COLAT_H


#include <iostream>
#include "NodoT.h"
using namespace std;

template<typename T>
class ColaT{
private:
    NodoT<T>* ini;
    NodoT<T>* fin;
public:
    ColaT(void);
    ~ColaT(void);
    void push(T d);
    T pop(void);
    bool estaVacia(void);
    void vaciaColaT(void);
};
template<typename T>
ColaT<T>::ColaT(void){
    ini = NULL;
    fin = NULL;
}
template<typename T>
ColaT<T>::~ColaT(void){
    vaciaColaT();
}
template<typename T>
void ColaT<T>::push(T d){
}
template<typename T>
T ColaT<T>::pop(void){
}
template<typename T>
bool ColaT<T>::estaVacia(void){
    return (ini == NULL && fin == ini);
}
template<typename T>
void ColaT<T>::vaciaColaT(void){
    while(!estaVacia())
        cout<<pop()<<endl;
}

#endif // COLAT_H
