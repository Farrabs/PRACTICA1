#include "NodoPilaArbol.hpp"


NodoPilaArbol::NodoPilaArbol(NodoArbol *a, NodoPilaArbol *sig)
{
      arbol = a;
      siguiente = sig;
}

NodoPilaArbol::~NodoPilaArbol()
{
}
