#ifndef COLA_HPP
#define COLA_HPP
#include "Nodo.hpp" 


class Cola
{
private:
    pNodo ultimo;
    pNodo primero;
    
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
