#ifndef LISTADOBLE_H
#define LISTADOBLE_H

class NodoListaDobleInt
{
public:
    NodoListaDobleInt *siguiente, *anterior;
    int dato;
    friend class ListaDoble;

};


class ListaDoble {

public:
    void inicializa();
    bool vacia();
    int tamano();
    void mostrar();
    void insertarAlFinal(int el);
    void insertarAlInicio(int el);
    void insertarEnPosicion(int pos, int el);
    int obtenerPorPosicion(int pos);
    void eliminarPrimero();
    void eliminarUltimo();
    void eliminarPorPosicion(int pos);
    void editarPorPosicion(int pos, int el);

    NodoListaDobleInt *primero, *ultimo;
};


#endif //TRABAJOEXTRACLASEDATOS2_LISTADOBLE_H
