#ifndef OPERARTABELA_H
#define OPERARTABELA_H

#include "QTableWidget"

class OperarTabela{
public:
    void start(QTableWidget *parent);
    void limpar(QTableWidget *parent);
    void popular(QTableWidget *parent, int &tamanho_vetor, Professor *prof);
    void buscaElemento(QTableWidget *parent, Professor &prof);
};

#endif // OPERARTABELA_H
