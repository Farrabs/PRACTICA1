#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"


class Arbol
{
private:
      pNodoArbol raiz;
      int contador, altura;
      
public:
      Arbol();
      ~Arbol();
      pNodoArbol actual;
      void Podar(pNodoArbol &nodo);
      void auxContador(pNodoArbol nodo);
      void auxAltura(pNodoArbol nodo, int a);
      void Mostrar(int &d);
      bool buscarNodo (int v);
      void insertarNodo (int v);
      void insertarNodoExpresion(int v, char*exp);
      void insertarNodoIzquierda(int v, NodoArbol *nodo);
      void insertarNodoDerecha(int v, NodoArbol *nodo);
      void insertarArbolIzquierda(pNodoArbol a, pNodoArbol nodo);
      void insertarArbolDerecha(pNodoArbol a, pNodoArbol nodo);
      void borrarNodo (int v);
      bool esArbolVacio();
      bool esNodoVacio(pNodoArbol nodo);
      bool esHoja(pNodoArbol nodo);
      int getAlturaArbol(NodoArbol *nodo);
      int getValorActual();
      pNodoArbol getRaiz();
      void setRaiz(int v, pNodoArbol izq, pNodoArbol der);
      int getValorRaiz();
      bool esRaiz(pNodoArbol nodo);
      void inOrden(NodoArbol *nodo); 
      void inOrdenExp(pNodoArbol nodo);
      void preOrden(NodoArbol *nodo);
      void postOrden(NodoArbol *nodo);
      void printTree(NodoArbol* p, int indent);
      void printValor(NodoArbol *p);
      int NumeroHojas(pNodoArbol nodo);
      int NumeroNodos(pNodoArbol nodo);

};

#endif // ARBOL_HPP
