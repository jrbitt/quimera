#pragma once
class QArmazenaValor
{

private:
	float **matriz;

public:
	QArmazenaValor(int e, int a);
	~QArmazenaValor();


	void armazenaValorQ(int estado, int acao, float q);
	float getValorQ(int estado, int acao);
	int getMelhorAcao(int estado, int *acoes, int numAcoes);
};

