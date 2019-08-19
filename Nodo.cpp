#include "Nodo.h"

Nodo::Nodo(void){
    dato = 0;
    sig = NULL;
}
Nodo::Nodo(int d, Nodo* s){
    dato = d;
    sig = s;
}
void Nodo::muestraDatos(void){
    cout << "|" << dato << "|";
    if(sig == NULL)
        cout<< "NULL|";
    else
        cout<< " -> " << sig << "| ";
}
void Nodo::pideDatos(void){
    cout<<"Dame mi dato: ";cin>>dato;
}

int Nodo::dameDato(void){
    return dato;
}
void Nodo::modificaDato(int d){
    dato = d;
}
Nodo* Nodo::dameSig(void){
    return sig;
}
void Nodo::modificaSig(Nodo* s){
    sig = s;
}
