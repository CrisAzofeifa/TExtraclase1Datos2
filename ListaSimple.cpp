//
// Created by cris on 23/02/18.
//

#include "ListaSimple.h"
#include <iostream>
#include <thread_db.h>

using namespace std;

ListaSimple::~ListaSimple() {
    for(NodoSimpleInt *p; !EstaVacia();) {
        p = primero->siguiente;
        delete primero;
        primero = p;
    }
}

void ListaSimple :: InsertarAlInicio(int el){
    primero = new NodoSimpleInt(el, primero);
    if (ultimo == nullptr){
        ultimo = primero;
    }
    tamanio++;
}

void ListaSimple ::InsertarAlFinal(int el) {
    if(ultimo != 0) {
        ultimo->siguiente = new NodoSimpleInt(el);
        ultimo = ultimo->siguiente;
    }else{
        primero = ultimo = new NodoSimpleInt(el);
    }
    tamanio++;
}


void ListaSimple ::EliminarPrimero() {

    if(primero == ultimo) {
        primero = ultimo = nullptr;
    }else{
        primero = primero->siguiente;


    }

    tamanio--;


}

void ListaSimple ::EliminarUltimo() {
    if(primero == ultimo){
        delete primero;
        primero = ultimo = nullptr;
        tamanio = 0;
    }else{
        NodoSimpleInt *tmp;
        for(tmp = primero; tmp->siguiente != ultimo; tmp = tmp->siguiente) {
            //delete ultimo;
        }
        delete ultimo;
        ultimo = tmp;
        ultimo->siguiente = nullptr;
        tamanio--;
    }

}

void ListaSimple ::EditarPorPosicion(int pos, int el) {
    if(pos == 0) {
        primero->dato = el;
    }else if(pos==tamanio){
        ultimo->dato = el;
    }else{
        NodoSimpleInt *tmp = primero;
        for(int x = 0; x<pos; x++){
            tmp = tmp->siguiente;
        }
        tmp->dato = el;
        delete tmp;
    }

}

int ListaSimple ::ObtenerPorPosicion(int pos) {

    if(pos == 0){
        int el = primero->dato;
        return el;

    }else{

        NodoSimpleInt *tmp = primero;
        for(int x = 0; x<pos; x++) {
            *tmp = *tmp->siguiente;
        }
        int el = tmp->dato;
        delete tmp;
        return el;

    }


}

void ListaSimple ::ImprimirLista() {
        NodoSimpleInt *tmp = primero;
        cout<<"[ ";
        while(tmp != nullptr){
            cout<<tmp->dato<<" ";
            tmp = tmp->siguiente;
        }
        cout<<"]";
        delete tmp;

}

void ListaSimple ::InsertarEnPosicion(int pos, int el) {
    NodoSimpleInt *aux = new NodoSimpleInt(el);
    aux->siguiente = nullptr;

    if(EstaVacia() or pos == 0 )
    {
        InsertarAlInicio(el);
    }
    else if (pos == tamanio)
    {
        InsertarAlFinal(el);
    }
    else if(pos>0 && pos<tamanio)
    {
        NodoSimpleInt *tmp, *tmp2;
        tmp = primero;
        for(int x = 0; x<pos; x++)
        {
            tmp2 = tmp;
            tmp = tmp->siguiente;
        }
        tmp2->siguiente = aux;
        aux->siguiente = tmp;
    }
    else{
        cout<<"Posición no encontrada, inserte una posición valida";
    }
    tamanio++;

}

void ListaSimple ::EliminarPorPosicion(int pos) {
    if(pos == 0)
    {
        EliminarPrimero();
    }else if(pos == tamanio)
    {
        EliminarUltimo();
    }else if(pos>0 && pos<tamanio)
    {
        NodoSimpleInt *tmp, *tmp2;
        tmp = primero;
        for(int x = 0; x<pos; x++){
            tmp2 = tmp;
            tmp = tmp->siguiente;
        }
        tmp2->siguiente = tmp->siguiente;
        delete tmp, tmp2;
    }else{
        cout<<"Posicion no valida.";
    }

}
int ListaSimple::GetTamanio(){
    return tamanio;
}


