#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
}

void Pila:: Apilar (int v){
    pNodoPila nuevo;
    nuevo = new NodoPila (v, ultimo);
    ultimo = nuevo;
}

int Pila:: Desapilar (){
    pNodoPila nodo;
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
    pNodoPila aux = ultimo;
    while (aux){
        cout << "   " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila :: Cima(){
    pNodoPila aux = ultimo;
    return aux->valor;
}

bool Pila:: es_Vacia(){
    return (ultimo== NULL);
}
Pila::~Pila()
{
    pNodoPila aux;
    while(ultimo){
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}
