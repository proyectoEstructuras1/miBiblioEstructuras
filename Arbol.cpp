#include "ArbolP.h"

ArbolP::ArbolP()
{
    raiz=NULL;
}

ArbolP::~ArbolP()
{
  eliminaArbol();
}
//rid
void ArbolP::muestraPre(void)
{
 muestraPre(raiz);
}
void ArbolP::muestraPre(NodoA* r)
{
if(r!=NULL)
{
    r->muestraDato();
    muestraPre(r->dameIzq());
    muestraPre(r->dameDer());


}

}
//idr
void ArbolP::muestraPos(void)
{
muestraPos(raiz);

}
void ArbolP::muestraPos(NodoA* r)
{
if(r!=NULL)
{
    muestraPos(r->dameIzq());
    muestraPos(r->dameDer());
    r->muestraDato();

}


}
//ird
void ArbolP::muestraIn (void)
{
muestraIn(raiz);

}
void ArbolP::muestraIn (NodoA* r)
{
    if(r!=NULL)
    {
     muestraIn(r->dameIzq());
     r->muestraDato();
     muestraIn(r->dameDer());

    }

}
void ArbolP::insertaNodo(Producto d)
{
if(raiz==NULL)
{
 raiz=new NodoA(d,NULL,NULL);


}
else
insertaNodo(raiz,d);

}
void ArbolP::insertaNodo(NodoA* r,Producto d)
{
 if (r->dameIzq()==NULL && d.dameNumero()<=r->dameDato().dameNumero())

    r->modificaIzq(new NodoA(d,NULL,NULL));
else if (r->dameDer()==NULL && d.dameNumero()>r->dameDato().dameNumero())
    r->modificaDer(new NodoA(d,NULL,NULL));
else if (r->dameIzq()!=NULL&& d.dameNumero()<=r->dameDato().dameNumero())
    insertaNodo(r->dameIzq(),d);
else if(r->dameDer()!=NULL && d.dameNumero()>r->dameDato().dameNumero())
    insertaNodo(r->dameDer(),d);

}
void ArbolP::eliminaArbol(void)
{
 if(raiz!=NULL)
 {
     eliminaArbol(raiz);
     raiz=NULL;

 }

}
void ArbolP::eliminaArbol(NodoA* r)
{


if(r!=NULL)
    {eliminaArbol(r->dameIzq());
    eliminaArbol(r->dameDer());

    r->dameDato().muestraDatos();

    delete r;
    }
}
bool ArbolP::buscaNodo(int d)
{
    if(raiz==NULL)
    return false;
    else if (d==raiz->dameDato().dameNumero())
        return true;
    else
    return buscaNodo(raiz,d);


}
bool ArbolP::buscaNodo(NodoA* r, int d)
{

if(d==r->dameDato().dameNumero())
{
 r->dameDato().muestraDatos();
        return true;}
    else if(d<r->dameDato().dameNumero() && r->dameIzq()==NULL)
        return false;
    else if(d>r->dameDato().dameNumero() && r->dameDer()==NULL)
        return false;
    else if(d<r->dameDato().dameNumero())
        return buscaNodo(r->dameIzq(),d);
    else if(d>r->dameDato().dameNumero())
        return buscaNodo(r->dameDer(),d);



}
int ArbolP::cuentaNodos(void)
{
if(raiz==NULL)
    return 0;
else
    return cuentaNodos(raiz);


}
int ArbolP::cuentaNodos(NodoA* r)
{
if(r->dameIzq()==NULL && r->dameDer()==NULL)
return 1;

else if(r->dameIzq()!=NULL && r->dameDer()==NULL)
   return  1+ cuentaNodos(r->dameIzq());
else if (r->dameDer()!=NULL && r->dameIzq()==NULL)
    return 1+cuentaNodos(r->dameDer());
else
    return 1+cuentaNodos(r->dameIzq())+cuentaNodos(r->dameDer());


}
int ArbolP::profundidadDelArbol(void)
{
int pP = -1;
    if(raiz==NULL)
        return pP;
    else
        return profundidadDelArbol(raiz,pP);



}
int ArbolP::profundidadDelArbol(NodoA* r, int pP)
{
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
bool ArbolP::eliminaSubarbol(int d)
{
    if(raiz==NULL)
        return false;
    else if(d==raiz->dameDato().dameNumero()){
        eliminaArbol();
        return true;
    }
    else
        return eliminaSubarbol(NULL,raiz,d);
}
bool ArbolP::eliminaSubarbol(NodoA* nP,NodoA* r,int d){
    if(d==r->dameDato().dameNumero()&&r==nP->dameIzq()){
        eliminaArbol(r);
        nP->modificaIzq(NULL);
        return true;
    }
    else if(d==r->dameDato().dameNumero()&&r==nP->dameDer()){
        eliminaArbol(r);
        nP->modificaDer(NULL);
        return true;
    }
    else if(d<r->dameDato().dameNumero()&&r->dameIzq()==NULL)
        return false;
    else if(d>r->dameDato().dameNumero()&&r->dameDer()==NULL)
        return false;
    else if(d<r->dameDato().dameNumero()&&r->dameIzq()!=NULL)
        return eliminaSubarbol(r,r->dameIzq(),d);
    else if(d>r->dameDato().dameNumero()&&r->dameDer()!=NULL)
        return eliminaSubarbol(r,r->dameDer(),d);
}

bool ArbolP::eliminaNodo(int d)
{
   if(raiz==NULL)
        return false;
    else if(d==raiz->dameDato().dameNumero()){
        eliminaArbol();
        return true;
    }
    else
        return eliminaNodo(NULL,raiz,d);



}
bool ArbolP::eliminaNodo(NodoA* nP,NodoA* r,int d){
    if(d==r->dameDato().dameNumero() && r->dameIzq()==NULL && r->dameDer()==NULL){
        delete r;

        if(nP==NULL)//Y eres la raiz
            raiz=NULL;
        else if(r==nP->dameIzq())
            nP->modificaIzq(NULL);
        else//Y eres hijo derecho de nP
            nP->modificaDer(NULL);

        return true;
    }
    else if(d==r->dameDato().dameNumero() && r->dameIzq()!=NULL && r->dameDer()==NULL){
        if(nP==NULL)
            raiz=r->dameIzq();
        else if(r==nP->dameIzq())
            nP->modificaIzq(r->dameIzq());
        else
            nP->modificaDer(r->dameIzq());

        delete r;
        return true;
    }
    else if(d==r->dameDato().dameNumero() && r->dameIzq()==NULL && r->dameDer()!=NULL){
        if(nP==NULL)
            raiz=r->dameDer();
        else if(r==nP->dameIzq())
            nP->modificaIzq(r->dameDer());
        else
            nP->modificaDer(r->dameDer());

        delete r;
        return true;
    }
    else if(d==r->dameDato().dameNumero() && r->dameIzq()!=NULL && r->dameDer()!=NULL){
        traeMenorNodo(r,r->dameDer(),r);
        return true;
    }
    else if(d<r->dameDato().dameNumero() && r->dameIzq()==NULL){
        return false;
    }
    else if(d>r->dameDato().dameNumero() && r->dameDer()==NULL){
        return false;
    }
    else if(d<r->dameDato().dameNumero() && r->dameIzq()!=NULL)
        return eliminaNodo(r,r->dameIzq(),d);
    else if(d>r->dameDato().dameNumero() && r->dameDer()!=NULL)
        return eliminaNodo(r,r->dameDer(),d);
}
void ArbolP::traeMenorNodo(NodoA* nP,NodoA* r,NodoA* aqui)
{
    if(r->dameIzq()==NULL && r->dameDer()==NULL && r==nP->dameIzq()){
        aqui->modificaDato(r->dameDato());
        nP->modificaIzq(NULL);
        delete r;
    }
    else if(r->dameIzq()==NULL && r->dameDer()==NULL && r==nP->dameDer()){
        aqui->modificaDato(r->dameDato());
        nP->modificaDer(NULL);
        delete r;
    }
    else if(r->dameIzq()==NULL && r->dameDer()!=NULL && r==nP->dameIzq()){
        aqui->modificaDato(r->dameDato());
        nP->modificaIzq(r->dameDer());
        delete r;
    }
    else if(r->dameIzq()==NULL && r->dameDer()!=NULL && r==nP->dameDer()){
        aqui->modificaDato(r->dameDato());
        nP->modificaDer(r->dameDer());
        delete r;
    }
    else
        traeMenorNodo(r,r->dameIzq(),aqui);
}
