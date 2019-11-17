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
bool Arbol::buscaNodo(int d){
    if(raiz==NULL)
        return false;
    else if(d==raiz->dameDato())
        return true;
    else
        return buscaNodo(raiz,d);
}
bool Arbol::buscaNodo(NodoA* r, int d){
    if(d==r->dameDato())
        return true;
    else if(d<r->dameDato() && r->dameIzq()==NULL)
        return false;
    else if(d>r->dameDato() && r->dameDer()==NULL)
        return false;
    else if(d<r->dameDato())
        return buscaNodo(r->dameIzq(),d);
    else if(d>r->dameDato())
        return buscaNodo(r->dameDer(),d);
}
int Arbol::cuentaNodos(void){
    if(raiz==NULL)
        return 0;
    else
        return cuentaNodos(raiz);
}
int Arbol::cuentaNodos(NodoA* r){
    if(r->dameIzq()==NULL &&
       r->dameDer()==NULL){
        return 1;
    }
    else if(r->dameIzq()!=NULL &&
       r->dameDer()==NULL){
        return 1 + cuentaNodos(r->dameIzq());
    }
    else if(r->dameIzq()==NULL &&
       r->dameDer()!=NULL){
        return 1 + cuentaNodos(r->dameDer());
    }
    else {
        return 1 + cuentaNodos(r->dameIzq())
                 + cuentaNodos(r->dameDer());
    }
}
int Arbol::profundidadDelArbol(void){
    int pP = -1;
    if(raiz==NULL)
        return pP;
    else
        return profundidadDelArbol(raiz,pP);
}
int Arbol::profundidadDelArbol(NodoA* r, int pP){
    if(r->dameIzq()==NULL && r->dameDer()==NULL)
        return pP + 1;
    else if(r->dameIzq()!=NULL && r->dameDer()==NULL)
        return profundidadDelArbol(r->dameIzq(),pP + 1);
    else if(r->dameIzq()==NULL && r->dameDer()!=NULL)
        return profundidadDelArbol(r->dameDer(),pP + 1);
    else if(r->dameIzq()!=NULL && r->dameDer()!=NULL){
        int pI,pD;
        pI = profundidadDelArbol(r->dameIzq(),pP + 1);
        pD = profundidadDelArbol(r->dameDer(),pP + 1);
        if(pI>=pD)
            return pI;
        else
            return pD;
    }
}
bool Arbol::eliminaSubarbol(int d){
    if(raiz==NULL)
        return false;
    else if(d==raiz->dameDato()){
        eliminaArbol();
        return true;
    }
    else
        return eliminaSubarbol(NULL,raiz,d);
}
bool Arbol::eliminaSubarbol(NodoA* nP,NodoA* r,int d){
    if(d==r->dameDato()&&r==nP->dameIzq()){
        eliminaArbol(r);
        nP->modificaIzq(NULL);
        return true;
    }
    else if(d==r->dameDato()&&r==nP->dameDer()){
        eliminaArbol(r);
        nP->modificaDer(NULL);
        return true;
    }
    else if(d<r->dameDato()&&r->dameIzq()==NULL)
        return false;
    else if(d>r->dameDato()&&r->dameDer()==NULL)
        return false;
    else if(d<r->dameDato()&&r->dameIzq()!=NULL)
        return eliminaSubarbol(r,r->dameIzq(),d);
    else if(d>r->dameDato()&&r->dameDer()!=NULL)
        return eliminaSubarbol(r,r->dameDer(),d);
}
bool Arbol::eliminaNodo(int d){
    NodoA* aux;
    if(raiz==NULL){
        cout<<"Arbol vacio"<<endl<<endl;
        return false;
    }
    else
        return eliminaNodo(NULL,raiz,d);
}
bool Arbol::eliminaNodo(NodoA* nP,NodoA* r,int d){
    if(d==r->dameDato() && r->dameIzq()==NULL && r->dameDer()==NULL){//Eres hoja
        delete r;

        if(nP==NULL)//Y eres la raiz
            raiz=NULL;
        else if(r==nP->dameIzq())//Y eres hijo izquierdo de nP
            nP->modificaIzq(NULL);
        else//Y eres hijo derecho de nP
            nP->modificaDer(NULL);

        return true;
    }
    else if(d==r->dameDato() && r->dameIzq()!=NULL && r->dameDer()==NULL){//Solo tienes hijo izquierdo

        if(nP==NULL)//Y eres la raiz
            raiz=r->dameIzq();
        else if(r==nP->dameIzq())//Y eres hijo izquierdo de nP
            nP->modificaIzq(r->dameIzq());
        else//Y eres hijo derecho de nP
            nP->modificaDer(r->dameIzq());

        delete r;
        return true;
    }
    else if(d==r->dameDato() && r->dameIzq()==NULL && r->dameDer()!=NULL){//Solo tienes hijo derecho

        if(nP==NULL)//Y eres la raiz
            raiz=r->dameDer();
        else if(r==nP->dameIzq())//Y eres hijo izquierdo de nP
            nP->modificaIzq(r->dameDer());
        else//Y eres hijo derecho de nP
            nP->modificaDer(r->dameDer());

        delete r;
        return true;
    }
    else if(d==r->dameDato() && r->dameIzq()!=NULL && r->dameDer()!=NULL){//Tienes 2 hijos
        traeMenorNodo(r,r->dameDer(),r);
        return true;
    }
    else if(d<r->dameDato() && r->dameIzq()==NULL){//Buscas un numero inexistente menor a r
        return false;
    }
    else if(d>r->dameDato() && r->dameDer()==NULL){//Buscas un numero inexistente mayor a r
        return false;
    }
    else if(d<r->dameDato() && r->dameIzq()!=NULL)//Ve a buscar d en la rama izquierda de r
        return eliminaNodo(r,r->dameIzq(),d);
    else if(d>r->dameDato() && r->dameDer()!=NULL)//Ve a buscar d en la rama derecha de r
        return eliminaNodo(r,r->dameDer(),d);
}
void Arbol::traeMenorNodo(NodoA* nP,NodoA* r,NodoA* aqui){
    if(r->dameIzq()==NULL && r==nP->dameIzq()){
        aqui->modificaDato(r->dameDato());
        nP->modificaIzq(NULL);
        delete r;
    }
    else if(r->dameIzq()==NULL && r==nP->dameDer()){
        aqui->modificaDato(r->dameDato());
        nP->modificaDer(NULL);
        delete r;
    }
    else
        traeMenorNodo(r,r->dameIzq(),aqui);
}
