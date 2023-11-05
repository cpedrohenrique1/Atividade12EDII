#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , operar_tabela(0)
    , arquivo(0)
{
    ui->setupUi(this);
    try{
        operar_tabela = new OperarTabela(ui->tableWidget_saida_dados, 1000);
        operar_tabela->start();
        arquivo = new Arquivo(operar_tabela->getVetor(), operar_tabela->getTamanhoVetor());
        arquivo->abrir();
        operar_tabela->atualizar();
    }
    catch (std::bad_alloc& e){
        QMessageBox::critical(this, "Erro", "Nao foi possivel alocar memoria para a criacao da tabela");
    }
    catch (QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch (...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
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
        if (ok)
            QMessageBox::about(this, "Concluido", "Matricula: " + QString::number(matricula) + "\nNome Completo: " + operar_tabela->buscaElemento(matricula));
        else if (!nomeCompleto.isEmpty())
            QMessageBox::about(this, "Concluido", operar_tabela->buscaElemento(nomeCompleto));
        else
            operar_tabela->atualizar();
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_inserir_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        if (!ok)
            throw QString("matricula nao pode estar vazia");
        
        operar_tabela->inserirElemento(matricula, nomeCompleto);
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + "\nNome Completo:" + operar_tabela->buscaElemento(matricula) +" inserido");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
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
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + " alterado");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
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
        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + " removido");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
    
}

