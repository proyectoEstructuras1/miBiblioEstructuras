#include "NodoP.h"

NodoP::NodoP(void){
    sig = NULL;
}
NodoP::NodoP(Termino d, NodoP* s){
    dato = d;
    sig = s;
}
void NodoP::muestraDatos(void){
    cout << "|" << dato << "|";
    if(sig == NULL)
        cout<< "NULL|";
    else
        cout<< " -> " << sig << "| ";
}
void NodoP::muestraDato(void){
    cout << "|" << dato << "|";
    if(sig != NULL)
        cout<< " -> ";
}
void NodoP::pideDatos(void){
    cout<<"Dame mi dato: ";cin>>dato;
}

Termino NodoP::dameDato(void){
    return dato;
}
void NodoP::modificaDato(Termino d){
    dato = d;
}
NodoP* NodoP::dameSig(void){
    return sig;
}
void NodoP::modificaSig(NodoP* s){
    sig = s;
}
