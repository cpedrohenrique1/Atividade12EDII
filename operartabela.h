#ifndef OPERARTABELA_H
#define OPERARTABELA_H

#include "QTableWidget"
#include "QHeaderView"

class OperarTabela
{
private:
    QTableWidget *tabela;
    QString *vetor;
    int tamanho_vetor;

public:
    OperarTabela();
    OperarTabela(QTableWidget *parent, int tamanho_vetor);
    ~OperarTabela();
    void start();
    void limpar();
    void atualizar();
    QString buscaElemento(const int& matricula);
    QString buscaElemento(const QString& nomeCompleto);
    void inserirElemento(int& matricula, QString& nomeCompleto);
    void alterarElemento(int& matricula, QString& nomeCompleto);
    void removerElemento(int& matricula);
    QString *getVetor()const;
    int getTamanhoVetor()const;
};

#endif // OPERARTABELA_H
