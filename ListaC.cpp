#include "ListaC.h"

ListaC::ListaC(void){
    ini = NULL;
}
ListaC::~ListaC(void){
    eliminaListaC();
}
bool ListaC::estaVacia(void){
    return ini == NULL;
}
void ListaC::insertaNodo(Contacto d){
    ini = new NodoC(d,ini);
}
bool ListaC::buscaNodo(Contacto d){
    NodoC* aux = ini;
    while(aux!=NULL && d!=aux->dameDato()){
        aux = aux->dameSig();
    }
    if(aux == NULL)
        return false;
    else
        return true;
}
void ListaC::eliminaListaC(void){
    NodoC* aux = ini;
    while(aux != NULL){
        ini = ini->dameSig();
        cout<<aux->dameDato()<<endl;
        delete aux;
        aux = ini;
    }
}
void ListaC::muestraListaC(void){
    NodoC* aux = ini;
    while(aux != NULL){
        cout<<aux->dameDato()<<endl;
        aux = aux->dameSig();
    }
}
void ListaC::guardaLista(void){
    ofstream HaciaArchivo("archivo.txt");
    NodoC* aux=ini;
    while(aux!=NULL){
        HaciaArchivo << aux->dameDato();
        aux = aux->dameSig();
        if(aux!=NULL)
            HaciaArchivo<<endl;
    }
    HaciaArchivo.close();
}
void ListaC::cargaLista(void){
    ifstream DesdeArchivo("archivo.txt");
    Contacto X;
    while(!DesdeArchivo.eof()){
        DesdeArchivo >> X;
        insertaNodo(X);
    }
    DesdeArchivo.close();
}

