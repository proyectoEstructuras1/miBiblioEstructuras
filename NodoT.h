#ifndef NODOT_H
#define NODOT_H


#include <iostream>
using namespace std;

template<typename T>
class NodoT{
private:
    T dato;
    NodoT<T>* sig;
public:
    NodoT(void);
    NodoT(T d, NodoT<T>* s);
    void muestraDatos(void);
    void pideDatos(void);
    T dameDato(void);
    void modificaDato(T d);
    NodoT<T>* dameSig(void);
    void modificaSig(NodoT<T>* s);
};

template<typename T>
NodoT<T>::NodoT(void){
    dato = 0;
    sig = NULL;
}
template<typename T>
NodoT<T>::NodoT(T d, NodoT<T>* s){
    dato = d;
    sig = s;
}
template<typename T>
void NodoT<T>::muestraDatos(void){
    cout << "|" << dato << "|";
    if(sig == NULL)
        cout<< "NULL|";
    else
        cout<< " -> " << sig << "| ";
}
template<typename T>
void NodoT<T>::pideDatos(void){
    cout<<"Dame mi dato: ";cin>>dato;
}
template<typename T>
T NodoT<T>::dameDato(void){
    return dato;
}
template<typename T>
void NodoT<T>::modificaDato(T d){
    dato = d;
}
template<typename T>
NodoT<T>* NodoT<T>::dameSig(void){
    return sig;
}
template<typename T>
void NodoT<T>::modificaSig(NodoT<T>* s){
    sig = s;
}

#endif // NODOT_H
