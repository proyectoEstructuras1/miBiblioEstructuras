#include "Pila.h"

Pila::Pila(void){
    top = NULL;
}
void Pila::push(int d){
    top = new Nodo(d,top);
}
int Pila::pop(void){
    int d;
    Nodo* aux;
    d = top->dameDato();
    aux = top->dameSig();
    delete top;
    top = aux;
    return d;
}
int Pila::dameTop(void){
    return top->dameDato();
}
void Pila::push(void){
    int d;
    cout<<"Dame d ";cin>>d;
    top = new Nodo(d,top);
}
bool Pila::estaVacia(void){
    if(top == NULL)
        return true;
    else

        return false;
}
void Pila::vaciaPila(void){
    while(!estaVacia())
        cout << pop() << endl;
}
Pila::~Pila(){
    vaciaPila();
}
