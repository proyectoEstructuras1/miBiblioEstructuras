#include "ListaD.h"

ListaD::ListaD(void){
    ini = NULL;
    fin = NULL;
}
ListaD::~ListaD(){
    eliminaLista();
}
bool ListaD::estaVacia(void){
    return
        ini == NULL
        &&
        fin ==NULL
    ;
}
void ListaD::muestraIniFin(void){
    NodoD* aux=ini;
    while(aux != NULL){
        aux->muestraDato();
        aux = aux->dameSig();
    }
}
void ListaD::muestraFinIni(void){
    NodoD* aux=fin;
    while(aux != NULL){
        if(ini==fin)
            cout<<"|"<<aux->dameDato()<<"|";
        else if(aux==ini)
            cout<<" <- |"<<aux->dameDato()<<"|";
        else if(aux==fin)
            cout<<"|"<<aux->dameDato()<<"| -> ";
        else
            aux->muestraDato();

        aux = aux->damePre();
    }
}
void ListaD::insertaNodo(int d){
    if(estaVacia()){
        ini = new NodoD(NULL,d,NULL);
        fin = ini;
    }
    else if(d < ini->dameDato()){
        ini->modificaPre(new NodoD(NULL,d,ini));
        ini = ini->damePre();
    }
    else if(d > fin->dameDato()){
        fin->modificaSig(new NodoD(fin,d,NULL));
        fin = fin->dameSig();
    }
    else{

    }
}
void ListaD::eliminaLista(void){
    if(!estaVacia()){
        NodoD* a1=ini;
        NodoD* a2=fin;
        while(
          a1!=a2 &&
          a1->dameSig()!=a2
        ){
            ini=ini->dameSig();
            cout<<a1->dameDato()<<" | ";
            delete a1;
            a1=ini;

            fin=fin->damePre();
            cout<<a2->dameDato()<<endl;
            delete a2;
            a2=fin;

        }
        if(a1==a2){
            cout<<a1->dameDato()<<endl;
            delete a1;
        }
        else{
            cout<<a1->dameDato()<<" | ";
            delete a1;
            cout<<a2->dameDato()<<endl;
            delete a2;
        }
        ini=NULL;
        fin=ini;
    }
}
bool ListaD::buscaNodo(void){
    int d;
    cout<<"Nodo a buscar? ";cin>>d;
    return buscaNodo(d) != NULL;
}
NodoD* ListaD::buscaNodo(int d){
    if(estaVacia())
        return NULL;
    else{
        NodoD* a1=ini;
        NodoD* a2=fin;
        while(
              a1!=a2 &&
              a1->dameSig()!=a2 &&
              d!=a1->dameDato() && d!=a2->dameDato()
              ){
            a1 = a1->dameSig();
            a2 = a2->damePre();
        }
        if(d==a1->dameDato())
            return a1;
        else if(d==a2->dameDato())
            return a2;
        else
            return NULL;
    }
}
bool ListaD::eliminaNodo(int d){
    NodoD* a2;
    a2 = buscaNodo(d);
    if(a2==NULL)
        return false;
    else if(ini==fin){
        delete a2;
        ini=NULL;
        fin=ini;
    }
    else if(a2==ini){
        ini=ini->dameSig();
        ini->modificaPre(NULL);
        delete a2;
    }
    else if(a2==fin){
        fin=fin->damePre();
        fin->modificaSig(NULL);
        delete a2;
    }
    else{
        NodoD* a1 = a2->damePre();
        NodoD* a3 = a2->dameSig();
        a1->modificaSig(a3);
        a3->modificaPre(a1);
        delete a2;
    }
    return true;
}

