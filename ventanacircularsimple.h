#ifndef VENTANACIRCULARSIMPLE_H
#define VENTANACIRCULARSIMPLE_H

#include "ui_ventanalistadoble.h"
#include <QDialog>
#include <listacircularsimple.h>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QBrush>
#include <string>

namespace Ui {
class ventanacircularsimple;
}

class ventanacircularsimple : public QDialog
{
    Q_OBJECT

public:
    explicit ventanacircularsimple(QWidget *parent = 0);
    ~ventanacircularsimple();

private slots:
    void actualizarDibujo();
    void on_InsertarInicioBTN_clicked();


    void on_InsertarFinalBTN_clicked();

    void on_InsertarPOSBTN_clicked();

private:
    Ui::ventanacircularsimple *ui;
    QGraphicsScene *scene = NULL;

    ListaCircularSimple *lista = new ListaCircularSimple();


};

#endif // VENTANACIRCULARSIMPLE_H
