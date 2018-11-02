#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
}

void Pila:: Apilar (int v){
    pNodo nuevo;
    nuevo = new Nodo (v, ultimo);
    ultimo = nuevo;
}

int Pila:: Desapilar (){
    pNodo nodo;
    int v;
    if (!ultimo){
        return 0;
    }
    nodo = ultimo;
    ultimo = nodo->siguiente;
    v = nodo ->valor;
    
    delete nodo;
    return v;
}

void Pila :: Mostrar(){
    pNodo aux = ultimo;
    while (aux){
        cout << "   " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila :: Cima(){
    pNodo aux = ultimo;
    return aux->valor;
}

bool Pila:: es_Vacia(){
    return (ultimo== NULL);
}
Pila::~Pila()
{
    pNodo aux;
    while(ultimo){
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}