#include "Arbol.h"


Arbol::Arbol(NodoA* r){//Temporal, solo para ejemplo.
    raiz = r;
}
Arbol::~Arbol(void){
}
void Arbol::muestraPre(void){
    muestraPre(raiz);
}
void Arbol::muestraPre(NodoA* r){
    if(r!=NULL){
        r->muestraDato();
        muestraPre(r->dameIzq());
        muestraPre(r->dameDer());
    }
}
void Arbol::muestraIn(void){
    muestraIn(raiz);
}
void Arbol::muestraIn(NodoA* r){
    if(r!=NULL){
        muestraIn(r->dameIzq());
        r->muestraDato();
        muestraIn(r->dameDer());
    }
}
void Arbol::muestraPos(void){
    muestraPos(raiz);
}
void Arbol::muestraPos(NodoA* r){
    if(r!=NULL){
        muestraPos(r->dameIzq());
        muestraPos(r->dameDer());
        r->muestraDato();
    }
}

