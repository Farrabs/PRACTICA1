#ifndef EVALUACION_HPP
#define EVALUACION_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
#include <stdio.h>
#include <iostream>

class Evaluacion
{
private:
    int tam_exp; 
    
    
public:
      Evaluacion();
      char *expresion ;
      ~Evaluacion();

      int Evaluar_ExpresionInfija(char *exp);
      int Evaluar_ExpresionInfija_2(char* exp);
      Cola ExpresionInfija_a_ExpresionPostfija (char* exp);
      int Evaluar_ExpresionPosfija (Cola c);
      bool es_Correcta(char* exp);
	char* completar_parentesis(char* expresion);
      Arbol arbolDesdePosfija(char * exp);
      int ResolverArbol(Arbol a);
      
      void SacarTamano(char* exp);
      bool es_Num(char c);
      bool es_Caracter(int v);
      bool es_Oper(int v);
      bool esNumero(int n);
      Lista expresionDesdeArbol(pNodoArbol a,pNodoArbol b,Lista lista);
      Cola colaDesdeArbol(pNodoArbol nodo, Cola cola);
    
};

#endif // EVALUACION_HPP
