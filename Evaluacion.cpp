#include "Evaluacion.hpp"
#include "Lista.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

Evaluacion::Evaluacion()
{
    expresion = " 2*5-1*2/11-9)";
}

void Evaluacion:: SacarTamano(char* exp){
    int i =0;
    while (exp[i] != '\0'){
        i +=1;
    }
    tam_exp = i;
}

bool Evaluacion:: es_Caracter(int v){
      return ((v == '(') || (v == ')') || (v=='*') || (v == '-') || (v == '+') || (v=='/'));
}

bool Evaluacion:: es_Num (char c){
      return ((c == '0') || (c=='1') || (c == '2') || (c == '3') || (c=='4') || (c == '5') || (c == '6') || (c=='7') || (c == '8') || (c== '9'));
}


            /*PRIMER EJERCICIO*/
/*_________________________________________________________*/
int Evaluacion:: Evaluar_ExpresionInfija(char* exp){
    Pila pila_car; Pila pila_num; Pila pila_NumAux; Pila pila_CarAux;
      SacarTamano(expresion);
      int n1; int n2; int res;
      if (tam_exp == 0){
            cout << "Error. No has escrito nada. ";
            return -1;
      }
	
	if (!es_Correcta(expresion)){
		cout << "La expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
		return -1;
	}
      
      if (exp[0] != '('){
            return -1;
      }
      
      for (int i =0; i <tam_exp; i++){
            if (exp[i] == '('){
                  pila_car.Apilar(exp[i]);
            }
            if((exp[i] =='+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/')){
                  pila_car.Apilar(exp[i]);
            }
            if(es_Num(exp[i])){
                  if ((es_Num(exp[i-1])) && (es_Num(exp[i]))){
                        int n1 = pila_num.Cima();
                        int n2 = n1*10 + exp[i] - 48;
                        pila_num.Desapilar();
                        pila_num.Apilar(n2);
                  }
            else{
                  int n = exp[i] -48;
                  pila_num.Apilar(n);
                  }
            }
        
            if(exp[i] == ')'){
                  pila_car.Apilar(exp[i]);
            }
            if (pila_car.Cima() == ')'){
                  pila_car.Desapilar();
                  n2 = pila_num.Cima();   pila_num.Desapilar();
                  n1 = pila_num.Cima();   pila_num.Desapilar();

                  switch (pila_car.Cima()){
                      case '*':
                          res = n1 * n2;
                          break;
                      case '+':
                          res = n1 + n2;
                          break;
                      case '-':
                          res = n1 - n2;
                          break;
                      case '/':
                          res = n1/n2;
                          break;
                      default:
                          break;
                  }         
   
                  pila_num.Apilar(res);
                  pila_car.Desapilar();pila_car.Desapilar();
            }
      }
      if (pila_car.es_Vacia()){
            return pila_num.Cima();
      }
      else{
            while (!pila_num.es_Vacia()){
                  int num = pila_num.Cima();
                  pila_NumAux.Apilar(num);
                  pila_num.Desapilar();
            }
            while (!pila_car.es_Vacia()){
                  int c = pila_car.Cima(); pila_car.Desapilar();
                  pila_CarAux.Apilar(c);
            }
            while (!pila_CarAux.es_Vacia()){
                  n1 = pila_NumAux.Cima();  pila_NumAux.Desapilar();
                  n2 = pila_NumAux.Cima();  pila_NumAux.Desapilar();
                  switch (pila_CarAux.Cima()){
                        case '*':
                              res = n1 * n2;
                              break;
                        case '+':
                              res = n1 + n2;
                              break;
                        case '-':
                              res = n1 - n2;
                              break;
                        case '/':
                              res = n1/n2;
                              break;
                        default:
                              break;
                    }
                    pila_CarAux.Desapilar();
                    pila_NumAux.Apilar(res);
            }
      }
      return pila_NumAux.Cima();
}



        /*SEGUNDO EJERCICIO*/
