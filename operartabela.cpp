#include "operartabela.h"

OperarTabela::OperarTabela() : tabela(0),
                               vetor(0)
{
}

OperarTabela::OperarTabela(QTableWidget *parent, QString *vetor) : tabela(0),
                                                                   vetor(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    
    if (!vetor)
        throw QString("vetor nao criado");
    
    this->tabela = parent;
    this->vetor = vetor;
}

OperarTabela::~OperarTabela()
{}

void OperarTabela::start()
{
    if (!tabela)
        throw QString("tabela nao localizada");
    
    tabela->setColumnCount(2);
    QStringList cabecalho = {"Matricula", "Nome"};
    tabela->setHorizontalHeaderLabels(cabecalho);
    tabela->setColumnWidth(0, 100); // Matricula
    tabela->setColumnWidth(1, 650); // Nome
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
}

void OperarTabela::limpar()
{
    if (!tabela)
        throw QString("tabela nao localizada");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void OperarTabela::atualizar()
{
    if (!tabela)
        throw QString("tabela nao localizada");
    
    if (!vetor)
        throw QString("vetor nao localizado");
    

    limpar();

    int j = 0;
    for (int i = 0; i < 1000; ++i){
        if (vetor[i] != ""){
            tabela->insertRow(j);
            tabela->setItem(j, 0, new QTableWidgetItem(QString::number(i)));
            tabela->setItem(j, 1, new QTableWidgetItem(vetor[i]));
            ++j;
        }
    }
}

void OperarTabela::buscaElemento(const int& matricula)
{
    if (!tabela)
        throw QString("tabela nao localizada");
    
    if (!vetor)
        throw QString("vetor nao localizado");
    
    limpar();

    tabela->insertRow(0);
    tabela->setItem(0, 0, new QTableWidgetItem(QString::number(matricula)));
    tabela->setItem(0, 1, new QTableWidgetItem(vetor[matricula]));
}
