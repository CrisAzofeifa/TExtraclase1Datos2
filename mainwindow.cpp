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

void MainWindow::on_ListaSimpleBTN_clicked()
{
    VentanaListaSimple *ventana = new VentanaListaSimple;
    ventana->show();
}


void MainWindow::on_ListaDobleBTN_clicked()
{
    ventanalistadoble *ventana = new ventanalistadoble;
    ventana->show();
}

void MainWindow::on_ListaCircularBTN_clicked()
{
    ventanacircularsimple *ventana = new ventanacircularsimple;
    ventana->show();
}
