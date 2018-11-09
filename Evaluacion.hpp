#ifndef EVALUACION_HPP
#define EVALUACION_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include <stdio.h>
#include <string.h>
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
      Lista completar_parentesis(char* exp);
      void SacarTamano(char* exp);
      bool es_Num(char c);
      bool es_Caracter(int v);
    
};

#endif // EVALUACION_HPP
