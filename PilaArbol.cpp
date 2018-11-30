#include "PilaArbol.hpp"

PilaArbol::PilaArbol()
{
      ultimo = NULL;
}


void PilaArbol:: ApilarArbol(pNodoArbol a){
      pNodoPilaArbol nuevo;
      nuevo = new NodoPilaArbol (a, ultimo);
      ultimo = nuevo;
}

pNodoArbol PilaArbol:: DesapilarArbol (){
    pNodoPilaArbol nodo;
    pNodoArbol a =NULL;
    if (!ultimo){
        return a;
    }
    nodo = ultimo;
    ultimo = nodo->siguiente;
    a = nodo->arbol;
    
    delete nodo;
    return a;
}

pNodoArbol PilaArbol :: Cima(){
    pNodoPilaArbol aux = ultimo;
    return aux->arbol;
}

bool PilaArbol:: es_Vacia(){
    return (ultimo== NULL);
}

void PilaArbol :: Mostrar(){
      pNodoPilaArbol aux = ultimo;
      cout << "\n\t" ;
      while (aux){
            pNodoArbol n = aux->arbol;
            /*if (n == '('){cout << "( ";}
            else if (n == ')'){cout << ") ";}
            else if (n == '*'){cout << "* ";}
            else if (n == '+'){cout << "+ ";}
            else if (n == '-'){cout << "- ";}
            else if (n == '/'){cout << "/ ";}
            else{*/
                  cout << n << " ";
            //}
            aux = aux->siguiente;
    }
    cout << endl;
}


PilaArbol::~PilaArbol()
{
}

