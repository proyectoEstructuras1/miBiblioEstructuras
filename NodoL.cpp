#include "NodoL.h"

NodoL::NodoL(void){
    sig = NULL;
}
NodoL::NodoL(Libro d, NodoL* s){
    dato = d;
    sig = s;
}
void NodoL::muestraDatos(void){
    cout << "|" << dato << "|";
    if(sig == NULL)
        cout<< "NULL|";
    else
        cout<< " -> " << sig << "| ";
}
void NodoL::muestraDato(void){
    cout << dato;
    if(sig != NULL)
        cout<< " -> "<<endl<<endl;
}
void NodoL::pideDatos(void){
    cout<<"Dame mi dato: ";cin>>dato;
}

Libro NodoL::dameDato(void){
    return dato;
}
void NodoL::modificaDato(Libro d){
    dato = d;
}
NodoL* NodoL::dameSig(void){
    return sig;
}
void NodoL::modificaSig(NodoL* s){
    sig = s;
}