/*___________________________________________________________*/
int Evaluacion:: Evaluar_ExpresionInfija_2(char* exp){
      Pila pila_car; Pila pila_num; Pila pila_aux; Pila pila_CarAux;
      int n1; int n2; int res;
      
      char* expresion_nueva = new char;
      expresion_nueva[0] = '(';
      strcat(expresion_nueva, exp);
      strcat(expresion_nueva, ")");
      SacarTamano(expresion_nueva);
      cout << "Expresion concatenada: " << expresion_nueva << endl;
      
      if (tam_exp == 0){
            cout << "Error. No has escrito nada. ";
            return -1;
      }
	
	if (!es_Correcta(expresion)){
		cout << "La expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
		return -1;
	}
	
      for (int i =0; i <tam_exp; i++){
        
            if (expresion_nueva[i] == '('){
                  pila_car.Apilar(expresion_nueva[i]);
            }
            else if((expresion_nueva[i] =='+') || (expresion_nueva[i] == '-') || (expresion_nueva[i] == '*') || (expresion_nueva[i] == '/')){
                  pila_car.Apilar(expresion_nueva[i]);
            }
            else if(es_Num(expresion_nueva[i])){
                  if (i==0){
                        int n = expresion_nueva[i] -48;
                        pila_num.Apilar(n);
                  }
                  else{
                        if (es_Num(expresion_nueva[i-1])){
                              n1 = pila_num.Cima();
                              n2 = n1*10 + expresion_nueva[i] - 48;
                              pila_num.Desapilar();
                              pila_num.Apilar(n2);
                        }
                        else{
                              int n = expresion_nueva[i] -48;
                              pila_num.Apilar(n);
                        }
                  }
            }

            if(((pila_car.Cima() == '*') || (pila_car.Cima() == '/'))){
                  if ((expresion_nueva[i] == '*') || (expresion_nueva[i] == '/')){
                
                  }
                  else{
                        if (!es_Num(expresion_nueva[i+1])){
                              n2 = pila_num.Cima(); pila_num.Desapilar();
                              n1 = pila_num.Cima(); pila_num.Desapilar();
                              switch(pila_car.Cima()){
                                    case '*':
                                          res = n1*n2;
                                          break;
                                    case '/':
                                          res = n1/n2;
                                          break;
                                    default:
                                          break;
                              }
                              pila_car.Desapilar();
                              pila_num.Apilar(res);
                        }
                  }
            }
        
            if(expresion_nueva[i] == ')'){
                  pila_car.Apilar(expresion_nueva[i]);
            }

            if (expresion_nueva[i] == ')'){
                  pila_car.Desapilar();
                  n1 = pila_num.Cima(); pila_num.Desapilar();
                  int c; char c1;
                  pila_aux.Apilar(n1);
                  
                  while (pila_car.Cima() != '('){
                        c = pila_car.Cima(); pila_car.Desapilar();
                        pila_aux.Apilar(c);
                        n1 = pila_num.Cima(); pila_num.Desapilar();
                        pila_aux.Apilar(n1);
                  }
                  pila_car.Desapilar();
                  
                  while (!pila_aux.es_Vacia()){
                        n1 = pila_aux.Cima(); pila_aux.Desapilar();
                        if (pila_aux.es_Vacia()){
                              break;
                        }
                        else{
                              c1 = pila_aux.Cima(); pila_aux.Desapilar();
                              n2 = pila_aux.Cima(); pila_aux.Desapilar();
                              switch (c1){
                                    case '+':
                                          res = n1 + n2;
                                          break;
                                    case '-':
                                          res = n1 - n2;
                                          break;
                                    default:
                                          break;
                                    }
                              pila_aux.Apilar(res);
                        }
                  }
                  pila_num.Apilar(n1);
                  pila_aux.Desapilar();
            }
        /*FIN DEL BUCLE FOR PARA RECORRER LA EXPRESION*/
      }
        
      if (pila_car.es_Vacia()){
            return pila_num.Cima();
      }
      else{
            while (!pila_num.es_Vacia()){
                  int num = pila_num.Cima();
                  pila_aux.Apilar(num);
                  pila_num.Desapilar();
            }
            while (!pila_car.es_Vacia()){
                  int c = pila_car.Cima(); pila_car.Desapilar();
                  pila_CarAux.Apilar(c);
            }
            while (!pila_CarAux.es_Vacia()){
                  n1 = pila_aux.Cima();  pila_aux.Desapilar();
                  n2 = pila_aux.Cima();  pila_aux.Desapilar();
                  switch (pila_CarAux.Cima()){
                        case '*':
                              res = n1 * n2;
                              break;
                        case '+':
                              res = n1 + n2;
                              break;
                        case '-':
                              res = n1 - n2;
                              break;
                        case '/':
                              res = n1/n2;
                              break;
                        default:
                              break;
                  }
                  pila_CarAux.Desapilar();
                  pila_aux.Apilar(res);
            }
      }
      return pila_aux.Cima();
}


        /*TERCER EJERCICIO*/
