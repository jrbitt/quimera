#include "Perceptron.h"
#include <cmath>
#include <cstdlib>

float Perceptron::threshold(float i)
{
	return 1.0f/(1.0+exp(-alfa*i));
}

Perceptron::Perceptron()
{
	erro = 0;
	alfa = 10;
}


Perceptron::~Perceptron()
{
}

void Perceptron::addEntrada(Perceptron::Entrada * e)
{
	entradas.push_back(e);
}

float Perceptron::getEstado()
{
	return estado;
}

void Perceptron::setEstado(float e)
{
	estado = e;
}

float Perceptron::getErro()
{
	return erro;
}

float Perceptron::getGanho()
{
	return ganho;
}

void Perceptron::setGanho(float g)
{
	ganho = g;
}

void Perceptron::propagar()
{
	float soma = 0;
	vector<Perceptron::Entrada*>::iterator it;
	for (it = entradas.begin(); it != entradas.end(); it++) {
		Perceptron::Entrada* entrada = (*it);
		soma += entrada->perceptronEntrada->getEstado()*entrada->peso;
	}
	estado = threshold(soma);
}

void Perceptron::ajustarPesos(float erroAtual)
{
	vector<Perceptron::Entrada*>::iterator it;
	for (it = entradas.begin(); it != entradas.end(); it++) {
		Perceptron::Entrada* entrada = (*it);
		float delta = (ganho*erroAtual*entrada->perceptronEntrada->getEstado());
		entrada->peso += delta;
	}
	erro = erroAtual;
}

float Perceptron::getPesoEntrada(Perceptron * p)
{
	vector<Entrada*>::iterator it;
	for (it = entradas.begin(); it != entradas.end(); it++) {
		if ((*it)->perceptronEntrada == p) {
			return (*it)->peso;
		}
	}
	return 0.0f;
}

void Perceptron::limpar()
{
	estado = 0;
	erro = 0;
}

void Perceptron::inicializar()
{
	vector<Entrada*>::iterator it;
	for (it = entradas.begin(); it != entradas.end(); it++) {
		(*it)->peso = ((float)rand() / (RAND_MAX));
	}
}
