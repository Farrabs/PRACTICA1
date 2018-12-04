#include "Arbol.hpp"
#include <iomanip>

class izquierda;
Arbol::Arbol()
{
      contador =0;
      contador_parentesis=-1;
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

/*void Arbol:: setRaiz(int v,Arbol izq, Arbol der){
      Arbol nuevo = new NodoArbol(v,izq,der);
      raiz = nuevo;
}*/

int Arbol::getAlturaArbol(NodoArbol * nodo){
      
      if (esNodoVacio(nodo->izquierda)){
            if(esNodoVacio(nodo->derecha)){ altura =0; }
            else{ altura = 1 + getAlturaArbol(nodo->derecha); }
      }
      
      else{
            if (esNodoVacio(nodo->derecha)){ altura = 1 + getAlturaArbol(nodo->izquierda); }
            else{ altura = 1 + max(getAlturaArbol(nodo->izquierda), getAlturaArbol(nodo->derecha)); }
      }
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

void Arbol:: insertarNodoExpresion(int v, char*exp){
      NodoArbol *padre = NULL;
      actual = raiz;
      while(!esNodoVacio(actual)){
            padre = actual;
            if(v > actual->valor) actual = actual->derecha;
            else if(v== actual->valor) actual = actual->izquierda;
            else if(v < actual->valor) actual = actual->izquierda;
      }
      if(!esNodoVacio(actual))return;
      if(esNodoVacio(padre)) raiz = new NodoArbol(v,NULL,NULL,exp);
            else if(v < padre->valor) padre->izquierda = new NodoArbol(v,NULL,NULL,exp);
            else if(v== padre->valor) padre->izquierda = new NodoArbol(v,NULL,NULL,exp);
            else if(v > padre->valor) padre->derecha = new NodoArbol(v,NULL,NULL,exp);
}


void Arbol::insertarNodo (int v){
      NodoArbol *padre = NULL;
      actual = raiz;
      while(!esNodoVacio(actual)){
            padre = actual;
            if(v > actual->valor) actual = actual->derecha;
            else if(v==actual->valor) actual = actual->izquierda;
            else if(v < actual->valor) actual = actual->izquierda;
      }
      if(!esNodoVacio(actual))return;
      if(esNodoVacio(padre)) raiz = new NodoArbol(v);
            else if(v < padre->valor) padre->izquierda = new NodoArbol(v);
            else if(v== padre->valor) padre->izquierda = new NodoArbol(v);
            else if(v > padre->valor) padre->derecha = new NodoArbol(v);
}

void Arbol::insertarNodoDerecha(int v, NodoArbol *nodo){
      if (nodo->derecha) { cout <<"Error, el nodo derecho ya está lleno\n";}
      else{
            nodo->derecha =new NodoArbol(v, NULL, NULL);
      }
}

void Arbol::insertarNodoIzquierda(int v, NodoArbol *nodo){
      if (nodo->izquierda) { cout <<"Error, el nodo izquierdo ya está lleno\n";}
      else{
            nodo->izquierda =new NodoArbol(v, NULL, NULL);
      }
}

void Arbol:: insertarArbolDerecha(pNodoArbol a, pNodoArbol nodo){
      if (nodo->derecha) { cout <<"Error, el nodo ya está lleno\n";}
      else{
            nodo->derecha =new NodoArbol(a->valor, a->derecha, a->izquierda);
      }
}

void Arbol:: insertarArbolIzquierda(pNodoArbol a, pNodoArbol nodo){
      if (nodo->izquierda) { cout <<"Error, el nodo ya está lleno\n";}
      else{
            nodo->izquierda =new NodoArbol(a->valor, a->derecha, a->izquierda);
      }
}

void Arbol:: borrarNodo (int v){
      NodoArbol *padre = NULL;
      NodoArbol *nodo;
      char aux;
      actual = raiz;
      while(!esNodoVacio(actual)){
            if(v == actual->valor) {// Si el valor está en el nodo actual
                  if(esHoja(actual)){
                        if(padre){ // Si tiene padre (no es el nodo raiz)
                              if(padre->derecha == actual){ padre->derecha = NULL;}
                              else if(padre->izquierda == actual){ padre->izquierda = NULL;}
                        }
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
                                    nodo = nodo->izquierda;
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
            printValor(nodo);
            cout << "," ;
            preOrden (nodo->izquierda);
            preOrden (nodo->derecha);
      }
}

void Arbol::postOrden (pNodoArbol nodo){
      if (nodo!= NULL){
            postOrden (nodo->izquierda);
            postOrden (nodo->derecha);
            printValor(nodo);
            cout << "," ;
      }
}

void Arbol::inOrden(pNodoArbol nodo){
      if (nodo!= NULL){
            inOrden(nodo->izquierda);
            printValor(nodo);
            cout << "," ;
            inOrden(nodo->derecha);
      }
}

void Arbol::inOrdenExp(pNodoArbol nodo){
      if (nodo!= NULL){
            inOrdenExp(nodo->izquierda);
            cout << "[ "<< nodo->expresion <<"] ," ;
            inOrdenExp(nodo->derecha);
      }
}


void Arbol::printTree(pNodoArbol p, int indent)
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
      else if (n == ')'){cout << "[)]";}
      else if (n == '*'){cout << "[*]";}
      else if (n == '+'){cout << "[+]";}
      else if (n == '-'){cout << "[-]";}
      else if (n == '/'){cout << "[/]";}
      else{
            cout <<"[" <<n<<"]";
      }
}

int Arbol:: NumeroHojas(pNodoArbol nodo){
      if (nodo == NULL){
            return 0;
      }
      else{
            if ((nodo->izquierda == NULL) && (nodo->derecha ==NULL)){
                  return 1 + NumeroHojas(nodo->izquierda) + NumeroHojas(nodo->derecha);
            }
            else{
                  return NumeroHojas(nodo->izquierda) + NumeroHojas(nodo->derecha);
            }
      }
}

int Arbol:: NumeroNodos(pNodoArbol nodo){
      if (nodo == NULL){
            return 0;
      }
      else {
            return 1 + NumeroNodos(nodo->izquierda) + NumeroNodos(nodo->derecha);
      }
}



Arbol::~Arbol()
{
}