/*___________________________________________________________*/

Cola Evaluacion:: ExpresionInfija_a_ExpresionPostfija (char* exp){
      Pila pila_car; Pila pila_num; Cola cola_exp; int n1; int n2;
      SacarTamano(expresion);
      if (tam_exp == 0){
            cout << "Error. No has escrito nada. ";
            return cola_exp;
      }
	if (!es_Correcta(expresion)){
		cout << "La expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
		return cola_exp;
	}

      for (int i =0; i <tam_exp; i++){
            if(es_Num(exp[i])){
                  if (es_Num(exp[i-1])){
                        n1 = pila_num.Cima();
                        n2 = n1*10 + exp[i] - 48;
                        pila_num.Desapilar();
                        pila_num.Apilar(n2);
                  }
                  else{
                        n1 = exp[i] -48;
                        pila_num.Apilar(n1);
                  }
            }
            if ((!es_Num(exp[i+1])) && (exp[i+1] != '(') && (exp[i+1] != ')')){
                  cola_exp.Encolar(pila_num.Cima());
                  if ((!pila_car.es_Vacia()) && ((pila_car.Cima() == '*') || (pila_car.Cima() == '/'))){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                  }
            }
            
            if (exp[i] == '('){
                  pila_car.Apilar(exp[i]);
            }
            
            if ((exp[i] == '*') || (exp[i] == '/')){
                  if (pila_car.es_Vacia()){
                        pila_car.Apilar(exp[i]);
                  }
                  else if (pila_car.Cima() == '('){
                        pila_car.Apilar(exp[i]);
                  }
                  else if ((pila_car.Cima() == '+') || (pila_car.Cima() == '-')){
                        pila_car.Apilar(exp[i]);
                  }
                  else if ((pila_car.Cima() == '*') || pila_car.Cima() == '/'){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                        pila_car.Apilar(exp[i]);
                  }
            }
            
            if ((exp[i] == '+') || (exp[i] == '-')){
                  if (pila_car.es_Vacia()){
                        pila_car.Apilar(exp[i]);
                  }
                  else if (pila_car.Cima() == '('){
                        pila_car.Apilar(exp[i]);
                  }
                  else if ((pila_car.Cima() == '+') || (pila_car.Cima() == '-')){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                        pila_car.Apilar(exp[i]);
                  }
                  else if ((pila_car.Cima() == '*') || pila_car.Cima() == '/'){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                        pila_car.Apilar(exp[i]);
                  }
            }
            
            if (exp[i] == ')'){
                  while(pila_car.Cima() != '('){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                  }
                  pila_car.Desapilar();
            }
      cout << "Pila: ";
      pila_car.Mostrar();
      cout << "Cola: ";
      cola_exp.Mostrar();
      }
      while (!pila_car.es_Vacia()){
          cola_exp.Encolar(pila_car.Cima());  
          pila_car.Desapilar();
      }
      cola_exp.Mostrar();
      return cola_exp;
}


        /*CUARTO EJERCICIO*/
