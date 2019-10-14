#include "NodoD.h"

NodoD::NodoD(void){
    pre = NULL;
    dato = 0;
    sig = NULL;
}
NodoD::NodoD(NodoD* p, int d, NodoD* s){
    pre = p;
    dato = d;
    sig = s;
}
void NodoD::pideDatos(void){
    cout<<"Dame mi dato: ";
    cin>>dato;
}
void NodoD::muestraDato(void){
    if(pre != NULL)
        cout<<  " <- ";
    cout << "|" << dameDato() <<"|";
    if(dameSig() != NULL)
        cout<< " -> ";
}
void NodoD::muestraDatos(void){
    cout<<" ";
    if(pre == NULL)
        cout<<"NULL";
    else
        cout<<pre;
    cout<<  " <- |" << dameDato() <<"| -> ";
    if(dameSig() == NULL)
        cout<<"NULL";
    else
        cout<<dameSig();
    cout<<" ";
}
NodoD* NodoD::damePre(void){
    return pre;
}
void NodoD::modificaPre(NodoD* p){
    pre = p;
}
int NodoD::dameDato(void){
    return dato;
}
void NodoD::modificaDato(int d){
    dato = d;
}
NodoD* NodoD::dameSig(void){
    return sig;
}
void NodoD::modificaSig(NodoD* s){
    sig = s;
}
