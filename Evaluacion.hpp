#ifndef EVALUACION_HPP
#define EVALUACION_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include <stdio.h>
#include <string.h>
#include <iostream>

class Evaluacion
{
private:
    int tam_exp; 
    
public:
      Evaluacion();
      const char *expresion ;
      ~Evaluacion();

      int Evaluar_ExpresionInfija(const char *exp);
      int Evaluar_ExpresionInfija_2(const char* exp);
      Cola ExpresionInfija_a_ExpresionPostfija (const char* exp);
      int Evaluar_ExpresionPosfija (Cola c);
      bool es_Correcta(const char* exp);
      void SacarTamano(const char* exp);
      bool es_Num(char c);
    
};

#endif // EVALUACION_HPP
