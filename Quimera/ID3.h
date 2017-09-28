#pragma once
#include <map>
#include <list>
#include "Nodo.h"
#include "BaseDeExemplos.h"
using namespace std;

class NodoID3 {
public:

	BaseDeExemplos base;
	map<string, list<Exemplo*>> conjuntos;
	int atributoId;

	NodoID3();
};

class ID3
{
private:
	Nodo<NodoID3*> *arvore;

	void criarArvore(BaseDeExemplos *examples, int* attrs, Nodo<NodoID3*> *node);
	int* getAtributos(int* or, int length, int exc);
	float entropiaDosConjuntos(map<string,list<Exemplo*>> *sets, int exampleCount);
	map<string, list<Exemplo*>>* dividirPorAtributo(BaseDeExemplos *examples, int attr);
	float entropia(BaseDeExemplos *examples);
	float log(float prop);
	void contaAcoes(map<string,int> *actions, BaseDeExemplos *examples);

public:
	ID3();
	~ID3();

	void criarArvore(BaseDeExemplos *examples);
	Nodo<NodoID3*>* getArvore();
};




