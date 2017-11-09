#include "MLP.h"
#include <time.h>


MLP::MLP(int e, int h, int s)
{
	srand(time(NULL));
	for (int i = 0; i < e; i++) {
		Perceptron* p = new Perceptron();
		entradas.push_back(p);
	}
	for (int i = 0; i < h; i++) {
		Perceptron* p = new Perceptron();
		for (int j = 0; j < e;j++) {
			Perceptron::Entrada *e = new Perceptron::Entrada;
			e->perceptronEntrada = entradas[j];
			p->addEntrada(e);
		}
		p->inicializar();
		camadaOculta.push_back(p);
	}
	for (int i = 0; i < s; i++) {
		Perceptron* p = new Perceptron();
		for (int j = 0; j < h; j++) {
			Perceptron::Entrada *e = new Perceptron::Entrada;
			e->perceptronEntrada = camadaOculta[j];
			p->addEntrada(e);
		}
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

float MLP::aprenderPadrao(float * entrada, float * saida)
{
	gerarSaida(entrada);
	backprop(saida);
	return getErroMedio(saida);
}

void MLP::setTaxaAprendizagem(float ganho)
{
	for (int i = 0; i < numEntradas; i++) {
		entradas[i]->setGanho(ganho);
	}
	for (int i = 0; i < numOcultas; i++) {
		camadaOculta[i]->setGanho(ganho);
	}
	for (int i = 0; i < numSaidas; i++) {
		saidas[i]->setGanho(ganho);
	}
}

float MLP::getErroMedio(float * saida)
{
	float erro = 0.0;
	for (int i = 0; i < numSaidas; i++) {
		erro += abs(saidas[i]->getEstado() - saida[i]);
	}
	return erro / numSaidas;
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
		float erro = (saida[i++] - estado);
		perceptron->ajustarPesos(erro);
	}
	for (it = camadaOculta.begin(); it != camadaOculta.end(); it++) {
		Perceptron *perceptron = (*it);
		float estado = perceptron->getEstado();
		
		float soma = 0;
		for (int j = 0; j < numSaidas; j++) {
			soma = saidas[j]->getPesoEntrada(perceptron)*saidas[j]->getErro();
		}
		//float erro = estado*(1 - estado)*soma;
		perceptron->ajustarPesos(soma);
	}
}
