#include "ListaL.h"

ListaL::ListaL(void){
    ini = NULL;
}
ListaL::~ListaL(void){
    eliminaListaL();
}
bool ListaL::estaVacia(void){
    return ini == NULL;
}
void ListaL::insertaNodo(Libro d){
    ini = new NodoL(d,ini);
}
bool ListaL::buscaNodo(Libro d){
    NodoL* aux = ini;
    while(aux!=NULL && d!=aux->dameDato()){
        aux = aux->dameSig();
    }
    if(aux == NULL)
        return false;
    else
        return true;
}
void ListaL::eliminaListaL(void){
    NodoL* aux = ini;
    while(aux != NULL){
        ini = ini->dameSig();
        cout<<aux->dameDato()<<endl;
        delete aux;
        aux = ini;
    }
}
void ListaL::muestraListaL(void){
    NodoL* aux = ini;
    while(aux != NULL){
        cout<<aux->dameDato()<<endl;
        aux = aux->dameSig();
    }
}

