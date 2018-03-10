#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Abre la ventana para manipular lista simple
 */
void MainWindow::on_ListaSimpleBTN_clicked()
{
    VentanaListaSimple *ventana = new VentanaListaSimple;
    ventana->show();
}

/*
 * Abre la ventana para manipular lista doble
 */
void MainWindow::on_ListaDobleBTN_clicked()
{
    ventanalistadoble *ventana = new ventanalistadoble;
    ventana->show();
}

/*
 * Abre la ventana para manipular lista circular simple
 */
void MainWindow::on_ListaCircularBTN_clicked()
{
    ventanacircularsimple *ventana = new ventanacircularsimple;
    ventana->show();
}
