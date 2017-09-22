#include "AgenteMovel.h"
#include "Matriz3x3.h"


AgenteMovel::AgenteMovel(Vetor2D posicao,
	double    raio,
	Vetor2D velocidade,
	double    velMaxima,
	Vetor2D direcao,
	double    massa,
	Vetor2D escala,
	double    rotacao,
	double    forcaMaxima): Agente(0)
{
	this->direcao = direcao;
	this->velocidade = velocidade;
	this->massa = massa;
	this->lado = direcao.perpendicular();
	this->velMax = velMaxima;
	this->rotacaoMax = rotacao;
	this->forcaMax = forcaMaxima;
	this->escala = escala;
}

AgenteMovel::~AgenteMovel()
{
}

void AgenteMovel::atualizar(double te)
{
	Vetor2D sForca = gSteering->calcular();
	Vetor2D aceleracao = sForca / massa;

	velocidade += aceleracao*te;
	velocidade.truncar(velMax);

	posicao += velocidade*te;
	if (velocidade.tamanhoQuadrado() > 0.000000001) {
		Vetor2D v(velocidade);
		v.normalizar();
		direcao = v;
		lado = direcao.perpendicular();
	}
}

Vetor2D AgenteMovel::getVelocidade() const
{
	return velocidade;
}

void AgenteMovel::setVelocidade(const Vetor2D & v)
{
	velocidade = v;
}

double AgenteMovel::getMassa() const
{
	return massa;
}

Vetor2D AgenteMovel::getLado() const
{
	return lado;
}

double AgenteMovel::getVelocidadeMax() const
{
	return velMax;
}

void AgenteMovel::setVelocidadeMax(double vm)
{
	velMax = vm;
}

double AgenteMovel::getForcaMax() const
{
	return forcaMax;
}

void AgenteMovel::setForcaMax(double mf)
{
	forcaMax = mf;
}

bool AgenteMovel::isVelocidadeAcimaMaximo() const
{
	return velMax*velMax >= velocidade.tamanhoQuadrado();
}

double AgenteMovel::getRapidez() const
{
	return velocidade.tamanho();
}

double AgenteMovel::getRapidezQuadrado() const
{
	return velocidade.tamanhoQuadrado();
}

Vetor2D AgenteMovel::getDirecao() const
{
	return direcao;
}

void AgenteMovel::setDirecao(Vetor2D d)
{
	direcao = d;
}

bool AgenteMovel::rotacionarEmDirecaoPosicao(Vetor2D alvo)
{
	Vetor2D paraAlvo = alvo - posicao;
	paraAlvo.normalizar();

	double angulo = acos(direcao.produto(paraAlvo));
	if (angulo < 0.00001) return true;

	if (angulo > rotacaoMax) angulo = rotacaoMax;

	Matriz3x3 matRotacao;

	matRotacao.rotacionar(angulo * direcao.sinal(paraAlvo));
	matRotacao.transformarVetor2Ds(direcao);
	matRotacao.transformarVetor2Ds(velocidade);

	lado = direcao.perpendicular();
}

double AgenteMovel::getRotacaoMaxima() const
{
	return rotacaoMax;
}

void AgenteMovel::setRotacacoMaxima(double val)
{
	rotacaoMax = val;
}

void AgenteMovel::setGerenteDeSteering(GerenteDeSteering * s)
{
	gSteering = s;
}

GerenteDeSteering * AgenteMovel::getGerenteDeSteering() const
{
	return gSteering;
}
