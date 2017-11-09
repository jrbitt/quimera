#include "QArmazenaValor.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

QArmazenaValor::QArmazenaValor(int e, int a)
{
	estados = e;
	acoes = a;
	matriz = new float*[e];
	for (int i = 0; i<e; i++) {
		matriz[i] = new float[a];
		for (int j = 0; j<a; j++) {
			matriz[i][j] = ((float)rand() / (RAND_MAX));
		}
	}
}


QArmazenaValor::~QArmazenaValor()
{
}

void QArmazenaValor::armazenaValorQ(int estado, int acao, float q)
{
	matriz[estado][acao] = q;
}

float QArmazenaValor::getValorQ(int estado, int acao)
{
	return matriz[estado][acao];
}

int QArmazenaValor::getMelhorAcao(int estado, vector<int>* acoes)
{
	int melhori = 0;
	float melhorq = -1.0f;
	for (int i = 0; i<acoes->size(); i++) {
		if (matriz[estado][(*acoes)[i]]>melhorq) {
			melhorq = matriz[estado][(*acoes)[i]];
			melhori = i;
		}
	}
	return melhori;
}

int QArmazenaValor::getAcao(int estado, vector<int>* acoes)
{
	int melhori = 0;
	float melhorq = INT_MIN;
	for (int i = 0; i<acoes->size(); i++) {
		if (matriz[estado][(*acoes)[i]]>melhorq) {
			melhorq = matriz[estado][(*acoes)[i]];
			melhori = (*acoes)[i];
		}
	}
	return melhori;
}

void QArmazenaValor::salvar(string nomeArquivo)
{
	ofstream saida(nomeArquivo);
	saida << estados << " " << acoes << endl;
	for (int i = 0; i<estados; i++) {
		for (int j = 0; j<acoes; j++) {
			saida << matriz[i][j] << endl;
		}
	}
	saida.close();
}
