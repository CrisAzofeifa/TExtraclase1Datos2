#ifndef VENTANALISTASIMPLE_H
#define VENTANALISTASIMPLE_H

#include "ui_ventanalistasimple.h"
#include <QDialog>
#include <ListaSimple.h>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QBrush>


namespace Ui {
class VentanaListaSimple;
}

class VentanaListaSimple : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaListaSimple(QWidget *parent = 0);
    ~VentanaListaSimple();

private slots:
    void on_InsertarInicioBTN_clicked();

    void on_InsertarFinalBTN_clicked();

    void on_InsertarPOSBTN_clicked();

    void on_EliminarInicioBTN_clicked();

    void on_EliminarFinalBTN_clicked();

    void on_EliminarPOSBTN_clicked();

    void on_EditarPosBTN_clicked();

    void on_ObtenerPosBTN_clicked();

    void actualizardibujo();


private:
    Ui::VentanaListaSimple *ui;
    ListaSimple *lista = new ListaSimple;

    QGraphicsScene *scene = NULL;


};

#endif // VENTANALISTASIMPLE_H
