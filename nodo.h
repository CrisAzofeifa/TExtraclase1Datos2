#ifndef NODO_H
#define NODO_H


#include <iostream>

using namespace::std;


class nodo{

public:
nodo();
nodo(int);
~nodo();


int data;
nodo* siguiente;

void insertarNodo(int);
void desplegarLista();

};


#endif // NODO_H
