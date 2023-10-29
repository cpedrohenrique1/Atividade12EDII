#ifndef OPERARTABELA_H
#define OPERARTABELA_H

#include "QTableWidget"
#include "QHeaderView"

class OperarTabela
{
private:
    QTableWidget *tabela;
    QString *vetor;

public:
    OperarTabela();
    OperarTabela(QTableWidget *parent, QString *vetor);
    ~OperarTabela();
    void start();
    void limpar();
    void atualizar();
    void buscaElemento(const int& matricula);
};

#endif // OPERARTABELA_H
