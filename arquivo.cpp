#include "arquivo.h"

Arquivo::Arquivo(): vetor(0)
{}

Arquivo::Arquivo(QString *newVetor): vetor(0)
{
    if (!newVetor)
        throw QString("Vetor nao criado");
    vetor = newVetor;
}
bool Arquivo::elemento_existe(const int& matricula)
{
    if (!vetor)
        throw QString("Vetor nao existe");
    if (matricula > 1000 || matricula < 0)
        throw QString("nmr matricula maior que o vetor");
    
    if (vetor[matricula] != "")
        return true;
    return false;
}

void Arquivo::abrir()
{
    if (!vetor)
        throw QString("Vetor nao existe");
    
    QString endereco_arquivo = "/home/cpedrohenrique1/Documents/development/qtcreator/Atividade12EDII/dados/DadosDosAlunos_Matricula_Nome.csv";
    QFile arquivo(endereco_arquivo);
    if (!arquivo.open(QIODevice::ReadOnly))
        throw QString("Nao foi possivel abrir o arquivo");
    
    QTextStream in(&arquivo);
    carregar_elementos(in);

    arquivo.close();
}

void Arquivo::carregar_elementos(QTextStream &in)
{
    if (!vetor)
        throw QString("vetor nao existe");

    while(!in.atEnd()){
        QString linha = in.readLine();
        QStringList parts = linha.split(";");
        int matricula = parts[0].toInt();

        if (!elemento_existe(matricula))
            vetor[matricula] = parts[1];
    }
}
