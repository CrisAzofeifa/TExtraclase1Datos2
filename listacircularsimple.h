#ifndef ESTRUCTURAS_DE_DATOS_LISTACIRCULARSIMPLE_H
#define ESTRUCTURAS_DE_DATOS_LISTACIRCULARSIMPLE_H


#include <iostream>
#include "nodo.h"




using namespace std;


class ListaCircularSimple{

public:
    ListaCircularSimple();
    ~ListaCircularSimple();


    void insertarInicio(int el);
    void insertarFinal(int el);
    void insertarPosicion(int dato, int pos);
    int obtenerporpos(int pos);
    void desplegarLista();
    void eliminarporposicion(int pos);
    void eliminarInicio();
    void eliminarFinal();
    void editarporposicion(int pos, int el);
    int cont;

    nodo *primero; nodo *ultimo;






};

#endif //ESTRUCTURAS_DE_DATOS_LISTACIRCULARSIMPLE_H
