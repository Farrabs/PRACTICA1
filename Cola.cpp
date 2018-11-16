#include "Cola.hpp"
using namespace std;

Cola::Cola()
{
    ultimo = NULL;
    primero = NULL;
}

void Cola:: Encolar(int v){
    pNodoCola nuevo = new NodoCola (v,NULL);
    if (ultimo){
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if(!primero){
        primero = nuevo;
    }
}

int Cola:: Desencolar(){
    
    pNodoCola aux = primero;
    int v = aux-> valor;
    if(!aux){
        return 0;
    }
    primero = aux->siguiente;
    delete aux;
    if(!primero){
        ultimo =NULL;
    }
    return v;
}

void Cola:: Mostrar(){
      pNodoCola aux = primero;
      cout << "\n\t";
      while (aux){
            int n = aux->valor;
            if (n == '('){cout << "( ";}
            else if (n == ')'){cout << ") ";}
            else if (n == '*'){cout << "* ";}
            else if (n == '+'){cout << "+ ";}
            else if (n == '-'){cout << "- ";}
            else if (n == '/'){cout << "/ ";}
            else{
                  cout << n << " ";
            }
        aux = aux->siguiente;
    }
    cout << endl;
}

int Cola::Primero(){
    int v= primero->valor;
    return v;
}

bool Cola:: es_Vacia(){
    return (primero == NULL);
}

Cola::~Cola()
{
}
