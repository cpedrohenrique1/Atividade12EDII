#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Arquivo
{
private:
    QString *vetor;
public:
    Arquivo();
    Arquivo(QString *newVetor);
    bool elemento_existe(const int& matricula);
    void abrir();
    void carregar_elementos(QTextStream &in);
};

#endif // ARQUIVO_H
