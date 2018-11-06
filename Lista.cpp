#include "Lista.hpp"

Lista::Lista(){
      primero = NULL;
      ultimo = NULL;
      longitud = 0;
}

Lista:: ~Lista(){

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

int Lista:: verPrimero(){
    pNodoLista aux = primero;
    return aux->valor;
}

int Lista:: verUltimo(){
      pNodoLista aux = ultimo;
      return aux->valor;
}

void Lista:: Mostrar(){
      pNodoLista aux = primero;
      cout<< "Mi Lista:[";
      while(aux){
            cout<<aux->valor<<",";
            aux = aux->siguiente;
      }
      cout<<"]";
      cout<<endl; 
      cout<<"Longitud: "<<longitud<<"\n";
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
      if(p<0 || p>longitud);
      else{
            if(p==0) {
                  InsertarIzq(v);
            }
            if(p==longitud-1){
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
