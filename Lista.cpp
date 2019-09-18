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
    Nodo* aux2;
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
        //aqui va tu tarea =P
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
void Lista::muestraLista(void){
    Nodo* aux = ini;
    while(aux!=NULL){
        aux->muestraDatos();
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





























