#ifndef LISTA_HPP

#define LISTA_HPP

#include "NodoLista.hpp"

class Lista
{

private:
        
	pNodoLista primero;
	pNodoLista ultimo;
	int longitud;
    
public:
        
	Lista();
	~Lista();
        
	void InsertarIzq(int v);
	void InsertarDer(int v);
	int verPrimero();
	int verUltimo();
	void Mostrar();
	bool esVacia();
	int Longitud();
	int Ver(int i);
	void Insertar(int v,int p);
};

#endif // LISTA_HPP
