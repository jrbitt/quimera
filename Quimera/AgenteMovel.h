#pragma once
#include "Agente.h"
#include "GerenteDeSteering.h"
class GerenteDeSteering;

class AgenteMovel :
	public Agente
{
protected:
	Vetor2D velocidade;
	Vetor2D direcao;
	Vetor2D lado;
	double massa;

	double velMax;
	double forcaMax;
	double rotacaoMax; //radianos/segundos

	GerenteDeSteering* gSteering;

public:
	AgenteMovel(Vetor2D posicao,
		double    raio,
		Vetor2D velocidade,
		double    velMaxima,
		Vetor2D direcao,
		double    massa,
		Vetor2D escala,
		double    rotacao,
		double    forcaMaxima);
	~AgenteMovel();

	void atualizar(double te);

	Vetor2D getVelocidade()const;
	void setVelocidade(const Vetor2D& v);
	double getMassa()const;
	Vetor2D getLado()const;
	double getVelocidadeMax()const;
	void setVelocidadeMax(double n);
	double getForcaMax()const;
	void setForcaMax(double mf);

	bool isVelocidadeAcimaMaximo() const;
	double getRapidez() const;
	double getRapidezQuadrado() const;

	Vetor2D getDirecao()const;
	void setDirecao(Vetor2D d);
	bool rotacionarEmDirecaoPosicao(Vetor2D alvo);
	double getRotacaoMaxima()const;
	void setRotacacoMaxima(double val);

	void setGerenteDeSteering(GerenteDeSteering *s);
	GerenteDeSteering* getGerenteDeSteering() const;
};

