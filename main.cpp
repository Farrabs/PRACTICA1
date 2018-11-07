#include <Evaluacion.hpp>
#include "Lista.hpp"
#include "Pila.hpp"
#include "Cola.hpp"

int main(int argc, char **argv)
{
    Evaluacion e1;
//cout << "El resultado es: " << e1.Evaluar_ExpresionInfija(e1.expresion);
cout << "El resultado es: " << e1.expresion << " ==>" << e1.Evaluar_ExpresionInfija_2(e1.expresion);
//cout << "Expresion: " << e1.expresion << " \n";
//Cola c = e1.ExpresionInfija_a_ExpresionPostfija(e1.expresion);

//cout << "El resultado es: " << e1.Evaluar_ExpresionPosfija(c);
}
