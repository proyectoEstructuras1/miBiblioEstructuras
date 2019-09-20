#include "Lista.h"

Lista::Lista(void){
    ini = NULL;
}
Lista::~Lista(void){
    eliminaLista();
}
bool Lista::estaVacia(void){
    return ini == NULL;
}
void Lista::eliminaLista(void){
    while(!estaVacia()){
        cout<<eliminaNodo()<<endl;
    }
}
void Lista::insertaNodo(int d){
    Nodo* aux=ini;
    if(estaVacia())
        ini = new Nodo(d,ini);
    else if(d <= ini->dameDato())
        ini = new Nodo(d,ini);
    else if(d >= dameDatoFin()){
        while(aux->dameSig() != NULL){
            aux = aux->dameSig();
        }
        aux->modificaSig(new Nodo(d,NULL));
    }
    else{
        Nodo* aux2;
        aux2 = aux->dameSig();
        while(d > aux2->dameDato()){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        aux->modificaSig(
            new Nodo(d,aux2)
        );
    }
}
int Lista::eliminaNodo(void){
    //Esta incompleto

    Nodo* aux;
    int d;
    aux = ini->dameSig();
    d = ini->dameDato();
    delete ini;
    ini = aux;
    return d;
}
bool Lista::buscaNodo(int d){
    Nodo* aux = ini;
    while(aux!=NULL){
        if(d == aux->dameDato())
            return true;
        aux = aux->dameSig();
    }
    return false;
}
void Lista::muestraLista(void){
    Nodo* aux = ini;
    while(aux!=NULL){
        aux->muestraDato();
        aux = aux->dameSig();
    }
}
int Lista::dameDatoIni(void){
    return ini->dameDato();
}
int Lista::dameDatoFin(void){
    Nodo* aux = ini;
    if(estaVacia()){
        cout<<"Lista vacia... =("<<endl;
        exit(-1);
    }
    while(aux->dameSig() != NULL){
        aux = aux->dameSig();
    }
    return aux->dameDato();
}
