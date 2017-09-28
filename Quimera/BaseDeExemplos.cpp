#include "BaseDeExemplos.h"



BaseDeExemplos::BaseDeExemplos(int ni, int no)
{
	numEntradas = ni;
	numSaidas = no;
}

BaseDeExemplos::BaseDeExemplos(string name)
{
	ler(name);
}

BaseDeExemplos::BaseDeExemplos(vector<Exemplo*> set)
{
	vector<Exemplo*>::iterator it = set.begin();
	for(it; it!=set.end(); it++){
		Exemplo *e = *it;
		numEntradas = e->getNumEntradas();
		numSaidas = e->getNumSaidas();
		addExemplo(e);
	}
}

BaseDeExemplos::~BaseDeExemplos()
{
}

void BaseDeExemplos::addExemplo(Exemplo * e)
{
	exemplos.push_back(e);
}

Exemplo * BaseDeExemplos::getExemplo(int index)
{
	return exemplos[index];
}

int BaseDeExemplos::getTamanho()
{
	return exemplos.size();
}

void BaseDeExemplos::salvar(string name)
{
	ofstream arquivo(name);
	arquivo << numEntradas << " ";
	arquivo << numSaidas << endl;
	
	vector<Exemplo*>::iterator it = exemplos.begin();
	for(it; it!=exemplos.end();it++){
		Exemplo *e = *it;
		float *ent = e->getEntradas();
		float *sai = e->getSaidas();
		for (int i = 0; i < numEntradas; i++) {
			arquivo << ent[i] << " ";
		}
		for (int i = 0; i < numSaidas; i++) {
			if (i != numSaidas - 1) {
				arquivo << sai[i];
			}
		}
	}
	arquivo.close();
}

void BaseDeExemplos::ler(string name)
{
	ifstream arquivo(name);
	arquivo >> numEntradas;
	arquivo >> numSaidas;
	Exemplo *e;
	while (!arquivo.eof()) {
		e = new Exemplo(numEntradas, numSaidas);
		string *ent = new string[numEntradas];
		string *sai = new string[numSaidas];
		for (int i = 0; i < numEntradas;i++) {
			arquivo >> ent[i];
		}
		for (int i = 0; i < numSaidas; i++) {
			arquivo >> sai[i];
		}
		e->setEntradas(ent);
		e->setSaidas(sai);

		if (!arquivo.fail()) {
			addExemplo(e);
		}
	}
	arquivo.close();
}

int BaseDeExemplos::getNumEntradas()
{
	return numEntradas;
}

int BaseDeExemplos::getNumSaidas()
{
	return numSaidas;
}
