#include "nodo.h"

nodo:: nodo(){
data = 0;
siguiente = nullptr;

}

//constructor de la clase nodo
nodo:: nodo(int dato){

data = dato;
siguiente = nullptr;
}

nodo::~nodo() {}
