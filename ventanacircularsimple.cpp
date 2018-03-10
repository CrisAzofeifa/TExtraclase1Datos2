#include "ventanacircularsimple.h"
#include "ui_ventanacircularsimple.h"

ventanacircularsimple::ventanacircularsimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanacircularsimple)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

ventanacircularsimple::~ventanacircularsimple()
{
    delete ui;
}

void ventanacircularsimple::actualizarDibujo(){
    scene->clear();

    string listaText = "[ ";

    nodo *tmp = lista->primero;
    for(int i = 0; i<lista->cont; i++){
        int numero = tmp->data;
        tmp = tmp->siguiente;
        string numeroT = to_string(numero);


        listaText = listaText+numeroT;
        if(i<(lista->cont)-1){
            listaText+=" , ";
        }
    }

    listaText+=" ]";

    QString Final = QString::fromStdString(listaText);

    scene->addText(Final,QFont("Times", 18, QFont::Bold));

}

void ventanacircularsimple::on_InsertarInicioBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarInicio(el);
    actualizarDibujo();
}


void ventanacircularsimple::on_InsertarFinalBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarFinal(el);
    actualizarDibujo();
}

void ventanacircularsimple::on_InsertarPOSBTN_clicked()
{
    int pos = ui->PosicionInsertar->value();
    if(pos<lista->cont && pos>=0){
        int el = ui->InsertarNumero->value();
        lista->insertarPosicion(el,pos);
        actualizarDibujo();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
}
