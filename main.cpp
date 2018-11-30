#include <Evaluacion.hpp>
#include <stdlib.h>


int main(int argc, char** argv)
{
      Arbol a;
      a.insertarNodo(18);
      a.insertarNodo(9);
      a.insertarNodo(6);
      a.insertarNodo(20);
      a.insertarNodo(1);
      a.insertarNodo(10);
      a.insertarNodo(81);
      a.insertarNodo(7);
      a.insertarNodo(16);
      a.insertarNodo('*');
      a.borrarNodo(18);
      a.borrarNodo(20);
      
      //a.insertarNodoDerecha(5,a.getRaiz()->derecha->derecha);

      
      
      a.inOrden(a.getRaiz());
      cout << "\nRaiz " << a.getValorRaiz() << endl;
      cout << "¿Es raiz? ==> " << a.esRaiz(a.getRaiz()) << endl;
      cout << "¿Es vacio? ==> " << a.esArbolVacio() << endl;;
      cout << "Altura ==> " << a.getAlturaArbol(a.getRaiz()) << endl;
      a.printTree(a.getRaiz(), a.getAlturaArbol(a.getRaiz()));
      Evaluacion e1;/*char expresion[40] = ""; Cola c; Lista list; char opcion;  bool res; char expresion[40] = "";
      do{
            cout << "\n\t------------------------------------------------\n";
            cout << "\t                       MENU                       \n";
            cout << "\t------------------------------------------------\n";

            cout << "\n\tA. Evaluar una expresion infija. \n";
            cout << "\tB. Evaluar una expresion infija 2.\n";
            cout << "\tC. Expresion infija a expresion postfija.\n";
            cout << "\tD. Evaluar una expresion posfija.\n";
            cout << "\tE. Evaluar si una expresion infija es correcta.\n";
            cout << "\tF. Completar parentesis de una expresion infija.\n\n";

            cout << "\tS.Salir del programa.\n\n";
            cout << "\tIndique la opcion deseada: ";
            cin >> opcion;
            system("cls");
            switch(opcion){  
                  case 'A':
                        cout << "\n\tIntroduzca una expresion (sin espacios): ";  //EXPRESION ((2*5)-(6*1))/(11-9)
                        cin >> expresion;
                        e1.expresion = expresion;
                        cout << "\n\tExpresion: " << e1.expresion << endl;
                        cout << "\n\tEl resultado es: " << e1.Evaluar_ExpresionInfija(e1.expresion)<< endl;
                        break;
                  case 'B':
                        cout << "\n\tIntroduzca una expresion (sin espacios y con parentesis al principio y al final) : ";  // EXPRESION (2*5-6*1)/(11-9)
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
                        Cola c = e1.ExpresionInfija_a_ExpresionPostfija(e1.expresion);
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
                        list = e1.Completar_Parentesis(e1.expresion);
                        list.Mostrar();
                        break;
                  case 'S':
                        cout << "\n\tSaliendo del programa..." << endl;
                        break;
                  default:
                        cout << "\n\tOpcion incorrecta!" << endl;
                  }
            }while(opcion != 'S');
            
            system("pause");
            system("cls");*/
            
            
            e1.arbolDesdePosfija("((((2*5)-(1*2))/((11-9)-(6-5))");
return 0;
}
