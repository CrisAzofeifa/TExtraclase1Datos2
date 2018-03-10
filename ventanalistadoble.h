#ifndef VENTANALISTADOBLE_H
#define VENTANALISTADOBLE_H


#include "ui_ventanalistadoble.h"
#include <QDialog>
#include <listadoble.h>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QBrush>
#include <string>

namespace Ui {
class ventanalistadoble;
}

class ventanalistadoble : public QDialog
{
    Q_OBJECT

public:
    explicit ventanalistadoble(QWidget *parent = 0);
    ~ventanalistadoble();

private slots:
    void on_InsertarInicioBTN_clicked();

    void on_InsertarFinalBTN_clicked();

    void on_InsertarPOSBTN_clicked();

    void on_EliminarInicioBTN_clicked();

    void on_EliminarFinalBTN_clicked();

    void on_EliminarPOSBTN_clicked();

    void on_ObtenerPosBTN_clicked();

    void on_EditarPosBTN_clicked();

    void actualizardibujo();

private:
    Ui::ventanalistadoble *ui;
    QGraphicsScene *scene = NULL;
    ListaDoble *lista = new ListaDoble();

};

#endif // VENTANALISTADOBLE_H
