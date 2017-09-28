#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Exemplo.h"

using namespace std;

class BaseDeExemplos
{
private:
	int numEntradas;
	int numSaidas;
	vector<Exemplo*> exemplos;

public:
	BaseDeExemplos(int ni, int no);
	BaseDeExemplos(string name);
	BaseDeExemplos(vector<Exemplo*> set);
	~BaseDeExemplos();

	void addExemplo(Exemplo *e);

	Exemplo* getExemplo(int index);
	int getTamanho();

	void salvar(string name);
	void ler(string name);

	int getNumEntradas();
	int getNumSaidas();

};
	
