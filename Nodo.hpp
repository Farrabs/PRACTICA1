#ifndef NODO_HPP
#define NODO_HPP

#include <iostream>
using namespace std;

class Nodo
{
public:
    Nodo (int v, Nodo *sig =NULL);
    ~Nodo();

private:
    int valor;
    Nodo* siguiente;
    
    friend class Cola;
    friend class Pila;

};

typedef Nodo* pNodo;

#endif // NODO_HPP
