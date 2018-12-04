#include "Evaluacion.hpp"
#include "Lista.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include "Arbol.hpp"
#include "PilaArbol.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <math.h>

Evaluacion::Evaluacion()
{
    expresion = "";
}

void Evaluacion:: SacarTamano(char* exp){
    int i =0;
    while (exp[i] != '\0'){
        i +=1;
    }
    tam_exp = i;
}

bool Evaluacion::esNumero(int n){
    if(n==40)return false;
    if(n==41)return false;
    if(n==42)return false;
    if(n==43)return false;
    if(n==45)return false;
    if(n==47)return false;
    else return true;
}

bool Evaluacion:: es_Caracter(int v){
      return ((v == '(') || (v == ')') || (v=='*') || (v == '-') || (v == '+') || (v=='/'));
}

bool Evaluacion:: es_Num (char c){
      return ((c == '0') || (c=='1') || (c == '2') || (c == '3') || (c=='4') || (c == '5') || (c == '6') || (c=='7') || (c == '8') || (c== '9'));
}

bool Evaluacion:: es_Oper(int v){
      return ((v=='*') || (v == '-') || (v == '+') || (v=='/'));
}

Lista Evaluacion:: expresionDesdeArbol(pNodoArbol nodo,pNodoArbol nodoB, Lista lista){
      if (nodo!= NULL){
            if (!(nodo->izquierda==NULL && nodo->derecha ==NULL)){
                        lista.InsertarDer('(');
            }
            lista = expresionDesdeArbol(nodo->izquierda,nodoB ,lista);
            
            lista.InsertarDer(nodo->valor);
            lista = expresionDesdeArbol(nodo->derecha ,nodoB,lista);
            if (!(nodo->izquierda==NULL && nodo->derecha ==NULL)){
                  lista.InsertarDer(')');
            }
            lista.Mostrar();
      }
      return lista;
}

Cola Evaluacion:: colaDesdeArbol(pNodoArbol nodo, Cola cola){
      if (nodo!= NULL){
            cola = colaDesdeArbol (nodo->izquierda, cola);
            cola = colaDesdeArbol (nodo->derecha, cola);
            cola.Encolar(nodo->valor);
      }
      return cola;
}



            /*PRIMER EJERCICIO*/
