#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp" 


class Cola
{
private:
    pNodoCola ultimo;
    pNodoCola primero;
    
public:
    Cola();
    ~Cola();
    
    void Encolar(int v);
    int Desencolar();
    void Mostrar();
    int Primero();
    bool es_Vacia();
};

#endif // COLA_HPP
