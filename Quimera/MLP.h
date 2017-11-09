#pragma once
#include "Perceptron.h"
#include <vector>
using namespace std;

class MLP
{
private:
	vector<Perceptron*> entradas;
	vector<Perceptron*> camadaOculta;
	vector<Perceptron*> saidas;
	int numEntradas;
	int numOcultas;
	int numSaidas;

	void gerarSaida(float *entrada);
	void backprop(float *saida);

public:
	MLP(int e, int h, int s);
	~MLP();

	void aprenderPadrao(float* entrada, float * saida); 
};

