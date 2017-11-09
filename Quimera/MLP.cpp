#include "MLP.h"
#include <time.h>


MLP::MLP(int e, int h, int s)
{
	srand(time(NULL));
	for (int i = 0; i < e; i++) {
		Perceptron* p = new Perceptron();
		p->inicializar();
		entradas.push_back(p);
	}
	for (int i = 0; i < h; i++) {
		Perceptron* p = new Perceptron();
		p->inicializar();
		camadaOculta.push_back(p);
	}
	for (int i = 0; i < s; i++) {
		Perceptron* p = new Perceptron();
		p->inicializar();
		saidas.push_back(p);
	}
	numEntradas = e;
	numSaidas = s;
	numOcultas = h;
}


MLP::~MLP()
{
}

void MLP::aprenderPadrao(float * entrada, float * saida)
{
	gerarSaida(entrada);
	backprop(saida);
}

void MLP::gerarSaida(float * entrada)
{
	int i = 0;
	vector<Perceptron*>::iterator it;
	for (it = entradas.begin(); it != entradas.end(); it++) {
		(*it)[i].setEstado(entrada[i]);
		i++;
	}
	for (it = camadaOculta.begin(); it != camadaOculta.end(); it++) {
		(*it)->propagar();
	}
	for (it = saidas.begin(); it != saidas.end(); it++) {
		(*it)->propagar();
	}
}

void MLP::backprop(float * saida)
{
	int i = 0;
	vector<Perceptron*>::iterator it;
	for (it = saidas.begin(); it != saidas.end(); it++) {
		Perceptron *perceptron = (*it);
		float estado = perceptron->getEstado();
		float erro = estado*(1 - estado)*(saida[i++] - estado);
		perceptron->ajustarPesos(erro);
	}
	for (it = camadaOculta.begin(); it != camadaOculta.end(); it++) {
		Perceptron *perceptron = (*it);
		float estado = perceptron->getEstado();
		
		float soma = 0;
		for (int j = 0; j < numSaidas; j++) {
			soma = saidas[i]->getPesoEntrada(perceptron)*saidas[i]->getErro();
		}
		float erro = estado*(1 - estado)*soma;
		perceptron->ajustarPesos(erro);
	}
}
