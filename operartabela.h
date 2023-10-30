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
    void start();
    void limpar();
    void atualizar();
    void buscaElemento(const int& matricula);
    void buscaElemento(const QString& nomeCompleto);
    void inserirElemento(int& matricula, QString& nomeCompleto);
    void alterarElemento(int& matricula, QString& nomeCompleto);
    void removerElemento(int& matricula);
};

#endif // OPERARTABELA_H
