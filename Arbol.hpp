#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "NodoArbol.hpp"
class Arbol
{
private:
      pNodoArbol raiz, actual;
      int contador, altura;
      
public:
      Arbol();
      ~Arbol();
      void Podar(pNodoArbol &nodo);
      void auxContador(pNodoArbol nodo);
      void auxAltura(pNodoArbol nodo, int a);
      void Mostrar(int &d);
      bool buscarNodo (int v);
      void insertarNodo (int v);
      void borrarNodo (int v);
      bool esArbolVacio();
      bool esNodoVacio(pNodoArbol nodo);
      bool esHoja(pNodoArbol nodo);
      int numeroNodos();
      int getAlturaArbol(NodoArbol *nodo);
      int getValorActual();
      pNodoArbol getRaiz();
      int getValorRaiz();
      bool esRaiz(pNodoArbol nodo);
      void inOrden(NodoArbol *nodo); 
      void preOrden(NodoArbol *nodo);
      void postOrden(NodoArbol *nodo);
      void printTree(NodoArbol* p, int indent);
      void printValor(NodoArbol *p);

};

#endif // ARBOL_HPP
