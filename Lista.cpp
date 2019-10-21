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
bool Lista::invierteNodos(int n1, int n2){
    Nodo* a1,*a2;
    Nodo* a3,*a4;
    Nodo* intermedio;

    if(estaVacia())//No hay nodos
        return false;
    else if(ini->dameSig()==NULL)//Hay solo un nodo
        return false;
    else if(n1 == ini->dameDato()){//Hay mas de un nodo, y n1 es el primero.
        return invierteAlPrimero(n2);
    }
    else if(n2==ini->dameDato()){//Hay mas de un nodo, y n2 es el primero.
        return invierteAlPrimero(n1);
    }
    else{//Hay mas de un nodo, y ni n1 ni n2 es el primero. Se buscan los nodos.
        a1=ini;
        a2=ini->dameSig();
        while(a2!=NULL && n1 != a2->dameDato()){//Se busca el primer numero.
            a1=a1->dameSig();
            a2=a2->dameSig();
        }
        if(a2==NULL)//Si el primer numero no esta.
            return false;
        else{//El primer numero esta.
            a3=ini;
            a4=ini->dameSig();
            while(a4!=NULL && n2 != a4->dameDato()){//se busca el segundo numero.
                a3=a3->dameSig();
                a4=a4->dameSig();
            }
            if(a4==NULL)//Si el segundo numero no esta.
                return false;
            else{//Ambos numeros estan, se intercambian.
                a1->modificaSig(a4);
                a3->modificaSig(a2);
                intermedio = a2->dameSig();
                a2->modificaSig(a4->dameSig());
                a4->modificaSig(intermedio);
                return true;
            }
        }
    }
}
bool Lista::invierteAlPrimero(int n2){
    Nodo* a1;
    Nodo* a3,*a4;
    Nodo* intermedio;

    if(estaVacia())
        return false;
    if(ini->dameSig()!=NULL){//Si hay mas de un nodo
        a1=ini;
        a3=ini;
        a4=a3->dameSig();
        while(a4!=NULL && a4->dameDato()!=n2){//Se busca n2
            a3 = a3->dameSig();
            a4 = a4->dameSig();
        }
        if(a4==NULL)//Si no encontro n2
            return false;
        else{//Si encontro n2, lo intercambia con el primero.
            a3->modificaSig(a1);
            ini = a4;
            intermedio = a1->dameSig();
            a1->modificaSig(a4->dameSig());
            a4->modificaSig(intermedio);
            return true;
        }
    }
    else//Si solo hay un nodo.
        return false;
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
void Lista::muestraListaInvertida(void){
    if(!estaVacia()){
        Nodo* a1=ini;
        Nodo* a2=NULL;//El apuntador al que se busca, inicialmente el ultimo, tiene NULL
        while(a2!=ini){
            while(a1->dameSig() != a2){//Se busca al nodo cuyo sig sea a2
                a1 = a1->dameSig();
            }
            cout << "|" << a1->dameDato() << "|";
            if(a1!=ini)
                cout<< " -> ";
            a2=a1;//a2 se vuelve el "ultimo", con cada vuelta, al que se tiene que buscar.
            a1=ini;//Siempre se busca desde el nodo inicial.
        }
    }
}
void Lista::guardaLista(void){
    ofstream HaciaArchvo("archivo.txt");
    Nodo* aux = ini;
    while(aux != NULL){
        HaciaArchvo << aux->dameDato();
        aux = aux->dameSig();
        if(aux!=NULL)
            HaciaArchvo << endl;
    }
    HaciaArchvo.close();
}
void Lista::cargaLista(void){
    ifstream DesdeArchvo("archivo.txt");
    int d;
    while(!DesdeArchvo.eof()){
        DesdeArchvo >> d;
        insertaNodo(d);
    }
    DesdeArchvo.close();
}

