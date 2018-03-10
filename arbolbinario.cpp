#include <iostream>

using namespace::std;

#include "arbolbinario.h"

 nodoBin *crearNodo(int dato, nodoBin *padre){
     nodoBin *nuevo = new nodoBin();

     nuevo->dato = dato;
     nuevo -> der = NULL;
     nuevo ->izq = NULL;
     nuevo -> padre = padre;
     return nuevo;


 }

void insertar( nodoBin *& raiz, int dato, nodoBin *padre){
    if (raiz == NULL){
        nodoBin *nuevo = crearNodo(dato,padre);
        raiz = nuevo;
    }else{
        int valorRaiz = raiz -> dato;
        if( dato < valorRaiz){
            insertar (raiz -> izq, dato, padre);

        }else{
            insertar(raiz -> der, dato, padre);

        }
    }
}

void eliminarNodo (nodoBin *nodoElim){

        if(nodoElim -> izq && nodoElim -> der){
        nodoBin *menor = minimo(nodoElim -> der);
        nodoElim -> dato = menor -> dato;
        eliminar(nodoElim);
        }
        else if (nodoElim ->izq){
            reemplazar(nodoElim, nodoElim ->izq);
            destruirNodo(nodoElim);
        }
        else if(nodoElim ->izq){
            reemplazar(nodoElim, nodoElim-> der);
            destruirNodo(nodoElim);

        }
}
void eliminar( nodoBin *raiz, int data){
    if(raiz==  NULL){
        return;
    }
    else if(data < raiz -> dato){
        eliminar(raiz ->izq, data);
    }
    else if ( data > raiz -> dato){
        eliminar(raiz ->  der, data);
    }
    else{
        eliminarNodo(raiz);
    }
}
