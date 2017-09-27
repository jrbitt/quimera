#pragma once
#include <list>
#include <algorithm>
using namespace std;
#include "Comando.h"

template<class V>
class Nodo
{
protected:
	int indice;
	V valor;				//Valor armazenado no nodo
	bool visitado;		//Se o nodo já foi visitado
	Nodo<V> *pai;			//Nodo pai
	Comando *op;		//Um operador padrao
	int profundidade = 0;			//Profundidade
	float custo;			//Custo

	list<Node<V>> filhos;

public:
	Nodo()
	{
		indice = -1;
	}

	Nodo(int i)
	{
		indice = i;
	}


	~Nodo()
	{
	}
	
	int getIndice()
	{
		return indice;
	}

	void setIndice(int i)
	{
		indice = i;
	}

	V getValor() {
		return valor;
	}

	void setValor(V v) {
		this.valor = va;
	}

	bool isVisitado() {
		return visitado;
	}

	void setVisitado(bool v) {
		this.visitado = v;
	}

	int numeroDeFilhos() {
		return filhos.size();
	}

	list<Node<V>>::iterator elementos() {
		return children.iterator();
	}

	void adicionar(Nodo<V> nn, Comando *cmd) {
		nn.setComando(cmd);
		filhos.push_back(nn);
	}

	bool contem(V v) {
		return (find(filhos.begin(), filhos.end(), v) != filhos.end());
	}

	Nodo<V> getPai() {
		return pai;
	}

	void setPai(Nodo<V> p) {
		this.pai = p;
	}

	Comando* getComando() {
		return op;
	}

	void setComando(Comando* op) {
		this.op = op;
	}

	int getProfundidade() {
		return profundidade;
	}

	void setProfundidade(int d) {
		this.profundidade = d;
	}

	float getCusto() {
		return custo;
	}

	void setCusto(float c) {
		this.custo = c;
	}
};