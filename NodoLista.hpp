#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include <iostream>
using namespace std;

class NodoLista
{
public:
    NodoLista (int v, NodoLista *sig =NULL);
    ~NodoLista();

private:
    int valor;
    NodoLista* siguiente;
    
    friend class Lista;

};

typedef NodoLista* pNodoLista;

#endif // NODOLISTA_HPP
