#include "Cola.hpp"
using namespace std;

Cola::Cola()
{
    ultimo = NULL;
    primero = NULL;
}

void Cola:: Encolar(int v){
    pNodo nuevo = new Nodo (v,NULL);
    if (ultimo){
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if(!primero){
        primero = nuevo;
    }
}

int Cola:: Desencolar(){
    
    pNodo aux = primero;
    int v = aux-> valor;
    if(!aux){
        return 0;
    }
    primero = aux->siguiente;
    delete aux;
    if(!primero){
        ultimo =NULL;
    }
    return v;
}

void Cola:: Mostrar(){
    pNodo aux = primero;
    while (aux){
        cout << "   " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}

int Cola::Primero(){
    int v= primero->valor;
    return v;
}

bool Cola:: es_Vacia(){
    return (primero == NULL);
}

Cola::~Cola()
{

}

