#ifndef NODOPILAARBOL_HPP
#define NODOPILAARBOL_HPP
#include "NodoArbol.hpp"
#include "Arbol.hpp"

#include <iostream>
using namespace std;

class NodoPilaArbol
{
public:
    NodoPilaArbol (Arbol v(), NodoPilaArbol *sig =NULL);
    ~NodoPilaArbol();
    
    Arbol arbol;
    NodoPilaArbol* siguiente;

private:
    
    
    friend class Pila;
    friend class Arbol;

};

typedef NodoPilaArbol* pNodoPilaArbol;

#endif // NODOPILAARBOL_HPP
