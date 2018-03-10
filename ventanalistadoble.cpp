#include "ventanalistadoble.h"
#include "ui_ventanalistadoble.h"
#include <iostream>

using namespace std;

/*
 * Inicia la ventana con la ecena donde se muestra la lista
 */
ventanalistadoble::ventanalistadoble(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanalistadoble)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

ventanalistadoble::~ventanalistadoble()
{
    delete ui;
}

/*
 * Ejecuta el método de insertar incio
 */
void ventanalistadoble::on_InsertarInicioBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarAlInicio(el);
    actualizardibujo();

}

/*
 * Ejecuta el método de insertar final
 */
void ventanalistadoble::on_InsertarFinalBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarAlFinal(el);
    actualizardibujo();
}
/*
 * Ejecuta el método de insertar en posicion
 */
void ventanalistadoble::on_InsertarPOSBTN_clicked()
{
    int pos = ui->PosicionInsertar->value();


    if(pos<lista->tamano() && pos>-1){
        int el = ui->InsertarNumero->value();
        lista->insertarEnPosicion(pos,el);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }


    actualizardibujo();
}

/*
 * Ejecuta el método de eliminar incio
 */
void ventanalistadoble::on_EliminarInicioBTN_clicked()
{
    lista->eliminarPrimero();
    QString x = "hola";
    actualizardibujo();

}
/*
 * Ejecuta el método de eliminar final
 */
void ventanalistadoble::on_EliminarFinalBTN_clicked()
{
    lista->eliminarUltimo();
    actualizardibujo();

}

/*
 * Ejecuta el método de elminar por posicion
 */
void ventanalistadoble::on_EliminarPOSBTN_clicked()
{
    int pos = ui->PosEliminar->value();

    if(pos<lista->tamano() && pos>=0){
        lista->eliminarPorPosicion(pos);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
    actualizardibujo();
}

/*
 * Ejecuta el método de obtener por posicion
 */
void ventanalistadoble::on_ObtenerPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();



    if(pos<lista->tamano() && pos>-1){
        int numero = lista->obtenerPorPosicion(pos);
        string texto = "El número en la posición "+to_string(pos)+" es "+to_string(numero);
        QString Qtexto = QString::fromStdString(texto);
        QMessageBox msgBox;
        msgBox.setText(Qtexto);
        msgBox.exec();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
}

/*
 * Ejecuta el método de editar por posicion
 */
void ventanalistadoble::on_EditarPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();

    if(pos<lista->tamano() && pos>-1){
        int el = ui->NumeroEditar->value();
        lista->editarPorPosicion(pos, el);
        actualizardibujo();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
}


/*
 * Actualiza el gráfico de la lista
 * Mediante un string este muestra la lista en pantalla
 */
void ventanalistadoble::actualizardibujo(){
    scene->clear();

    string listaText = "[ ";

    NodoListaDobleInt *tmp = lista->primero;
    for(int i = 0; i<lista->tamano(); i++){
        int numero = tmp->dato;
        tmp = tmp->siguiente;
        string numeroT = to_string(numero);


        listaText = listaText+numeroT;
        if(i<lista->tamano()-1){
            listaText+=" , ";
        }
    }

    listaText+=" ]";

    QString Final = QString::fromStdString(listaText);

    scene->addText(Final,QFont("Times", 18, QFont::Bold));

}
