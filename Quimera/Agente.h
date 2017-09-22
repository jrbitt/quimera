#pragma once
#include "Acao.h"
#include "Ambiente.h"
#include "Controle.h"
#include "Vetor2D.h"

#include <list>
using namespace std;

class Agente
{
private:
	int id;
	static int proximoId;

	void setId(int i);

protected:
	Controle* controle;
	Vetor2D posicao;
	Vetor2D escala;
	double raio;

public:
	Agente(int i);
	~Agente();

	void setControle(Controle *c);
	list<Acao*>* agir(Ambiente *a);

	virtual void inicializar(Ambiente *a=NULL) = 0;
	virtual void atualizar(double te) = 0;

	int getId() const;

	Vetor2D getPosicao()const;
	void setPosicao(Vetor2D np);
	double getRaio()const;
	void setRaio(double r);
	Vetor2D getEscala()const;
	void setEscala(Vetor2D val);
	void setEscala(double val);


};

