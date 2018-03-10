#include "ventanalistasimple.h"
#include "ui_ventanalistasimple.h"
#include <iostream>

using namespace std;

VentanaListaSimple::VentanaListaSimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaListaSimple)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


}

VentanaListaSimple::~VentanaListaSimple()
{
    delete ui;
}

void VentanaListaSimple::on_InsertarInicioBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->InsertarAlInicio(el);
    actualizardibujo();

}

void VentanaListaSimple::on_InsertarFinalBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->InsertarAlFinal(el);
    actualizardibujo();

}

void VentanaListaSimple::on_InsertarPOSBTN_clicked()
{
    int pos = ui->PosicionInsertar->value();


    if(pos<lista->GetTamanio() && pos>-1){
        int el = ui->InsertarNumero->value();
        lista->InsertarEnPosicion(pos,el);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }


    actualizardibujo();
}

void VentanaListaSimple::on_EliminarInicioBTN_clicked()
{
    lista->EliminarPrimero();
    actualizardibujo();
}

void VentanaListaSimple::on_EliminarFinalBTN_clicked()
{
    lista->EliminarUltimo();
    actualizardibujo();
}

void VentanaListaSimple::on_EliminarPOSBTN_clicked()
{
    int pos = ui->PosEliminar->value();

    if(pos<lista->GetTamanio() && pos>=0){
        lista->EliminarPorPosicion(pos);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
    actualizardibujo();
}

void VentanaListaSimple::on_EditarPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();

    if(pos<lista->GetTamanio() && pos>-1){
        int el = ui->NumeroEditar->value();
        lista->EditarPorPosicion(pos, el);
        actualizardibujo();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
}

void VentanaListaSimple::on_ObtenerPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();



    if(pos<lista->GetTamanio() && pos>-1){
        int numero = lista->ObtenerPorPosicion(pos);
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

void VentanaListaSimple::actualizardibujo(){

    scene->clear();

    string listaText = "[ ";

    NodoSimpleInt *tmp = lista->primero;
    for(int i = 0; i<lista->GetTamanio(); i++){
        int numero = tmp->dato;
        tmp = tmp->siguiente;
        string numeroT = to_string(numero);


        listaText = listaText+numeroT;
        if(i<lista->GetTamanio()-1){
            listaText+=" , ";
        }
    }
    delete tmp;

    listaText+=" ]";

    QString Final = QString::fromStdString(listaText);

    scene->addText(Final,QFont("Times", 18, QFont::Bold));



}
