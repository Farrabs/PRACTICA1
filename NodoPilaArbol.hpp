#ifndef NODOPILAARBOL_HPP
#define NODOPILAARBOL_HPP
#include "Arbol.hpp"
#include "NodoArbol.hpp"

class NodoPilaArbol
{
public:
      NodoPilaArbol(NodoArbol *a, NodoPilaArbol * sig=NULL);
      ~NodoPilaArbol();
      
private:
      NodoArbol *arbol;
      NodoPilaArbol* siguiente;
      
      friend class PilaArbol;
      friend class Evaluacion;

};

typedef NodoPilaArbol* pNodoPilaArbol;

#endif // NODOPILAARBOL_HPP
