#include <Evaluacion.hpp>
#include <stdlib.h>


int main(int argc, char** argv)
{

      Arbol a ;Evaluacion e1;char expresion[40] = ""; Cola c; char opcion;  bool res; char* exp_fin;
      do{
            cout << "\n\t------------------------------------------------\n";
            cout << "\t                       MENU                       \n";
            cout << "\t------------------------------------------------\n";

            cout << "\n\tA. Evaluar una expresion infija. \n";
            cout << "\tB. Evaluar una expresion infija 2.\n";
            cout << "\tC. Expresion infija a expresion postfija.\n";
            cout << "\tD. Evaluar una expresion posfija.\n";
            cout << "\tE. Evaluar si una expresion infija es correcta.\n";
            cout << "\tF. Completar parentesis de una expresion infija.\n";
            cout << "\tG. Crear un arbol a partir de una expresion postfija.\n";
            cout << "\tH. Completar la expresion del arbol con parentesis y mostrar su resultado. \n";
            cout << "\tI. Crear un arbol de expresiones ordenado segun su resultado.\n";
            cout << "\tJ. Mostrar el arbol del apartado anterior en inorden. \n\n";
            cout << "\tS.Salir del programa.\n\n";
            cout << "\tIndique la opcion deseada: ";
            cin >> opcion;
            system("cls");
            switch(opcion){  
                  case 'A':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";  //EXPRESION (((2*5)-(6*1))/(11-9))
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        cout << "\n\tEl resultado es: " << e1.Evaluar_ExpresionInfija(e1.expresion)<< endl;
                        break;
                  case 'B':
                        cout << "\n\tIntroduzca una expresion (sin espacios y con parentesis al principio y al final) : ";  // (2*5-6*1)/(11-9)
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        cout << "\n\tEl resultado es: " << e1.Evaluar_ExpresionInfija_2(e1.expresion) << endl;
                        break;
                  case 'C':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";  // EXPRESION ((2*5)-(6*1))/(11-9)
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        c = e1.ExpresionInfija_a_ExpresionPostfija(e1.expresion);
                        break;
                  case 'D':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        c = e1.ExpresionInfija_a_ExpresionPostfija(e1.expresion);
                        cout << "\n\tEl resultado es: " << e1.Evaluar_ExpresionPosfija(c) << endl;
                        break;
                  case 'E':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";   // EXPRESION ((2*5)-(6*1))/(11-9)
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        res = e1.es_Correcta(e1.expresion);
                        if (res){
                              cout << "\n\tLa expresion es correcta." << endl;
                        }
                        else{
                              cout << "\n\tLa expresion es incorrecta." << endl;
                        }
                        break;
                  case 'F':                                                         // EXPRESION (2*5-6*1)/(11-9)
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";    
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        exp_fin = e1.completar_parentesis(e1.expresion);
                        break;
                  case 'G':                                                         //(((9*2)-(2*3))-6) == (((2*5)-(1*2))/(11-9)) == (6-((9*2)-(2*3)))
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";    
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        a = e1.arbolDesdePosfija(e1.expresion);
                        a.printTree(a.getRaiz(),a.getAlturaArbol(a.getRaiz()));
                        break;
                  case 'H':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";    
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        a = e1.arbolDesdePosfija(e1.expresion);
                        e1.ResolverArbol(a);
                        break;
                  case 'I':
                        a = e1.arbolDeExpresiones();
                        a.printTree(a.getRaiz(),a.getAlturaArbol(a.getRaiz()));
                        break;
                  case 'J':
                        e1.MostrarExpresionesArbol(a);
                        break;
                  case 'S':
                        cout << "\n\tSaliendo del programa..." << endl;
                        break;
                  default:
                        cout << "\n\tOpcion incorrecta!" << endl;
                        break;
                  }
            }while(opcion != 'S');
            
            system("pause");
            system("cls");
return 0;
}
