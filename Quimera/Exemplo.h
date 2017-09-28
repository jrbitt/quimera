#pragma once
#include <string>
using namespace std;

class Exemplo
{
private:
	string *entradas;
	string *saidas;
	int nentradas;
	int nsaidas;

public:
	Exemplo();
	Exemplo(int ni, int no);
	~Exemplo();

	void setEntradas(float* e);

	void setSaidas(float* s);

	float* getEntradas();

	float* getSaidas();

	int getNumEntradas();

	int getNumSaidas();

	void setEntradas(string* e);

	void setSaidas(string* s);

	string getSaida(int i);

	string getValor(int a);
};