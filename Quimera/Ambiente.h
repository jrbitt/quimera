#pragma once
#include <map>
#include <string>
#include "Vetor2D.h"
using namespace std;

class Ambiente
{
public:

	static Ambiente& getInstancia();

	void set(string chave, bool v);
	void set(string chave, int v);
	void set(string chave, float v);
	void set(string chave, double v);
	void set(string chave, string v);
	void set(string chave, Vetor2D* v);
	bool getBool(string chave);
	int getInt(string chave);
	float getFloat(string chave);
	double getDouble(string chave);
	string getString(string chave);
	Vetor2D* getVetor2D(string chave);

private:
	Ambiente();
	~Ambiente();

	map<string, bool> mapaBool;
	map<string, int> mapaInt;
	map<string, float> mapaFloat;
	map<string, double> mapaDouble;
	map<string, string> mapaString;
	map<string, Vetor2D*> mapaVetor2D;

	static Ambiente *instancia;
};

