#include "Arbol.h"


Arbol::Arbol(void){
    raiz = NULL;
}
Arbol::~Arbol(void){
    eliminaArbol();
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
void Arbol::insertaNodo(int d){
    if(raiz==NULL)
        raiz = new NodoA(NULL,d,NULL);
    else
        insertaNodo(raiz,d);
}
void Arbol::insertaNodo(NodoA* r, int d){
    if(d<=r->dameDato() && r->dameIzq()==NULL)
        r->modificaIzq(new NodoA(NULL,d,NULL));
    else if(d>r->dameDato() && r->dameDer()==NULL)
        r->modificaDer(new NodoA(NULL,d,NULL));
    else if(d<=r->dameDato() && r->dameIzq()!=NULL)
        insertaNodo(r->dameIzq(),d);
    else if(d>r->dameDato() && r->dameDer()!=NULL)
        insertaNodo(r->dameDer(),d);
}
void Arbol::eliminaArbol(void){
    if(raiz!=NULL){
        eliminaArbol(raiz);
        raiz=NULL;
    }
}
void Arbol::eliminaArbol(NodoA* r){
    if(r!=NULL){
        eliminaArbol(r->dameIzq());
        eliminaArbol(r->dameDer());
        r->muestraDato();
        delete r;
    }
}

