//
// Created by cris on 23/02/18.
//

#include "ListaSimple.h"
#include <iostream>
#include <thread_db.h>

using namespace std;

/*
 * Destructor de la clase
 */
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

/*
 *Método que inserta al final un nuevo
 * valor
 */
void ListaSimple ::InsertarAlFinal(int el) {
    if(ultimo != 0) {
        ultimo->siguiente = new NodoSimpleInt(el);
        ultimo = ultimo->siguiente;
    }else{
        primero = ultimo = new NodoSimpleInt(el);
    }
    tamanio++;
}

/*
 * Método que borra el primer elemento
 */
void ListaSimple ::EliminarPrimero() {

    if(primero == ultimo) {
        primero = ultimo = nullptr;
    }else{
        primero = primero->siguiente;


    }

    tamanio--;


}

/*
 * Método que borra el último elemento
 */
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
        ultimo = tmp;
        ultimo->siguiente = nullptr;
        tamanio--;
    }

}

/*
 * Método que busca un nodo en la posicion dada
 * por el usuario y sustituye su valor por otro
 */
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
    }

}

/*
 * Método que obtiene el valor de una posición dada
 */
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
        return el;

    }


}

/*
 *Método que muestra la lista en consola
 */
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

/*
 * Método que inserta un valor determinado en una
 * posición dada
 */
void ListaSimple ::InsertarEnPosicion(int pos, int el) {

    if(pos == 0 )
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
        NodoSimpleInt *nuevo = new NodoSimpleInt();
        nuevo->dato = el;
        tmp2->siguiente = nuevo;
        nuevo->siguiente = tmp;
    }
    else{
        cout<<"Posición no encontrada, inserte una posición valida";
    }
    tamanio++;

}

/*
 * Método que elimina el elemento de una posicion dada
 */
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
    }else{
        cout<<"Posicion no valida.";
    }

}

/*
 *Método que retorna el tamaño de la lista
 */
int ListaSimple::GetTamanio(){
    return tamanio;
}


