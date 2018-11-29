#ifndef PILAARBOL_HPP
#define PILAARBOL_HPP
#include "NodoPila.hpp"
#include "NodoArbol.hpp"
#include "NodoPilaArbol.hpp"
#include "Arbol.hpp"

class PilaArbol
{
private:
      pNodoPilaArbol ultimo;

public:
      PilaArbol();
      ~PilaArbol();
      
      Arbol DesapilarArbol();
      void ApilarArbol(Arbol arbol);
      bool es_Vacia();

};

#endif // PILAARBOL_HPP
