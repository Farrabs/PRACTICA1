#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"

class Pila
{
private:
    pNodoPila ultimo;
    
public:
    Pila();
    ~Pila();
    
    void Mostrar();
    void Apilar(int v);
    int Desapilar();
    int Cima();
    bool es_Vacia();


};

#endif // PILA_HPP
