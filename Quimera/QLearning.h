#pragma once
#include <vector>
#include "ProblemaAprReforco.h"
#include "QArmazenaValor.h"
using namespace std;

class QLearning
{
private:
	QArmazenaValor *armazem;
	ProblemaAprReforco *problema;
	
	int iteracoes;
	float alpha, gamma, rho, nu;

	int randomUm(vector<int>* acoes);
	float random();

public:
	QLearning(ProblemaAprReforco *p);
	~QLearning();

	void aprender();

	int getIteracoes();

	void setIteracoes(int it);

	float getAlpha();

	void setAlpha(float alpha);

	float getGamma();

	void setGamma(float gamma);

	float getRho();

	void setRho(float rho);

	float getNu();

	void setNu(float nu);
};

