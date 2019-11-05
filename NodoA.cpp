#include "NodoA.h"

NodoA::NodoA(void){
    izq = NULL;
    dato = 0;
    der = NULL;
}
NodoA::NodoA(NodoA* i, int da, NodoA* d){
    izq = i;
    dato = da;
    der = d;
}
void NodoA::pideDatos(void){
    cout<<"Dame mi dato: ";
    cin>>dato;
}
void NodoA::muestraDato(void){
    if(izq != NULL)
        cout<<  " <- ";
    cout << "|" << dato <<"|";
    if(der != NULL)
        cout<< " -> ";
}
void NodoA::muestraDatos(void){
    cout<<" ";
    if(izq == NULL)
        cout<<"NULL";
    else
        cout<<izq;
    cout<<  " <- |" << dato <<"| -> ";
    if(der == NULL)
        cout<<"NULL";
    else
        cout<<der;
    cout<<" ";
}
NodoA* NodoA::dameIzq(void){
    return izq;
}
void NodoA::modificaIzq(NodoA* i){
    izq = i;
}
int NodoA::dameDato(void){
    return dato;
}
void NodoA::modificaDato(int da){
    dato = da;
}
NodoA* NodoA::dameDer(void){
    return der;
}
void NodoA::modificaDer(NodoA* da){
    der = da;
}

