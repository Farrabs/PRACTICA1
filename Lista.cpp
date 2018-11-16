#include "Lista.hpp"

Lista::Lista(){
      primero = NULL;
      ultimo = NULL;
      longitud = 0;
}

void Lista:: InsertarIzq(int v){
      pNodoLista nuevo;
      nuevo = new NodoLista(v,primero);
      if(esVacia()){
            primero = nuevo;
            ultimo = nuevo;
      }
      else{
            primero = nuevo;
      }
      longitud++;
}

void Lista:: InsertarDer(int v){
      pNodoLista nuevo;
      nuevo = new NodoLista(v,NULL);
      if(esVacia()){
            primero = nuevo;
            ultimo = nuevo;
      }
      else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
      }

      longitud++;
}

void Lista:: Mostrar(){
      pNodoLista aux = primero;
      cout<< "\n\tMi Lista:";
      while(aux){
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
      cout<<endl; 
      cout<<"\n\tLongitud: "<<longitud<<"\n";
}

bool Lista:: esVacia(){
      return primero == NULL;
}

int Lista:: Longitud(){
      return longitud;
}

int Lista:: Ver(int i){
      pNodoLista aux;
      int j;
      aux=primero;
      if(i>longitud)return -1;
      for(j=0;j<i;j++){
            aux=aux->siguiente;
      }
      return aux->valor;
}

void Lista::Insertar(int v,int p){
      pNodoLista nuevo,aux;
      int pos;
      if(p<0 || p>longitud){
      }
      else{
            if(p==0) {
                  InsertarIzq(v);
            }
            else if(p==longitud-1){
                  InsertarDer(v);
            }
            else{
                  aux = primero;
                  pos = 1;
                  while(pos<p){
                        pos++;
                        aux = aux->siguiente;
                  }
                  nuevo = new NodoLista(v,aux->siguiente);
                  aux->siguiente = nuevo;
                  longitud++;
            }
      }
}


Lista::~Lista()
{
}
