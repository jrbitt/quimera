#include "Exemplo.h"
#include <string>
using namespace std;


Exemplo::Exemplo()
{
	nentradas = nsaidas = 0;
}


Exemplo::Exemplo(int ni, int no)
{
	nentradas = ni;
	nsaidas = no;
	entradas = new string[ni];
	saidas = new string[no];
}

Exemplo::~Exemplo()
{
}

void Exemplo::setEntradas(float * e)
{
	for (int i = 0; i<nentradas; i++) {
		entradas[i] = to_string(e[i]);
	}
}

void Exemplo::setSaidas(float* s)
{
	for (int i = 0; i<nsaidas; i++) {
		saidas[i] = to_string(s[i]);
	}
}

float * Exemplo::getEntradas()
{
	float* temp = new float[nentradas];
	for (int i = 0; i<nentradas; i++) {
		temp[i] = stof(entradas[i]);
	}
	return temp;
}

float * Exemplo::getSaidas()
{
	float* temp = new float[nsaidas];
	for (int i = 0; i<nsaidas; i++) {
		temp[i] = stof(saidas[i]);
	}
	return temp;
}

int Exemplo::getNumEntradas()
{
	return nentradas;
}

int Exemplo::getNumSaidas()
{
	return nsaidas;
}

void Exemplo::setEntradas(string * e)
{
	entradas = e;
}

void Exemplo::setSaidas(string * s)
{
	saidas = s;
}

string Exemplo::getSaida(int i)
{
	return saidas[i];
}

string Exemplo::getValor(int a)
{
	return entradas[a];
}