#include "operartabela.h"

OperarTabela::OperarTabela() : tabela(0),
                               vetor(0),
                               tamanho_vetor(0)
{}

OperarTabela::OperarTabela(QTableWidget *parent, int tamanho_vetor):   tabela(0),
                                                                        vetor(0),
                                                                        tamanho_vetor(0)
{
    if (!parent)
        throw QString("tabela nao criada");
    
    this->tabela = parent;
    if (tamanho_vetor <= 0){
        throw QString("Tamanho invalido, valor precisa ser maior que 0");
    }

    this->tamanho_vetor = tamanho_vetor;
    try
    {
        vetor = new QString[tamanho_vetor];
    }
    catch(const std::bad_alloc& e)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

QString *OperarTabela::getVetor() const{
    return vetor;
}

int OperarTabela::getTamanhoVetor()const{
    return tamanho_vetor;
}

OperarTabela::~OperarTabela(){
    if (vetor)
        delete[] vetor;
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

    for (int i = 0; i < tamanho_vetor; ++i){
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        tabela->setItem(i, 1, new QTableWidgetItem(vetor[i]));
    }
}

QString OperarTabela::buscaElemento(const int& matricula)
{
    if (matricula >= tamanho_vetor || matricula < 0)
        throw QString("Numero invalido, tem que ser entre 0 e 999");
        
    if (!vetor)
        throw QString("vetor nao localizado {buscaelemento}");
    if (vetor[matricula] == "")
        return "Nao encontrado";
    return vetor[matricula];
}

QString OperarTabela::buscaElemento(const QString &nomeCompleto)
{
    if (!vetor)
        throw QString("vetor nao localizado");

    for (int i = 0; i < tamanho_vetor; ++i){
        if (vetor[i] == nomeCompleto.toUpper()){
            return "Matricula: " + QString::number(i) + "\nNome Completo: " + vetor[i];
        }
    }
    return "Nao encontrado";
}

void OperarTabela::inserirElemento(int& matricula, QString& nomeCompleto)
{
    if (matricula < 0 || matricula >= tamanho_vetor)
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
    if (matricula < 0 || matricula >= tamanho_vetor)
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
    if (matricula < 0 || matricula >= tamanho_vetor)
        throw QString("numero de matricula nao condiz com os padroes {removerElemento}");
    if (vetor[matricula] == "")
        throw QString("elemento ja foi removido {removerElemento}");
    vetor[matricula] = "";
    atualizar();
}
