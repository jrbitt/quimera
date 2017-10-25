#pragma once
class ProblemaAprReforco
{

public:
	class ParProblema {
	public:
		float recompensa;
		int novoEstado;
	};

	ProblemaAprReforco();
	~ProblemaAprReforco();

	virtual int getEstadoRandomico() = 0;
	virtual int* getAcoes(int estado) = 0;
	virtual ParProblema tomarAcao(int estado, int acao) = 0;

	virtual int getNumEstados() = 0;
	virtual int getNumMaxAcoes() = 0;

	virtual bool acabou() = 0;
};

