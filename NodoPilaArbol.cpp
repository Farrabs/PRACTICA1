#include "NodoPilaArbol.hpp"

NodoPilaArbol::NodoPilaArbol(Arbol v, NodoPilaArbol *sig)
{
      arbol = v;
      siguiente = sig;
}

NodoPilaArbol::~NodoPilaArbol()
{
}
