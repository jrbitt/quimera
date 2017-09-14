#pragma once
#include <vector>
#include <list>

using namespace std;

template<class TipoNodo, class TipoAresta>
class Grafo {
public:

	typedef TipoAresta TipoDeAresta;
	typedef TipoNodo TipoDeNodo;

	typedef vector<TipoNodo> VetorDeNodos;
	typedef list<TipoAresta> ListaDeArestas;
	typedef vector<ListaDeArestas> VetorDeListasDeArestas;

private:
	VetorDeNodos nodos;
	VetorDeListasDeArestas arestas;

	bool dirigido;
	int proximoIndice;

public:

	Grafo(bool d) {
		proximoIndice = 0;
		dirigido = d;
	}

	const TipoDeNodo& getNodo(int i)const {
		return nodos[i];
	}
	TipoDeNodo& getNodo(int i) {
		return nodos[i];
	}
	const TipoDeAresta& getAresta(int de, int para)const {
		for (ListaDeArestas::const_iterator curAresta = arestas[de].begin();
			curArestas != arestas[de].end();
			++curArestas)
		{
			if (curArestas->getPara() == para) return *curArestas;
		}
	}
	TipoDeAresta& getAresta(int de, int para) {
		for (ListaDeArestas::const_iterator curAresta = arestas[de].begin();
			curArestas != arestas[de].end();
			++curArestas)
		{
			if (curArestas->getPara() == para) return *curArestas;
		}
	}

	int getIndiceProximoNodoLivre()const {
		return proximoIndice;
	}

	int addNodo(TipoDeNodo n) {
		if (n.getIndice() < (int)nodos.size()){
			nodos[n.getIndice()] = n;
			return proximoIndice;
		}
		else{
			nodos.push_back(n);
			arestas.push_back(ListaDeArestas());
			return proximoIndice++;
		}
	}
	void removerNodo(int n) {
		nodos[n].setIndice(-1);

		//if the graph is not directed remove all edges leading to this node and then
		//clear the edges leading from the node
		if (!dirigido)
		{
			//visit each neighbour and erase any edges leading to this node
			for (ListaDeArestas::iterator curAresta = arestas[n].begin();
				curArestas != arestas[n].end();
				++Arestas)
			{
				for (ListaDeArestas::iterator curA = arestas[curAresta->getPara()].begin();
					curA != arestas[curAresta->getPara()].end();
					++curA)
				{
					if (curA->getPara() == n)
					{
						curA = arestas[curAresta->getPara()].erase(curA);
						break;
					}
				}
			}
			arestas[n].clear();
		}
		else
		{
			CullInvalidEdges();
		}
	}

	void removerAresta(int de, int para){
	
		ListaDeArestas::iterator curAresta;

		if (!dirigido)
		{
			for (curAresta = arestas[de].begin();
				curAresta != arestas[de].end();
				++curAresta)
			{
				if (curAresta->getPara() == de) { curAresta = arestas[de].erase(curAresta); break; }
			}
		}

		for (curAresta = arestas[de].begin();
			curAresta != arestas[de].end();
			++curAresta)
		{
			if (curAresta->getPara() == para) { curAresta = arestas[de].erase(curAresta); break; }
		}
	}

	void addAresta(TipoDeAresta a);
	

	int getNumNodos() const;
	int getNumNodosAtivos const;
	int getNumArestas() const; 

	bool isDirigido();
	bool isVazio();
	bool isAtual(int i) const;

	void limpar();

	class ArestaConstIterator;
	class ArestaIterator;
	class NodoIterator;
	class NodoConstIterator;
};