#ifndef PILA_HPP
#define PILA_HPP
#include "Nodo.hpp"

class Pila
{
private:
    pNodo ultimo;
    
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