#include <Evaluacion.hpp>
#include "Lista.hpp"
#include "Pila.hpp"
#include "Cola.hpp"

int main(int argc, char **argv)
{
    Lista l1;
    l1.InsertarIzq(8);
    l1.InsertarIzq(9);
    l1.InsertarIzq(1);
    l1.Insertar(20,0);
    l1.Mostrar();
    l1.verUltimo();
    l1.verPrimero();
    cout << l1.Ver(3) << endl;
    Evaluacion e1; 
//cout << "El resultado es: " << e1.Evaluar_ExpresionInfija(e1.expresion);
//cout << "El resultado es: " << e1.expresion << " ==>" << e1.Evaluar_ExpresionInfija_2(e1.expresion) << "\n";
//cout << "Expresion: " << e1.expresion << " \n";
//Cola c = e1.ExpresionInfija_a_ExpresionPostfija(e1.expresion);
//cout << "El resultado es: " << e1.Evaluar_ExpresionPosfija(c) << " \n";
//cout << "El resulado de correcto es: " << e1.es_Correcta(e1.expresion) << endl;
}
