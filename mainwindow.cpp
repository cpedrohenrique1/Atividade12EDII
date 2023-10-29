#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operar_tabela = new OperarTabela(ui->tableWidget_saida_dados, vetor);
    operar_tabela->start();
    arquivo = new Arquivo(vetor);
    arquivo->abrir();
    operar_tabela->atualizar();
}

MainWindow::~MainWindow()
{
    if (operar_tabela)
        delete operar_tabela;
    if (arquivo)
        delete arquivo;
    delete ui;
}

