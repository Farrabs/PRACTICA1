#include "PilaArbol.hpp"

PilaArbol::PilaArbol()
{
}

void PilaArbol:: ApilarArbol(Arbol arbol){
      pNodoPilaArbol nuevo;
      nuevo = new NodoPilaArbol(arbol, ultimo);
      ultimo = nuevo;
}

Arbol PilaArbol:: DesapilarArbol(){
      pNodoPilaArbol nodo;
      Arbol arbol ;
      if(!ultimo){
            return arbol;
      }
      nodo = ultimo;
      ultimo = nodo->siguiente;
      arbol = nodo->arbol;
      delete nodo;
      return arbol;
}

bool PilaArbol:: es_Vacia(){
    return (ultimo== NULL);
}


PilaArbol::~PilaArbol()
{
}

