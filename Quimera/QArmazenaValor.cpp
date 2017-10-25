#include "QArmazenaValor.h"

#include <cstdlib>

QArmazenaValor::QArmazenaValor(int e, int a)
{
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