/*_________________________________________________________*/
int Evaluacion:: Evaluar_ExpresionInfija(char* exp){
    Pila pila_car; Pila pila_num; Pila pila_NumAux; Pila pila_CarAux;
      SacarTamano(expresion);
      int n1; int n2; int res;
      if (tam_exp == 0){
            cout << "\n\tError. No has escrito nada. ";
            return -1;
      }
	
	if (!es_Correcta(expresion)){
		cout << "\n\tLa expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
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
      SacarTamano(expresion);
      if (tam_exp == 0){
            cout << "\n\tError. No has escrito nada. ";
            return -1;
      }
	
	if (!es_Correcta(expresion)){
		cout << "\n\tLa expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
		return -1;
	}
	
      for (int i =0; i< tam_exp; i++){
        
            if (exp[i] == '('){
                  pila_car.Apilar(exp[i]);
            }
            else if((exp[i] =='+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/')){
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

            if(((pila_car.Cima() == '*') || (pila_car.Cima() == '/'))){
                  if ((exp[i] == '*') || (exp[i] == '/')){
                
                  }
                  else{
                        if (!es_Num(exp[i+1])){
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
        
            if(exp[i] == ')'){
                  pila_car.Apilar(exp[i]);
            }

            if (exp[i] == ')'){
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
            cout << "\n\t" << expresion;
            cout << "\nPilaNum: " ;
            pila_num.Mostrar();
            cout << "\nPilaCar: " ;
            pila_car.Mostrar();
            cout << "\nPilaAux:" ;
            pila_aux.Mostrar();
            system("pause");
            system("cls");
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

Cola Evaluacion:: ExpresionInfija_a_ExpresionPostfija (char* exp){  //(2+7*(7-2)-9)
      Pila pila_car; Pila pila_num; Cola cola_exp; int n1; int n2;
      SacarTamano(expresion);
      if (tam_exp == 0){
            cout << "\n\tError. No has escrito nada. ";
            return cola_exp;
      }
	if (!es_Correcta(expresion)){
		cout << "\n\tLa expresion introducida no es correcta y no se pueden realizar las acciones correspondientes." << endl;
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
            if ((!es_Num(exp[i+1])) && (es_Num(exp[i]))){
                  cola_exp.Encolar(pila_num.Desapilar());
            }
            
            if ((!es_Num(exp[i+1])) && (exp[i+1] != '(') && (exp[i+1] != ')')){
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
            
            else if ((exp[i] == '+') || (exp[i] == '-')){
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
                        while ((!pila_car.es_Vacia()) && (pila_car.Cima() != '(')){
                              cola_exp.Encolar(pila_car.Cima());
                              pila_car.Desapilar();
                              
                        }
                        pila_car.Apilar(exp[i]);
                  }
            }
            
            else if (exp[i] == ')'){
                  while(pila_car.Cima() != '('){
                        cola_exp.Encolar(pila_car.Cima());
                        pila_car.Desapilar();
                  }
                  pila_car.Desapilar();
            }
            cout<<"Pulse una tecla para siguiente iteracion\n";
            cin.get();
            system("clear");
            
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
      int oper=0; int contador =0; Pila pila_num; Pila pila_car; Lista lista;
      int n1; int n2;
      SacarTamano(expresion);
      if (tam_exp == 0){
            cout << "\n\tError. No has escrito nada. ";
            return false;
      }
      
      for (int i =0; i < tam_exp; i++){
            if (exp[i] == '('){
                  lista.InsertarDer(exp[i]);
            }
		
		else if (exp[i] == ')'){
			lista.InsertarDer(exp[i]);
		}
            
            else if((exp[i] =='+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/')){
                  lista.InsertarDer(exp[i]);
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
            if ((es_Num(exp[i])) && (!es_Num(exp[i+1]))){
                  lista.InsertarDer(pila_num.Cima());
            }   
      }
      
      if (lista.Ver(0)== '('){
            if (lista.Ver(lista.Longitud()-1) != ')'){ return false;} 
      }
      if (es_Oper(lista.Ver(0))){ return false; }
      
      if (es_Oper(lista.Ver(lista.Longitud()-1))){ return false;}
 
      for (int i = 0;   i < lista.Longitud() ; i++){
            if (lista.Ver(i) == '('){
                  if (es_Oper(lista.Ver(i+1))){
                        return false;                  }
                  else if(lista.Ver(i+1) == ')'){
                        return false;
                  }
                  
                  else{
                        pila_car.Apilar(lista.Ver(i));
                  }
            }
            
            else if ((lista.Ver(i) == ')')) {
                  if(!pila_car.es_Vacia()){
                        if(pila_car.Cima() == '('){ pila_car.Desapilar();}
                  }
                  else{
                        return false;
                  }
            }
            
            
            else if ((lista.Ver(i) == '+') || (lista.Ver(i) == '-') || (lista.Ver(i) == '/') || (lista.Ver(i) == '*')){
                  if (lista.Ver(i+1) == ')'){
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
	  
      return (oper == contador -1) ;
}


        /*SEXTO EJERCICIO*/
/*___________________________________________________________*/  //(2*5-1*2)/(11-9)

char* Evaluacion::completar_parentesis(char* expresion){
    Lista lista; int i,j,k,cont; int a,b; size_t size; Pila pilaNum; bool anteriorNum;
    size = strlen(expresion);
    for(i=0;i<size;i++){
	cout<<"--Completar Parentesis--\n";
	cout<<"----Iteracion "<<i+1<<" ----\n";
        if(isdigit(expresion[i])){
            if(anteriorNum){
                a = pilaNum.Cima();
                pilaNum.Desapilar();
                b = a*10 + expresion[i]-48;
                pilaNum.Apilar(b);
            }
            else{
            pilaNum.Apilar(expresion[i]-48);
            }
            anteriorNum = true;
        }
        else{
            if(!pilaNum.es_Vacia()){
                lista.InsertarDer(pilaNum.Cima());  
                pilaNum.Desapilar();
            }
            lista.InsertarDer(expresion[i]);
            anteriorNum = false;
        }
    }
    i=0;
    if(lista.Ver(0)!=40){
        lista.InsertarDer(41);
        lista.InsertarIzq(40);
    }
    while(!lista.esUltimo(i)){ 
	cout<<"--Completar Parentesis--\n";
	cout<<"----Iteracion "<<i+1<<" ----\n";
        if((lista.Ver(i)==42 || lista.Ver(i)==47)){
            if(esNumero(lista.Ver(i+1)) && esNumero(lista.Ver(i-1))){
                if(lista.Ver(i+2)!=41 || lista.Ver(i-2)!=40){
                    cout<<"1"<<"\n";
                    if((i-2)<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,i-1);i++;}
                    if((i+2)>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,i+2);}
                }
            }
            else if(esNumero(lista.Ver(i-1)) && lista.Ver(i+1)==40){
                if(lista.Ver(i-2)!=40){
                    j=i;
                    cont=0;
                    while(j!=lista.Longitud()){
                        if(lista.Ver(j)==40)cont++;
                        if(lista.Ver(j)==41){
                            if(cont==0) break;
                            else cont--;
                        }
                        j++;
                    }
                    j++;
                    if((i-2)<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,i-1);i++;}
                    if(j>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,j);}
                }
            }
            else if(esNumero(lista.Ver(i+1)) && lista.Ver(i-1)==41){   
                int pos;
                if((i+2)>=lista.Longitud()-1)pos=lista.Longitud()-1;
                else pos = i+2;
                if(lista.Ver(pos)!=41){
                    j=i;
                    cont=0;
                    while(j!=0){
                        if(lista.Ver(j)==41)cont++;
                        if(lista.Ver(j)==40){
                            if(cont==0) break;
                            else cont--;
                        }
                        j--;
                    }
                    if((i+2)>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,i+2);}
                    if(j<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,j);i++;}
                }
            }
            else if(lista.Ver(i+1)==40 && lista.Ver(i-1)==41){
                  
                j=i;
                cont=0;
                while(j!=lista.Longitud()){
                    if(lista.Ver(j)==40)cont++;
                    if(lista.Ver(j)==41){
                          if(cont==0) break;
                          else cont--;
                    }
                    j++;
                }
                j++;

                k=i;
                cont=0;
                while(k!=0){
                    if(lista.Ver(k)==41)cont++;
                    if(lista.Ver(k)==40){
                        if(cont==0) break;
                        else cont--;
                    }
                    k--;
                }
                if(j>=lista.Longitud() && k<=0){
                    lista.InsertarDer(41);
                    lista.InsertarIzq(40);
                    i++;
                }
                else{
                    if(j>=lista.Longitud())j=lista.Longitud();
                    if(k<=0)k=0;
                    if(lista.Ver(k)!=40 || lista.Ver(j-1)!=41){
                        lista.Insertar(41,j);
                        lista.Insertar(40,k);
                        i++;
                    }
                }
            }
        }
        i++;
	lista.Mostrar();
	cout<<"Pulse una tecla para siguiente iteracion\n";
    	cin.get();
    	system("clear");
    }
    lista.Mostrar();
    i=0;
    while(!lista.esUltimo(i)){ 
	cout<<"--Completar Parentesis--\n";
	cout<<"----Iteracion "<<i+1<<" ----\n";
        if((lista.Ver(i)==43 || lista.Ver(i)==45)){
            if(esNumero(lista.Ver(i+1)) && esNumero(lista.Ver(i-1))){
                if(lista.Ver(i+2)!=41 || lista.Ver(i-2)!=40){
                    if((i-2)<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,i-1);i++;}
                    if((i+2)>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,i+2);}
                }
            }
            else if(esNumero(lista.Ver(i-1)) && lista.Ver(i+1)==40){
                if(lista.Ver(i-2)!=40){
                    j=i;
                    cont=0;
                    while(j!=lista.Longitud()){
                        if(lista.Ver(j)==40)cont++;
                        if(lista.Ver(j)==41){
                            if(cont==0) break;
                            else cont--;
                        }
                        j++;
                    }
                    j++;
                    if((i-2)<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,i-1);i++;}
                    if(j>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,j);}
                }
            }
            else if(esNumero(lista.Ver(i+1)) && lista.Ver(i-1)==41){
                if((i+2)>=lista.Longitud() || lista.Ver(i+2)!=41){
                    j=i;
                    cont=0;
                    while(j!=0){
                        if(lista.Ver(j)==41)cont++;
                        if(lista.Ver(j)==40){
                            if(cont==0) break;
                            else cont--;
                        }
                        j--;
                    }
                    if((i+2)>=lista.Longitud()-1){lista.InsertarDer(41);}
                    else{lista.Insertar(41,i+2);}
                    if(j<=0){lista.Insertar(40,0);i++;}
                    else{lista.Insertar(40,j);i++;}
                }
            }
            else if(lista.Ver(i+1)==40 && lista.Ver(i-1)==41){
                  
                j=i;
                cont=0;
                while(j!=lista.Longitud()){
                    if(lista.Ver(j)==40)cont++;
                    if(lista.Ver(j)==41){
                          if(cont==0) break;
                          else cont--;
                    }
                    j++;
                }
                j++;

                k=i;
                cont=0;
                while(k!=0){
                    if(lista.Ver(k)==41)cont++;
                    if(lista.Ver(k)==40){
                        if(cont==0) break;
                        else cont--;
                    }
                    k--;
                }
      
                if(j>=lista.Longitud() && k<=0){
                    lista.InsertarDer(41);
                    lista.InsertarIzq(40);
                    i++;
                }
                else{
                    if(j>=lista.Longitud())j=lista.Longitud();
                    if(k<=0)k=0;
                    if(lista.Ver(k)!=40 || lista.Ver(j-1)!=41){
                        lista.Insertar(41,j);
                        lista.Insertar(40,k);
                        i++;
                    }
                }
            }
        }
        i++;
	lista.Mostrar();
	cout<<"Pulse una tecla para siguiente iteracion\n";
    	cin.get();
    	system("clear");
    }
    char expresionCompleta[lista.Longitud()];
    for(i=0;i<lista.Longitud();i++){ 
            expresionCompleta[i] = lista.Ver(i);
    }
    cout<<expresionCompleta;
    lista.Mostrar();
    return expresionCompleta;
}


        /*SEPTIMO EJERCICIO*/
/*___________________________________________________________*/

Arbol Evaluacion:: arbolDesdePosfija(char * exp){
      Cola cola; Pila pila; PilaArbol pilaArbol; Lista lista; int n; int n1;int n2; Arbol tree; 
      expresion = exp;
      if (!es_Correcta(exp)){
            cout << "Error. Expresion mal introducida." << endl;
            return tree;
      }
      cola = ExpresionInfija_a_ExpresionPostfija(exp);
      while (!cola.es_Vacia()){
            n = cola.Desencolar();
            lista.InsertarDer(n);
      }
      lista.Mostrar();
      
      system("pause");
      system("cls");
      for (int i =0; i < lista.Longitud(); i++){
            n = lista.Ver(i);
            if (!es_Oper(n)){
                  pila.Apilar(n);
            }
            else if(es_Oper(n) && (es_Oper(lista.Ver(i-1)))){
                  Arbol treeAux;
                  treeAux.insertarNodo(n);
                  pNodoArbol ar_der = pilaArbol.DesapilarArbol(); //(((9*2)-(2*3))-6) ===== (((2*5)-(1*2))/(11-9)) == (6-((9*2)-(2*3)))
                  treeAux.insertarArbolDerecha(ar_der,treeAux.getRaiz());
                  if (!pilaArbol.es_Vacia()){
                        pNodoArbol ar_izq = pilaArbol.DesapilarArbol();
                        treeAux.insertarArbolIzquierda(ar_izq,treeAux.getRaiz());
                  }
                  else{
                        n1 = pila.Desapilar();
                        treeAux.insertarNodoIzquierda(n1,treeAux.getRaiz());
                  }
                  pilaArbol.ApilarArbol(treeAux.getRaiz());
                  
            }
            
            else if(es_Oper(n) && esNumero(lista.Ver(i-1)) && es_Oper(lista.Ver(i-2))){
                  Arbol treeAux;
                  treeAux.insertarNodo(n);
                  treeAux.insertarNodoDerecha(lista.Ver(i-1),treeAux.getRaiz());
                  pila.Desapilar();
                  pNodoArbol ar_izq = pilaArbol.DesapilarArbol();
                  treeAux.insertarArbolIzquierda(ar_izq,treeAux.getRaiz());
                  pilaArbol.ApilarArbol(treeAux.getRaiz());
            }
            
            else if(es_Oper(n)){
                  Arbol treeAux;
                  treeAux.insertarNodo(n);
                  n1 = pila.Desapilar();
                  
                  if (!pila.es_Vacia()){
                        n2 = pila.Desapilar();
                        treeAux.insertarNodoIzquierda(n2,treeAux.getRaiz());
                  }
                  treeAux.insertarNodoDerecha(n1,treeAux.getRaiz());
                  
                  treeAux.printTree(treeAux.getRaiz(),treeAux.getAlturaArbol(treeAux.getRaiz()));
                  pilaArbol.ApilarArbol(treeAux.getRaiz());
                  
            }
            if (!pilaArbol.es_Vacia()){
                  tree.printTree(pilaArbol.Cima(),tree.getAlturaArbol(pilaArbol.Cima()));
            }
            cout << "pila arbol" ; pilaArbol.Mostrar();
            
            cout << "\n\n\n";
            
            
            system("pause");
            system("cls");
      }
      
      pNodoArbol aux = pilaArbol.DesapilarArbol();
      tree.insertarNodo(aux->valor);
      tree.getRaiz()->derecha = aux->derecha;
      tree.getRaiz()->izquierda = aux->izquierda;
      tree.printTree(tree.getRaiz(),tree.getAlturaArbol(tree.getRaiz()));
      return tree;     
}


        /*OCTAVO EJERCICIO*/
/*___________________________________________________________*/

int Evaluacion:: ResolverArbol(Arbol a){
      Lista lista; Cola cola;
      lista = expresionDesdeArbol(a.getRaiz(),a.getRaiz(), lista);  
      lista.Mostrar();
      cout<<"\tMOSTRAR COLA\n";
    	cin.get();
    	system("clear");
      
      cola = colaDesdeArbol(a.getRaiz(),cola);
      cola.Mostrar();
      int resultado = Evaluar_ExpresionPosfija(cola);
      cout << "\n";
      a.printTree(a.getRaiz(),a.getAlturaArbol(a.getRaiz()));
      cout << "\n\tLa expresion final es ==> " ;
      lista.Mostrar();
      cout << "\t\nResultado: " << resultado << endl;
      return resultado;
      
}


        /*NOVENO EJERCICIO*/
/*___________________________________________________________*/

Arbol Evaluacion:: arbolDeExpresiones(){
      Arbol tree;
      char Expresiones[8][30] = {{"((2*5)-(1*2))"},{"(4*2)"},{"((2*5)+1)"},{"((2*5)-(1*4))"},{"(((2*5)-(1*2))/(11-9))"},{"(8*4)"},{"((6*4)-(7*3))"},{"((5*4)/2)"}};
      for (int i =0; i< 8; i++){
            expresion = Expresiones[i];
            int n = Evaluar_ExpresionInfija(Expresiones[i]);
            tree.insertarNodoExpresion(n,expresion);
      }
      tree.printTree(tree.getRaiz(),tree.getAlturaArbol(tree.getRaiz()));
      cout << "\n\tInorden con expresiones\n\t";
      tree.inOrdenExp(tree.getRaiz());
      return tree;
}


        /*DECIMO EJERCICIO*/
/*___________________________________________________________*/
void Evaluacion:: MostrarExpresionesArbol(Arbol tree){
      tree = arbolDeExpresiones();
      cout << "\n\tInorden con resultados\n\t";
      tree.inOrden(tree.getRaiz());
      
      return;
}


        /*UNDECIMO EJERCICIO*/
/*___________________________________________________________*/
void Evaluacion:: MostrarInformacionArbol(char *exp){
      Arbol tree = arbolDesdePosfija(exp);
      cout << "\tALTURA:\n\t=>" << tree.getAlturaArbol(tree.getRaiz());
      cout << "\n\tNUMERO DE HOJAS:\n\t=>" << tree.NumeroHojas(tree.getRaiz());
      cout << "\n\tNUMERO DE NODOS:\n\t=>" << tree.NumeroNodos(tree.getRaiz());
      cout << "\n\tNUMERO DE NODOS INTERNOS:\n\t=>" << tree.NumeroNodos(tree.getRaiz()) - tree.NumeroHojas(tree.getRaiz());
      int resultado = pow(2,tree.getAlturaArbol(tree.getRaiz()));
      cout << "\n\t¿Esta el arbol lleno?\n\t=>";
      if (resultado == tree.NumeroHojas(tree.getRaiz())){
            cout << "El arbol si esta lleno.\n";
      }
      else{
            cout << "El arbol no esta lleno.\n";
      }
}



Evaluacion::~Evaluacion()
{
}
