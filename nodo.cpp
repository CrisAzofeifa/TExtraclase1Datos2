#include "nodo.h"

nodo:: nodo(){
data = 0;
siguiente = nullptr;

}


nodo:: nodo(int dato){

data = dato;
siguiente = nullptr;
}

nodo::~nodo() {}
