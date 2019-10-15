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
    NodoD* aux=fin;
    while(aux != NULL){
        fin = fin->damePre();
        cout<<aux->dameDato()<<endl;
        delete aux;
        aux = fin;
    }
    ini = NULL;
}
