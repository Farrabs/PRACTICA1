#ifndef PILAARBOL_HPP
#define PILAARBOL_HPP
#include "NodoPilaArbol.hpp"

class PilaArbol
{
private:
      pNodoPilaArbol ultimo;
public:
      PilaArbol();
      ~PilaArbol();
      
      void ApilarArbol(pNodoArbol a);
      pNodoArbol DesapilarArbol();
      pNodoArbol Cima();
      bool es_Vacia();
      void Mostrar();

};

#endif // PILAARBOL_HPP
