//
// Created by cris on 07/03/18.
//

#include "listacircularsimple.h"



using namespace std;

 /*
 * Constructor de la clase
 */
ListaCircularSimple::ListaCircularSimple() {
    primero == nullptr;
    ultimo == nullptr;
    cont = 0;
}


/*
 * Método que inserta un nodo al final
 * de la lista
 */
void ListaCircularSimple::insertarFinal(int el){
    nodo *nuevo = new nodo(el);
    nuevo->siguiente = nullptr;
    if (primero == nullptr){
        primero = nuevo;
        primero -> siguiente =primero;
        ultimo = primero;
    }else{
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = primero;
        ultimo = nuevo;
    }
    cont ++;
}

/*
 * Método que inserta un nodo al incio de
 * la lista
 */
void ListaCircularSimple::insertarInicio(int el){
    nodo *nuevo = new nodo(el);
    nuevo->siguiente = nullptr;
    if (primero == nullptr){
        primero=nuevo;
        primero -> siguiente =primero;
        ultimo = primero;
    }else{
        nuevo-> siguiente = primero;
        primero = nuevo;
        ultimo -> siguiente = primero;

    }
    cont ++;
}

/*
 * Método que hace un recorrido por la lista
 * y muestra el valor de cada nodo
 */
void ListaCircularSimple :: desplegarLista(){
    nodo* actual;
    actual = primero;
    if (primero!= nullptr){
        do{
            cout << actual-> data<< endl;
            actual = actual -> siguiente;
        }while(actual != primero);

    }else{

    }

}


/*
 * Método que devuelve el elemento que se
 * encuentra en una posicion dada
 */
int ListaCircularSimple:: obtenerporpos(int pos) {
    if(pos==0){
        return primero->data;
    }

    else if(pos==cont){
        ultimo->data;
    }

    else if(pos<cont && pos>0)
    {
        nodo *tmp = primero;
        for(int x=0;x<pos;x++ ){
            tmp = tmp->siguiente;

        }
        return tmp->data;

    }else{
        cout<<"posicion no valida";
    }

}

/*
 * Método que permite cambiar el dato de un nodo
 * en determinada posición
 */
void ListaCircularSimple:: editarporposicion (int pos, int el){
    if(pos==0){
        primero->data = el;
    }

    else if(pos==cont){
        ultimo->data = el;
    }

    else if(pos<cont && pos>0)
    {
        nodo *tmp = primero;
        for(int x=0;x<pos-1;x++ ){
            tmp = tmp->siguiente;

        }
        nodo *nuevo = new nodo();
        nuevo->data = el;
        nuevo->siguiente = tmp->siguiente->siguiente;
        tmp->siguiente = nuevo;

    }else{
        cout<<"posicion no valida";
    }
}



/*
 * Método para eliminar el primer elemento
 * de la lista
 */
void ListaCircularSimple:: eliminarInicio(){

    primero = primero -> siguiente;
    ultimo -> siguiente = primero;
    cont--;

}

/*
 * Método para eliminar el último elemento
 * de la lista
 */
void ListaCircularSimple:: eliminarFinal(){
    if(primero==ultimo){
        primero = ultimo = NULL;
        cont=0;
    }else{
        nodo *tmp = primero;
        for(int x = 0; x<cont-1;x++ ){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = primero;
        cont--;
    }

}


/*
 * Método que elimina el elemento de una posicion dada
 * por el usuario
 */
void ListaCircularSimple:: eliminarporposicion(int pos){
    if(pos==0){
        eliminarInicio();
    }else if(pos==cont){
        eliminarFinal();
    }

    else if(pos<cont && pos>0)
    {
        nodo *tmp = primero;
        for(int x=0;x<pos-1;x++ ){
            tmp = tmp->siguiente;

        }
        tmp->siguiente = tmp->siguiente->siguiente;
        cont--;
    }else{
        cout<<"posicion no valida";
    }

}

/*
 * Método que inserta un número dado en una posición
 * determinada por el usuario
 */
void ListaCircularSimple:: insertarPosicion(int dato, int pos) {
    if(pos==0){
        insertarInicio(dato);
    }

    else if(pos==cont){
     insertarFinal(dato);
    }

    else if(pos<cont && pos>0)
    {
        nodo *tmp = primero;
        for(int x=0;x<pos-1;x++ ){
            tmp = tmp->siguiente;

        }
        nodo *nuevo = new nodo();
        nuevo->data = dato;
        nodo *aux = tmp->siguiente;
        tmp->siguiente = nuevo;
        nuevo->siguiente = aux;
        cont++;



    }else{
        cout<<"posicion no valida";
    }
}




ListaCircularSimple ::~ListaCircularSimple() {

}