/*___________________________________________________________*/

int Evaluacion :: Evaluar_ExpresionPosfija (Cola c1){
      Pila pila_aux;
      int res; int n1; int n2; char c;
      while (!c1.es_Vacia()){
            if (c1.Primero() == '+' ||c1.Primero() == '-' ||c1.Primero() == '*' || c1.Primero() == '/'){
                  c = c1.Primero();
                  c1.Desencolar();
                  n2 = pila_aux.Cima(); pila_aux.Desapilar();
                  n1 = pila_aux.Cima(); pila_aux.Desapilar();
                  switch (c){
                        case '+':
                              res = n1 + n2;
                              break;
                        case '-':
                              res = n1 - n2;
                              break;
                        case '*':
                              res = n1*n2;
                              break;
                        case '/':
                              res = n1 / n2;
                              break;
                        default: 
                              break;
                  }
                  pila_aux.Apilar(res);
            }
            else{
                  pila_aux.Apilar(c1.Primero());
                  c1.Desencolar();
            }
      }
      return pila_aux.Cima();
}


        /*QUINTO EJERCICIO*/
/*___________________________________________________________*/

bool Evaluacion:: es_Correcta(char* exp){
      int oper=0; int contador =0; Pila pila_num; Pila pila_car;
      int n1; int n2;
      SacarTamano(expresion);
      cout << expresion << endl;
      if (tam_exp == 0){
            cout << "Error. No has escrito nada. ";
            return false;
      }
      for (int i = 0; i < tam_exp ; i++){
            if(es_Num(exp[i])){
                  if (es_Num(exp[i-1])){
                        n1 = pila_num.Cima();
                        n2 = n1*10 + exp[i] - 48;
                        pila_num.Desapilar();
                        pila_num.Apilar(n2);
                  }
                  else{
                        n1 = exp[i] -48;
                        pila_num.Apilar(n1);
                  }
            }
            
            if (exp[i] == '('){
                  if (es_Num(exp[i-1])){
                        return false;
                  }
                  else{
                        pila_car.Apilar(exp[i]);
                  }
            }
            if (exp[i] == ')'){
                  if (exp[i-1] == '('){
                        return false;
                  }
                  else{
                        pila_car.Apilar(exp[i]);
                  }     
            }
            
            if ((exp[i] == ')') && (!pila_car.es_Vacia()) && (pila_car.Cima() == '(')){
                  pila_car.Desapilar(); pila_car.Desapilar();
            }
            
            
            if ((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '/') || (exp[i] == '*')){
                  if (exp[i+1] == ')'){
                        return false;
                  }
                  else{
                        oper +=1;
                  }
            }
            
      }
      
      while (!pila_num.es_Vacia()){
            contador +=1;
            pila_num.Desapilar();
      }
	  
	  if (!pila_car.es_Vacia()){
		  return false;
	  }
	  
      return (oper == contador -1);
}


        /*SEXTO EJERCICIO*/
/*___________________________________________________________*/

