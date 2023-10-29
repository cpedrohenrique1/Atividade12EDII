#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ot = new OperarTabela(ui->tableWidget_saida_dados, vetor);
    ot->start();
    
    ot->popular();
}

MainWindow::~MainWindow()
{
    if (ot)
        delete ot;
    delete ui;
}

