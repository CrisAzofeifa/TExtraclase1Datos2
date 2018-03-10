#include "ventanacircularsimple.h"
#include "ui_ventanacircularsimple.h"

/*incia la ventana con la ecena donde se mostrará la lista
 */
ventanacircularsimple::ventanacircularsimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanacircularsimple)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

/*
 *Destructor de la clase
 */
ventanacircularsimple::~ventanacircularsimple()
{
    delete ui;
}

/*
 * Actualiza el gráfico de la lista
 * Mediante un string este muestra la lista en pantalla
 */
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

/*
 * Ejecuta el método de insertar incio
 */
void ventanacircularsimple::on_InsertarInicioBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarInicio(el);
    actualizarDibujo();
}

/*
 * Ejecuta el método de insertar al final
 */
void ventanacircularsimple::on_InsertarFinalBTN_clicked()
{
    int el = ui->InsertarNumero->value();
    lista->insertarFinal(el);
    actualizarDibujo();
}


/*
 * Ejecuta el método de insertar en posicion
 */
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


/*
 * Ejecuta el método de eliminar incio
 */
void ventanacircularsimple::on_EliminarInicioBTN_clicked()
{
    lista->eliminarInicio();
    actualizarDibujo();
}

/*
 * Ejecuta el método de eliminar final
 */
void ventanacircularsimple::on_EliminarFinalBTN_clicked()
{
    lista->eliminarFinal();
    actualizarDibujo();
}

/*
 * Ejecuta el método de eliminar por posicion
 */
void ventanacircularsimple::on_EliminarPOSBTN_clicked()
{
    int pos = ui->PosicionInsertar->value();
    if(pos<lista->cont && pos>=0){
        lista->eliminarporposicion(pos);
        actualizarDibujo();
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }
}

/*
 * Ejecuta el método de obtener por posicion
 */
void ventanacircularsimple::on_ObtenerPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();

    if(pos<lista->cont && pos>-1){
        int numero = lista->obtenerporpos(pos);
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
void ventanacircularsimple::on_EditarPosBTN_clicked()
{
    int pos = ui->PosEditarObtener->value();

    if(pos<lista->cont && pos>-1){
        int el = ui->NumeroEditar->value();
        lista->editarporposicion(pos, el);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Posición inválida");
        msgBox.exec();
    }

    actualizarDibujo();
}
