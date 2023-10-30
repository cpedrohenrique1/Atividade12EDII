#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Arquivo
{
private:
    QString *vetor;
    int tamanho_vetor;
public:
    Arquivo();
    Arquivo(QString *newVetor, int tamanho_vetor);
    bool elemento_existe(const int& matricula);
    void abrir();
    void carregar_elementos(QTextStream &in);
};

#endif // ARQUIVO_H
