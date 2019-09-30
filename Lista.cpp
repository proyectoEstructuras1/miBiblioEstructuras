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
        cout<<eliminaPrimero()<<endl;
        //eliminaPrimero();
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
bool Lista::eliminaNodo(int d){
    if(estaVacia())
        return false;
    else if(d == ini->dameDato()){
        eliminaPrimero();
        return true;
    }
    else{
        Nodo* aux=ini, *aux2=ini->dameSig();
        while(aux2!=NULL && d != aux2->dameDato()){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        if(aux2==NULL)
            return false;
        else{
            aux->modificaSig(aux2->dameSig());
            delete aux2;
            return true;
        }
    }
}
int Lista::eliminaPrimero(void){
    Nodo* aux;
    int d;
    if(estaVacia()){
        cout<<"Lista vacia... =("<<endl;
        exit(-3);
    }
    aux = ini->dameSig();
    d = ini->dameDato();
    delete ini;
    ini = aux;
    return d;
}
int Lista::eliminaUltimo(void){
    int d;
    if(estaVacia()){
        cout<<"Lista vacia... =("<<endl;
        exit(-4);
    }
    else if(ini->dameSig()==NULL){
        d = ini->dameDato();
        delete ini;
        ini = NULL;
    }
    else {
        Nodo*aux=ini, *aux2=ini->dameSig();
        while(aux2->dameSig() != NULL){
            aux = aux->dameSig();
            aux2 = aux2->dameSig();
        }
        d = aux2->dameDato();
        delete aux2;
        aux->modificaSig(NULL);
    }
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
    if(estaVacia()){
        cout<<"Lista vacia... =("<<endl;
        exit(-1);
    }
    return ini->dameDato();
}
int Lista::dameDatoFin(void){
    Nodo* aux = ini;
    if(estaVacia()){
        cout<<"Lista vacia... =("<<endl;
        exit(-2);
    }
    while(aux->dameSig() != NULL){
        aux = aux->dameSig();
    }
    return aux->dameDato();
}
void Lista::invierteNodos(int n1, int n2){
    Nodo* a1,*a2;
    Nodo* a3,*a4;
    Nodo* intermedio;

    if(estaVacia()){
        cout<<"Lista vacia!\n"<<endl;
    }
    else if(buscaNodo(n1)&&buscaNodo(n2)){
        if(n1!=ini->dameDato()&&n2!=ini->dameDato()){
            a1=ini;
            a2=ini->dameSig();
            while(n1 != a2->dameDato()){
                a1=a1->dameSig();
                a2=a2->dameSig();
            }
            a3=ini;
            a4=ini->dameSig();
            while(n2 != a4->dameDato()){
                a3=a3->dameSig();
                a4=a4->dameSig();
            }
            a1->modificaSig(a4);
            a3->modificaSig(a2);
            intermedio = a2->dameSig();
            a2->modificaSig(a4->dameSig());
            a4->modificaSig(intermedio);
        }
    }
    else{
        cout<<"No'stan! =P"<<endl;
    }
}
void Lista::copiaEnListaMayoresQue(Lista& Lcopia, int n){
    Nodo* aux=ini;
    while(aux!=NULL){
        if(aux->dameDato()>=n)
            Lcopia.insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
}
void Lista::fusiona(Lista& A, Lista& B){
    Nodo* aux;

    aux = A.ini;
    while(aux!=NULL){
        insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
    aux = B.ini;
    while(aux!=NULL){
        insertaNodo(aux->dameDato());
        aux = aux->dameSig();
    }
}

