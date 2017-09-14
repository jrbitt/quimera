#include "Ambiente.h"


Ambiente* Ambiente::instancia = NULL;

Ambiente& Ambiente::getInstancia()
{
	if (instancia == NULL) {
		instancia = new Ambiente;
	}
	return *instancia;
}

void Ambiente::set(string chave, bool v) { mapaBool[chave] = v; }
void Ambiente::set(string chave, int v) { mapaInt[chave] = v; }
void Ambiente::set(string chave, float v) { mapaFloat[chave] = v; }
void Ambiente::set(string chave, double v) { mapaDouble[chave] = v; }
void Ambiente::set(string chave, string v) { mapaString[chave] = v; }
bool Ambiente::getBool(string chave) { return mapaBool[chave]; }
int Ambiente::getInt(string chave) { return mapaBool[chave]; }
float Ambiente::getFloat(string chave) { return mapaFloat[chave]; }
double Ambiente::getDouble(string chave) { return mapaDouble[chave]; }
string Ambiente::getString(string chave) { return mapaString[chave]; }

Ambiente::Ambiente()
{
}


Ambiente::~Ambiente()
{
}

