#include "Arbol.hpp"
#include <iomanip>

Arbol::Arbol()
{
      contador =0;
      altura =0;
      raiz = NULL;
      actual =NULL;
}

int Arbol::getValorActual(){
      return actual->valor;
}

bool Arbol::esArbolVacio(){
      return raiz == NULL;
}

bool Arbol::esNodoVacio(pNodoArbol nodo){
      return nodo == NULL;
}

bool Arbol::esHoja(pNodoArbol n){
      return !n->derecha && !n->izquierda;
}

bool Arbol::esRaiz(pNodoArbol nodo){
      return nodo == raiz;
}

pNodoArbol Arbol:: getRaiz(){
      return raiz;
}

int Arbol::getValorRaiz(){
      return raiz->valor;
}

int Arbol::getAlturaArbol(){
      return altura;
}

void Arbol::Podar(pNodoArbol &nodo)
{
      if(nodo){
            Podar(nodo->izquierda); // Podar izquierdo
            Podar(nodo->derecha); // Podar derecho
            delete nodo; // Eliminar nodo
            nodo = NULL;
      }
}

bool Arbol::buscarNodo (int dato)
{
      actual = raiz;
      while(!esNodoVacio(actual))
      {
            if(dato == actual->valor){ return true;}
            else{
                  if(dato > actual->valor){ actual = actual->derecha;}
                  else if(dato < actual->valor){ actual = actual->izquierda;}
            }
      }
      return false;
}

void Arbol::insertarNodo (int v){
      NodoArbol *padre = NULL;
      actual = raiz;
      while(!esNodoVacio(actual) && v != actual->valor){
            padre = actual;
            if(v > actual->valor) actual = actual->derecha;
            else if(v < actual->valor) actual = actual->izquierda;
      }
      if(!esNodoVacio(actual))return;
      if(esNodoVacio(padre)) raiz = new NodoArbol(v);
            else if(v < padre->valor) padre->izquierda = new NodoArbol(v);
            else if(v > padre->valor) padre->derecha = new NodoArbol(v);
}

void Arbol:: borrarNodo (int v){
      NodoArbol *padre = NULL;
      NodoArbol *nodo;
      char aux;
      actual = raiz;
      while(!esNodoVacio(actual))
      {
            if(v == actual->valor) {// Si el valor está en el nodo actual ua
                  if(esHoja(actual)){
                        if(padre) // Si tiene padre (no es el nodo raiz)
                              if(padre->derecha == actual){ padre->derecha = NULL;}
                              else if(padre->izquierda == actual){ padre->izquierda = NULL;}
                        delete actual; // Borrar el nodo
                        actual = NULL;
                        return;
                  }
                  else{
                        padre = actual;
                        if(actual->derecha){
                              nodo = actual->derecha;
                              while(nodo->izquierda) {
                                    padre = nodo;
                                    nodo = nodo->izquierda->izquierda;
                              }
                        }
                        else{
                              nodo = actual->izquierda;
                              while(nodo->derecha) {
                                    padre = nodo;
                                    nodo = nodo->derecha;
                              }
                        }
                        aux = actual->valor;
                        actual->valor = nodo->valor;
                        nodo->valor = aux;
                        actual = nodo;
                  }
            }
            else{
                  padre = actual;
                  if(v > actual->valor) actual = actual->derecha;
                  else if(v < actual->valor) actual = actual->izquierda;
            }
      }
}

void Arbol::preOrden (pNodoArbol nodo){
      if (nodo!= NULL){
            cout << nodo->valor <<" ";
            preOrden (nodo->izquierda);
            preOrden (nodo->derecha);
      }
}

void Arbol::postOrden (pNodoArbol nodo){
      if (nodo!= NULL){
            postOrden (nodo->izquierda);
            postOrden (nodo->derecha);
            cout << nodo->valor <<" ";
      }
}

void Arbol::inOrden(pNodoArbol nodo){
      if (nodo!= NULL){
            inOrden(nodo->izquierda);
            cout << nodo -> valor <<" ";
            inOrden(nodo->derecha);
      }
}


void Arbol::printTree(NodoArbol* p, int indent)
{
    if(p != NULL) {
        if(p->derecha) {
            printTree(p->derecha, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->derecha) cout<<" /\n" << setw(indent) << ' ';
            printValor(p);
            cout<< "\n ";
        if(p->izquierda) {
            cout << setw(indent) << ' ' <<" \\\n";
            printTree(p->izquierda, indent+4);
        }
    }
}

void Arbol:: printValor(NodoArbol *nodo){
      int n = nodo->valor;
      if (n == '('){cout << "( ";}
      else if (n == ')'){cout << ")";}
      else if (n == '*'){cout << "*";}
      else if (n == '+'){cout << "+";}
      else if (n == '-'){cout << "-";}
      else if (n == '/'){cout << "/";}
      else{
            cout << n;
      }
}

Arbol::~Arbol()
{
}

