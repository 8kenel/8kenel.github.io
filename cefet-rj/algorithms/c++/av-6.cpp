#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int quantidadeDeRegistros(ifstream &arquivo)
{
  string reg;
  int qtd = 0;

  getline (arquivo, reg);
  while (!arquivo.eof())
    {
        getline (arquivo, reg);
        qtd = qtd+1;
    }

  arquivo.clear();
  arquivo.seekg(0);
  return qtd;
}

void arquivoParaVetor(ifstream &arquivo, string v[], int tamanho)
{
    string nome;
    int i=0;

    while (!arquivo.eof())
    {
        arquivo >> v[i];
        i++;
    }

    arquivo.clear();
    arquivo.seekg(0);
}

void vetorParaArquivo(ofstream &arquivo, string v[], int tamanho)
{
  int i;

  for(i=0; i < tamanho; i++)
    {
        arquivo << "\n" << v[i];
    }
}

void imprimeArquivo(ifstream &arquivo)
{
    string nome;

    arquivo.seekg(0);
    while (!arquivo.eof())
    {
        cout << nome << "\n";
    }

    arquivo.clear();
    arquivo.seekg(0);
}

void troca(string &s1, string &s2)
{
string aux;
aux = s1;
s1 = s2;
s2 = aux;
}

void ordena(string v[], int tamanho)
{
int i, j;
for (i = 0; i < tamanho-1; i++)
for (j = i+1; j < tamanho; j++)
if (v[i] > v[j])
troca(v[i], v[j]);
}

main()
{
//Declara��o de vari�veis n�o arranjos.
string s;
ifstream entrada;
ofstream saida;
int i, qtdRegistros;

//Defini��o da quantidade de registros no arquivo de entrada.
entrada.open("Nomes.txt");
qtdRegistros = quantidadeDeRegistros(entrada);

//Declara��o do vetor.
string vetor[qtdRegistros];

//Ordena��o no vetor dos nomes contidos no arquivo.
arquivoParaVetor(entrada, vetor, qtdRegistros);
ordena(vetor, qtdRegistros);
entrada.close();

//Cria��o de um arquivo com os nomes ordenados.
saida.open("Dados.txt");
vetorParaArquivo(saida, vetor, qtdRegistros);
saida.close();

//Impress�o do arquivo rec�m criado.
entrada.open("Dados.txt");
imprimeArquivo(entrada);
entrada.close();
}
