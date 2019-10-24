#include "NodoC.h"

NodoC::NodoC(void){
    sig = NULL;
}
NodoC::NodoC(Contacto d, NodoC* s){
    dato = d;
    sig = s;
}
void NodoC::muestraDatos(void){
    cout << "|" << dato << "|";
    if(sig == NULL)
        cout<< "NULL|";
    else
        cout<< " -> " << sig << "| ";
}
void NodoC::muestraDato(void){
    cout << dato;
    if(sig != NULL)
        cout<< " -> "<<endl<<endl;
}
void NodoC::pideDatos(void){
    cout<<"Dame mi dato: ";cin>>dato;
}

Contacto NodoC::dameDato(void){
    return dato;
}
void NodoC::modificaDato(Contacto d){
    dato = d;
}
NodoC* NodoC::dameSig(void){
    return sig;
}
void NodoC::modificaSig(NodoC* s){
    sig = s;
}
