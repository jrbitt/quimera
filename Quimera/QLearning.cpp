#include "QLearning.h"
#include <time.h>

#include <cstdlib>

QLearning::QLearning(ProblemaAprReforco *p)
{
	armazem = new QArmazenaValor(p->getNumEstados(), p->getNumMaxAcoes());
	problema = p;
	iteracoes = 0;
	alpha = gamma = rho = nu = 0.0f;
	srand(time(NULL));
}


int QLearning::randomUm(vector<int>* acoes)
{
	return (*acoes)[rand() % acoes->size()];
}

float QLearning::random()
{
	return ((float)rand() / (RAND_MAX));
}

QLearning::~QLearning()
{
}

void QLearning::aprender()
{
	int estado = problema->getEstadoRandomico();
	for (int i = 0; i<iteracoes; i++) {
		if (random()<nu) {
			estado = problema->getEstadoRandomico();
		}

		vector<int>* acoes = problema->getAcoes(estado);
		int acao = -1;
		if (random()<rho) {
			acao = randomUm(acoes);
		}
		else {
			acao = (*acoes)[armazem->getMelhorAcao(estado, acoes)];
		}

		ProblemaAprReforco::ParProblema par = problema->tomarAcao(estado, acao);
		float q = armazem->getValorQ(estado, acao);
		float maxQ = armazem->getValorQ(par.novoEstado,armazem->getMelhorAcao(estado, acoes));
		q = (1 - alpha)*q + alpha*(par.recompensa+ gamma*maxQ);
		armazem->armazenaValorQ(estado, acao, q);
		estado = par.novoEstado;
		//if (problema->acabou()) {
			//break;
		//}
	}
}

int QLearning::agir(int estado)
{
	vector<int>* acoes = problema->getAcoes(estado);
	return armazem->getAcao(estado,acoes);
}

int QLearning::getIteracoes()
{
	return iteracoes;
}

void QLearning::setIteracoes(int it)
{
	iteracoes = it;
}

float QLearning::getAlpha()
{
	return alpha;
}

void QLearning::setAlpha(float alpha)
{
	this->alpha = alpha;
}

float QLearning::getGamma()
{
	return gamma;
}

void QLearning::setGamma(float gamma)
{
	this->gamma = gamma;
}

float QLearning::getRho()
{
	return rho;
}

void QLearning::setRho(float rho)
{
	this->rho = rho;
}

float QLearning::getNu()
{
	return nu;
}

void QLearning::setNu(float nu)
{
	this->nu = nu;
}

void QLearning::salvar(string nomeArquivo)
{
	armazem->salvar(nomeArquivo);
}

void QLearning::carregar(string nomeArquivo)
{
	armazem->carregar(nomeArquivo);
}
