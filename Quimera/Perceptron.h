#pragma once
#include <vector>
using namespace std;

class Perceptron
{
public:
	class Entrada{
	public:
		Perceptron* perceptronEntrada;
		float peso;
	};

private:
	vector<Entrada*> entradas;
	float estado;
	float erro;

	float alfa;
	float ganho;

	float threshold(float i);

public:
	Perceptron();
	~Perceptron();

	void addEntrada(Entrada *e);

	float getEstado();
	void setEstado(float e);
	float getErro();
	float getGanho();
	void setGanho(float g);

	void propagar();
	void ajustarPesos(float erroAtual);

	float getPesoEntrada(Perceptron *p);

	void limpar();
	void inicializar();

	float derivada();
};

