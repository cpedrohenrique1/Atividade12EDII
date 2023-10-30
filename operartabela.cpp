#include "operartabela.h"

OperarTabela::OperarTabela() : tabela(0),
                               vetor(0)
{}

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

void OperarTabela::start()
{
    if (!tabela)
        throw QString("tabela nao localizada {start}");
    
    tabela->setColumnCount(2);
    QStringList cabecalho = {"Matricula", "Nome Completo"};
    tabela->setHorizontalHeaderLabels(cabecalho);
    tabela->setColumnWidth(0, 100); // Matricula
    tabela->setColumnWidth(1, 650); // Nome
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
}

void OperarTabela::limpar()
{
    if (!tabela)
        throw QString("tabela nao localizada, {limpartabela}");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void OperarTabela::atualizar()
{
    if (!tabela)
        throw QString("tabela nao localizada {atualizar}");
    
    if (!vetor)
        throw QString("vetor nao localizado {atualizar}");
    
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
    if (matricula >= 1000 || matricula < 0)
        throw QString("Numero invalido, tem que ser entre 0 e 999");
    if (!tabela)
        throw QString("tabela nao localizada {buscaelemento}");
    if (!vetor)
        throw QString("vetor nao localizado {buscaelemento}");
    
    limpar();

    tabela->insertRow(0);
    tabela->setItem(0, 0, new QTableWidgetItem(QString::number(matricula)));
    tabela->setItem(0, 1, new QTableWidgetItem(vetor[matricula]));
}

void OperarTabela::buscaElemento(const QString &nomeCompleto)
{
    if (!tabela)
        throw QString("tabela nao localizada");
    if (!vetor)
        throw QString("vetor nao localizado");

    limpar();

    for (int i = 0; i < 1000; ++i){
        if (vetor[i] == nomeCompleto.toUpper()){
            tabela->insertRow(0);
            tabela->setItem(0, 0, new QTableWidgetItem(QString::number(i)));
            tabela->setItem(0, 1, new QTableWidgetItem(vetor[i]));
            return;
        }
    }
}

void OperarTabela::inserirElemento(int& matricula, QString& nomeCompleto)
{
    if (matricula < 0 || matricula >= 1000)
        throw QString("numero de matricula nao condiz com os padroes {inserirElemento}");
    
    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao 'remover' {inserirElemento}");
    
    if (!vetor)
        throw QString("vetor nao localizado {inserirElemento}");
    
    if (vetor[matricula] != "")
        throw QString("Este elemento ja existe, se deseja alterar, use o botao 'alterar' {inserirElemento}");
    
    vetor[matricula] = nomeCompleto.toUpper();
    atualizar();
}

void OperarTabela::alterarElemento(int &matricula, QString &nomeCompleto)
{
    if (matricula < 0 || matricula >= 1000)
        throw QString("numero de matricula nao condiz com os padroes {alterarElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome nao pode estar vazio, se deseja remover use o botao remover {alterarElemento}");

    if (!vetor)
        throw QString("vetor nao localizado {alterarElemento}");
    
    if (vetor[matricula].isEmpty())
        throw QString("Elemento nao existe, se deseja adicionar use o botao 'inserir' {alterarElemento}");
    
    vetor[matricula] = nomeCompleto.toUpper();
    atualizar();
}

void OperarTabela::removerElemento(int &matricula)
{
    if (!vetor)
        throw QString("vetor nao localizado {removerElemento}");
    if (matricula < 0 || matricula >= 1000)
        throw QString("numero de matricula nao condiz com os padroes {removerElemento}");
    if (vetor[matricula] == "")
        throw QString("elemento ja foi removido {removerElemento}");
    vetor[matricula] = "";
    atualizar();
}
