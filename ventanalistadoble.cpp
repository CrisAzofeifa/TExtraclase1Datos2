#include "ventanalistadoble.h"
#include "ui_ventanalistadoble.h"
#include <iostream>

using namespace std;

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

void ventanalistadoble::on_InsertarInicioBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarAlInicio(el);
    actualizardibujo();

}


void ventanalistadoble::on_InsertarFinalBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarAlFinal(el);
    actualizardibujo();
}

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

void ventanalistadoble::on_EliminarInicioBTN_clicked()
{
    lista->eliminarPrimero();
    actualizardibujo();

}

void ventanalistadoble::on_EliminarFinalBTN_clicked()
{
    lista->eliminarUltimo();
    actualizardibujo();

}

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