Lista Evaluacion::completar_parentesis(char* exp){
      Lista lista; Pila pila_num; Pila pila_car; int n1 =0; int n2 =0; int pos =0;
      SacarTamano(expresion);
      if (tam_exp == 0){
            cout << "Error. No has escrito nada. ";
            return lista;
      }
	if (!es_Correcta(expresion)){
		cout << "La expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
		return lista;
	}
      for (int i =0; i < tam_exp; i++){
            pos = i;
            if (exp[i] == '('){
                  lista.InsertarDer(exp[i]);
            }
		
		else if (exp[i] == ')'){
			lista.InsertarDer(exp[i]);
		}
            
            else if((exp[i] =='+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/')){
                  lista.InsertarDer(exp[i]);
                  pila_car.Apilar(exp[i]);
            }
            else if(es_Num(exp[i])){
                  if (i==0){
                        int n = exp[i] -48;
                        pila_num.Apilar(n);
                  }
                  else{
                        if (es_Num(exp[i-1])){
                              n1 = pila_num.Cima();
                              n2 = n1*10 + exp[i] - 48;
                              pila_num.Desapilar();
                              pila_num.Apilar(n2);
                        }

                        else{
                              int n = exp[i] -48;
                              pila_num.Apilar(n);
                        }
                  }
            }
            if ((!es_Num(exp[i+1])) &&(!pila_num.es_Vacia())){
                  lista.InsertarDer(pila_num.Cima());
                  pila_num.Desapilar();
            }
            
            
      }
      lista.Mostrar();
      for (int i =0;i < tam_exp; i++){
            pos =i;
            cout << "Iteracion de * y /" << i << endl;
            if ((lista.Ver(i) == '*') || (lista.Ver(i) == '/')){
                  if ((lista.Ver(i-1) == ')') && (lista.Ver(i+1) == '(')){
                        while (lista.Ver(pos -1) != '('){
                                    pos -=1;
                              }
                              lista.Insertar('(',pos);
                              pos=i;
                              tam_exp +=1;
                              
                        while (lista.Ver(pos+1) != ')'){
                              pos+=1;
                              }
                              lista.Insertar(')',pos+1);
                              i+=1;
                              tam_exp+=1;
                  }
                  else if (lista.Ver(i-1) == ')'){
                        while (lista.Ver(pos -1) != '('){
                                    pos -=1;
                              }
                              lista.Insertar('(',pos);
                              lista.Insertar(')',i+3);
                              i+=1;
                              tam_exp +=2;
                  }
                  else if ((!es_Caracter(lista.Ver(i-1))) && (!es_Caracter(lista.Ver(i+1)))) {
                        lista.Insertar('(',i-1);
                        lista.Insertar(')',i+3);
                        tam_exp +=2;
                        i+=1;
                  }
                  
            }
      cout << expresion << endl;
      lista.Mostrar();
      system("read -p 'Press Enter to continue...' var");
      system("clear");
      }
      
      for (int i =0; i< tam_exp; i++){
            pos =i;
            cout << "Iteracion de + y -: " << i << endl;
            if ((lista.Ver(i) == '+') || (lista.Ver(i) == '-')){
                  if ((lista.Ver(i-1) == ')') && (lista.Ver(i+1) == '(')){
                        while (lista.Ver(pos -1) != '('){
                                    pos -=1;
                              }
                              lista.Insertar('(',pos);
                              pos=i;
                              tam_exp +=1;
                              
                        while (lista.Ver(pos+1) != ')'){
                              pos+=1;
                              }
                              lista.Insertar(')',pos);
                              i+=1;
                              tam_exp+=1;
                  }
                  else if((lista.Ver(i-1) == ')') && (!es_Caracter(lista.Ver(i+1)))){
                        while (lista.Ver(pos -1) != '('){
                                    pos -=1;
                              }
                              lista.Insertar('(',pos);
                              lista.Insertar(')',i+3);
                              i+=1;
                              tam_exp+=2;
                  }
                  else if ((!es_Caracter(lista.Ver(i-1))) && (!es_Caracter(lista.Ver(i+1)))) {
                        lista.Insertar('(',i-1);
                        lista.Insertar(')',i+3);
                        tam_exp +=2;
                        i+=1;
                  }
            }
       
            cout << expresion << endl;
            lista.Mostrar();
            system("read -p 'Press Enter to continue...' var");
            system("clear");
      }
      
      cout << expresion << endl;
      lista.Mostrar();
      system("read -p 'Press Enter to continue...' var");
      system("clear");
}

Evaluacion::~Evaluacion()
{
}
