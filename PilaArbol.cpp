#include "PilaArbol.hpp"

PilaArbol::PilaArbol()
{
      ultimo = NULL;
}


void PilaArbol:: ApilarArbol(pNodoArbol a){
      pNodoPilaArbol nuevo;
      nuevo = new NodoPilaArbol (a, ultimo);
      ultimo = nuevo;
}

pNodoArbol PilaArbol:: DesapilarArbol (){
    pNodoPilaArbol nodo;
    pNodoArbol a =NULL;
    if (!ultimo){
        return a;
    }
    nodo = ultimo;
    ultimo = nodo->siguiente;
    a = nodo->arbol;
    
    delete nodo;
    return a;
}

pNodoArbol PilaArbol :: Cima(){
    pNodoPilaArbol aux = ultimo;
    return aux->arbol;
}

bool PilaArbol:: es_Vacia(){
    return (ultimo== NULL);
}



PilaArbol::~PilaArbol()
{
}
