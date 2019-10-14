#include "NodoD.h"

NodoD::NodoD(void): Nodo(){
    pre = NULL;
}
NodoD::NodoD(NodoD* p, int d, Nodo* s):Nodo(d,s){
    pre = p;
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

