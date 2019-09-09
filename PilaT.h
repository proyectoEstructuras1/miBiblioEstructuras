#ifndef PILAT_H
#define PILAT_H


#include <iostream>
#include "NodoT.h"
using namespace std;

template<typename T>
class PilaT{
private:
    NodoT<T>* top;
public:
    PilaT(void);
    ~PilaT(void);
    void push(T d);
    T pop(void);
    T dameTop(void);
    void push(void);
    bool estaVacia(void);
    void vaciaPilaT(void);
};
template<typename T>
PilaT<T>::PilaT(void){
    top = NULL;
}
template<typename T>
void PilaT<T>::push(T d){
    top = new NodoT<T>(d,top);
}
template<typename T>
T PilaT<T>::pop(void){
    T d;
    NodoT<T>* aux;
    d = top->dameDato();
    aux = top->dameSig();
    delete top;
    top = aux;
    return d;
}
template<typename T>
T PilaT<T>::dameTop(void){
    return top->dameDato();
}
template<typename T>
void PilaT<T>::push(void){
    T d;
    cout<<"Dame d ";cin>>d;
    top = new NodoT<T>(d,top);
}
template<typename T>
bool PilaT<T>::estaVacia(void){
    if(top == NULL)
        return true;
    else

        return false;
}
template<typename T>
void PilaT<T>::vaciaPilaT(void){
    while(!estaVacia())
        cout << pop() << endl;
}
template<typename T>
PilaT<T>::~PilaT(){
    vaciaPilaT();
}

#endif // PILAT_H
