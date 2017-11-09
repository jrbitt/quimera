#pragma once
#include <vector>
using namespace std;

class QArmazenaValor
{

private:
	float **matriz;
	int estados;
	int acoes;

public:
	QArmazenaValor(int e, int a);
	~QArmazenaValor();


	void armazenaValorQ(int estado, int acao, float q);
	float getValorQ(int estado, int acao);
	int getMelhorAcao(int estado, vector<int>* acoes);
	int getAcao(int estado, vector<int>* acoes);

	void salvar(string nomeArquivo);
	void carregar(string nomeArquivo);
};

