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


void MainWindow::on_pushButton_consultar_clicked()
{
    try
    {
        bool ok;
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (ok){
            operar_tabela->buscaElemento(matricula);
        }else if (!nomeCompleto.isEmpty()){
            operar_tabela->buscaElemento(nomeCompleto);
        }else{
            operar_tabela->atualizar();
        }
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_inserir_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        if (!ok){
            throw QString("matricula nao pode estar vazia");
        }
        operar_tabela->inserirElemento(matricula, nomeCompleto);
        operar_tabela->atualizar();
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
    
}


void MainWindow::on_pushButton_alterar_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        if (!ok)
            throw QString("n° matricula nao pode estar vazio");
        operar_tabela->alterarElemento(matricula, nomeCompleto);
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
}


void MainWindow::on_pushButton_remover_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("n° matricula nao pode estar vazio");
        operar_tabela->removerElemento(matricula);
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
}

