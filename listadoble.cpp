#include "listadoble.h"
#include <iostream>

using namespace std;

/*
 *Método que inicia la lista
 */
void ListaDoble ::inicializa() {

    primero = nullptr;
    ultimo = nullptr;

}


/*
 * Método booleano para saber si la lista está vacia
 */
bool ListaDoble ::vacia() {
    if(primero == nullptr &&  ultimo == nullptr)
    {
        return true;
    }else
    {
        return false;
    }

}


/*
 * método para calcular el tamaño haciendo un recorrido
 * en la lista
 */
int ListaDoble::tamano() {
    NodoListaDobleInt *tmp = ultimo;
    int cont = 0;
    while(tmp != nullptr){
        tmp = tmp->anterior;
        cont++;
    }
    return cont;

}


/*
 * Método que recorre la lista y despliega los
 * valores
 */
void ListaDoble::mostrar() {
    NodoListaDobleInt *tmp = primero;
    cout<<"[ ";
    while(tmp != nullptr){
        cout<<tmp->dato<<" ";
        tmp = tmp->siguiente;
    }
    cout<<"]";
    delete tmp;
}


/*
 * Método que agrega al incio un nuevo nodo
 */
void ListaDoble ::insertarAlInicio(int el) {
    NodoListaDobleInt *tmp = new NodoListaDobleInt;
    tmp->dato = el;
    tmp->anterior = nullptr;
    tmp->siguiente = nullptr;

    if(vacia()){
        primero = tmp;
        ultimo = tmp;
    }else{
        tmp->siguiente = primero;
        primero->anterior = tmp;
        primero = tmp;
    }
}


/*
 * Método que agrega al final un nuevo nodo
 */
void ListaDoble::insertarAlFinal(int el) {
    NodoListaDobleInt *tmp = new NodoListaDobleInt;
    tmp->dato = el;
    tmp->anterior = nullptr;
    tmp->siguiente = nullptr;

    if(vacia()){
        primero = tmp;
        ultimo = tmp;
    }else{
        tmp->anterior = ultimo;
        ultimo->siguiente = tmp;
        ultimo = tmp;
    }
}


/*
 * Método que inserta un número determinado en una posición
 * dada por el usuario
 */
void ListaDoble::insertarEnPosicion(int pos, int el) {
    if(pos == tamano())
    {
        insertarAlFinal(el);
    }

    else if(pos == 0)
    {
        insertarAlInicio(el);
    }

    else if(pos>0 && pos<tamano())
    {
        NodoListaDobleInt *aux = primero;
        NodoListaDobleInt *tmp = new NodoListaDobleInt;
        tmp->dato = el;
        tmp->siguiente, tmp->anterior = NULL;
        for(int x = 0; x<pos; x++)
        {
            aux = aux->siguiente;
        }
        aux->anterior->siguiente = tmp;
        tmp->siguiente = aux;
        tmp->anterior = aux->anterior;
        aux->anterior = tmp;


    }else{
        cout<<"No existe la posicion.";
    }
}



/*
 * Método que retorna el valor de contenido
 * en una posición dada por el usuario
 */
int ListaDoble::obtenerPorPosicion(int pos) {
    int dato;
    if(vacia()){
        cout<<"No hay elementos en la lista.";
    }else if(pos<tamano() && pos>0){
        NodoListaDobleInt *tmp = primero;
        for(int x = 0; x<pos; x++){
            tmp = tmp->siguiente;
        }
        dato = tmp->dato;
        return dato;
    }else{
        cout<<"La posición no existe";
        return dato;
    }

}



/*
 * Método para eliminar el primer nodo de la lista
 */
void ListaDoble::eliminarPrimero() {
    if(primero == ultimo) {
        primero = ultimo = nullptr;
    }else{
        primero = primero->siguiente;
        delete primero->anterior;
        primero->anterior = nullptr;

    }
}



/*
 * Método para eliminar el último nodo de la lista
 */
void ListaDoble::eliminarUltimo() {
    if(primero == ultimo) {
        primero = ultimo = nullptr;
    }else{
        ultimo = ultimo->anterior;
        delete ultimo->siguiente;
        ultimo->siguiente = nullptr;

    }


}


/*
 * Método que busca y elimina el nodo que se
 * encuentra en una posición dada por el
 * usuario
 */
void ListaDoble::eliminarPorPosicion(int pos) {    
    if(pos==0){
        eliminarPrimero();

    }else if(pos == tamano()){
        eliminarUltimo();
    }

    else if(pos>0 && pos<tamano()){
        NodoListaDobleInt *aux = primero;
        for(int x = 0; x<pos; x++){
            aux = aux->siguiente;
        }
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete(aux);

    }else{
        cout<<"Posicion no valida.";
    }
}


/*
 * Método que busca un nodo en la posicion dada
 * por el usuario y sustituye su valor por otro
 */
void ListaDoble::editarPorPosicion(int pos, int el) {
    if(pos>tamano() or pos<0)
    {
        cout<<"Posicion no valida";
    }
    else
    {
         NodoListaDobleInt *aux = primero;
         for(int x = 0; x<pos; x++){
             aux = aux->siguiente;
    }
    aux->dato = el;
    }
}
