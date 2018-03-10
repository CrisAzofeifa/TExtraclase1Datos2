//
// Created by cris on 07/03/18.
//

#include "listacircularsimple.h"



using namespace std;


ListaCircularSimple::ListaCircularSimple() {
    primero == nullptr;
    ultimo == nullptr;
    cont = 0;
}



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

void ListaCircularSimple:: editarporposicion (int pos, int el){
    if(pos==0){
        insertarInicio(el);
    }

    else if(pos==cont){
        insertarFinal(el);
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




void ListaCircularSimple:: eliminarInicio(){

    primero = primero -> siguiente;
    ultimo -> siguiente = primero;

}

void ListaCircularSimple:: eliminarFinal(){

    nodo *actual;
    actual = primero;
    nodo *anterior;
    anterior = NULL;

    if (primero != NULL) {
        do {
            if (actual == ultimo) {
                anterior -> siguiente = primero;
                ultimo = anterior;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != primero);

    } else {
        cout << "Lista vacia" << endl;
    }


}



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
