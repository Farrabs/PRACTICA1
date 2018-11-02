#include "Evaluacion.hpp"
#include "Nodo.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

Evaluacion::Evaluacion()
{
    expresion = "(2+2)+(3+3)-(4+4)";
}

void Evaluacion:: SacarTamano(const char* exp){
    int i =0;
    while (exp[i] != '\0'){
        i +=1;
    }
    tam_exp = i;
}

bool Evaluacion:: es_Num (char c){
    return ((c == '0') || (c=='1') || (c == '2') || (c == '3') || (c=='4') || (c == '5') || (c == '6') || (c=='7') || (c == '8') || (c== '9'));
}


            /*PRIMER EJERCICIO*/
/*_________________________________________________________*/
int Evaluacion:: Evaluar_ExpresionInfija(const char* exp){
    Pila pila_car; Pila pila_num; Pila pila_aux;
    SacarTamano(expresion);
    int n1; int n2; int res;
    if (tam_exp == 0){
        cout << "Error. No has escrito nada. ";
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
            n2 = pila_num.Cima();
            pila_num.Desapilar();
            n1 = pila_num.Cima();
            pila_num.Desapilar();
            pila_car.Desapilar();
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
        cout << "Pila de caracteres: ";
        pila_car.Mostrar();
        cout << "Pila de numeros: " ;
        pila_num.Mostrar();
        system("pause");
        system("cls");
    }
    if (pila_car.es_Vacia()){
        return pila_num.Cima();
    }
    else{
            while (!pila_num.es_Vacia()){
                int num = pila_num.Cima();
                pila_aux.Apilar(num);
                pila_num.Desapilar();
                cout <<  "Expresion a resolver: "<<expresion  << endl;
                cout << "Pila de caracteres: ";
                pila_car.Mostrar();
                cout << "Pila de numeros: " ;
                pila_num.Mostrar();
                cout << "Pila auxiliar: ";
                pila_aux.Mostrar();
                system("pause");
                system("cls");
            }
            while (!pila_car.es_Vacia()){
                if (pila_car.es_Vacia()){
                    return pila_aux.Cima();
                }
                
                else{
                    n1 = pila_aux.Cima();  pila_aux.Desapilar();
                    n2 = pila_aux.Cima();  pila_aux.Desapilar();
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
                    pila_car.Desapilar();
                    pila_aux.Apilar(res);
  
                }

            }
        }
    return pila_aux.Cima();
}



        /*SEGUNDO EJERCICIO*/
/*___________________________________________________________*/
int Evaluacion:: Evaluar_ExpresionInfija_2(const char* expresion_nueva){
    Pila pila_car; Pila pila_num; Pila pila_aux;
    int n1; int n2; int res;
    SacarTamano(expresion);
   /* char* expresion_nueva = new char[tam_exp +2];
    expresion_nueva[0] = '(';
    strcat(expresion_nueva, exp);
    strcat(expresion_nueva, ")");
    tam_exp +=2;
    expresion = expresion_nueva;
    cout << "Expresion concatenada: " << expresion_nueva << endl;*/
    if (tam_exp == 0){
        cout << "Error. No has escrito nada. ";
        return -1;
    }
    for (int i =0; i <tam_exp+1; i++){
        
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
                    cout <<  "PASO 1:   Expresion a resolver: "<<expresion  << endl;
                    cout << "Pila de caracteres: ";
                    pila_car.Mostrar();
                    cout << "Pila de numeros: " ;
                    pila_num.Mostrar();
                    cout << "Pila auxiliar: ";
                    pila_aux.Mostrar();
                    system("pause");
                    system("cls");
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
        cout <<  "PASO 3:   Expresion a resolver: "<<expresion  << endl;
        cout << "Pila de caracteres: ";
        pila_car.Mostrar();
        cout << "Pila de numeros: " ;
        pila_num.Mostrar();
        system("pause");
        system("cls");
        }
        if (pila_car.es_Vacia()){
            return pila_num.Cima();
        }
        else{
            while (!pila_num.es_Vacia()){
                int num = pila_num.Cima();
                pila_aux.Apilar(num);
                pila_num.Desapilar();
                cout <<  "Expresion a resolver: "<<expresion  << endl;
                cout << "Pila de caracteres: ";
                pila_car.Mostrar();
                cout << "Pila de numeros: " ;
                pila_num.Mostrar();
                cout << "Pila auxiliar: ";
                pila_aux.Mostrar();
                system("pause");
                system("cls");
            }
            while (!pila_car.es_Vacia()){
                    n1 = pila_aux.Cima();  pila_aux.Desapilar();
                    n2 = pila_aux.Cima();  pila_aux.Desapilar();
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
                    pila_car.Desapilar();
                    pila_aux.Apilar(res);
                }
                cout <<  "Expresion a resolver: "<<expresion  << endl;
                cout << "Pila de caracteres: ";
                pila_car.Mostrar();
                cout << "Pila de numeros: " ;
                pila_num.Mostrar();
                cout << "Pila auxiliar: ";
                pila_aux.Mostrar();
                system("pause");
                system("cls");
        }
        return pila_aux.Cima();
}



        /*TERCER EJERCICIO*/
/*___________________________________________________________*/

Cola Evaluacion:: ExpresionInfija_a_ExpresionPostfija (const char* exp){
    Pila pila_car; Pila pila_num; Pila pila_aux; Cola cola_exp; Cola cola_aux;
    SacarTamano(expresion);
    if (tam_exp == 0){
        cout << "Error. No has escrito nada. ";
        return cola_aux;
    }
    int n1; int n2; int c;
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
                n1 = exp[i] -48;
                pila_num.Apilar(n1);
            }
        }
        
        
        if(exp[i] == ')'){
            if (pila_num.es_Vacia()){
                cola_exp.Encolar(pila_car.Cima());
                pila_car.Desapilar(); pila_car.Desapilar();
            }
            else{
                n2= pila_num.Cima(); pila_num.Desapilar();
                n1= pila_num.Cima(); pila_num.Desapilar();
                c = pila_car.Cima(); pila_car.Desapilar(); pila_car.Desapilar();
                cola_exp.Encolar(n1);
                cola_exp.Encolar(n2);
                cola_exp.Encolar(c);
            }
        }
        cout << expresion << endl;
        cout << "Pila caracteres: ";
        pila_car.Mostrar();
        cout << "Pila numeros: ";
        pila_num.Mostrar();
        cout << "Cola expresion: ";
        cola_exp.Mostrar();
        system("pause");
        system("cls");
    }

    if (pila_car.es_Vacia() && pila_num.es_Vacia()){
            return cola_exp;
    }
    else{
        while(!pila_car.es_Vacia()){
            pila_aux.Apilar(pila_car.Cima());
            pila_car.Desapilar();
        }
        while(!pila_aux.es_Vacia()){
            cola_exp.Encolar(pila_aux.Cima());
            pila_aux.Desapilar();
        }
        cola_exp.Mostrar();
    }
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
            n1 = c1.Primero(); c1.Desencolar();
            n2 = c1.Primero(); c1.Desencolar();
            c = c1.Primero(); c1.Desencolar();
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
        cout << "Expresion: " << expresion << endl;
        cout << "C1: ";
        c1.Mostrar();
        cout << "Pila auxiliar: ";
        pila_aux.Mostrar();
        system("pause");
        system("cls");
    }
    return pila_aux.Cima();
}


Evaluacion::~Evaluacion()
{
}

