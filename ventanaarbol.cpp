#include "ventanaarbol.h"
#include "ui_ventanaarbol.h"

ventanaarbol::ventanaarbol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ventanaarbol)
{
    ui->setupUi(this);
}

ventanaarbol::~ventanaarbol()
{
    delete ui;
}
