#pragma once
#include "e:\Joao\2017_2\IA_SL\Quimera\Quimera\Agente.h"
class AgenteFSM :
	public Agente
{
private:
	//Criar os estados
	Estado vaguear;
	Estado perseguir;
	Estado fugir;
	Estado retornarBase;

	//Criar as transições
	Transicao ver_pacman;
	Transicao comer_pilula;
	Transicao perde_pacman;
	Transicao termina_pilula;
	Transicao foi_comido;
	Transicao chegou_base;

public:
	AgenteFSM();
	~AgenteFSM();

	void inicializar(Ambiente *a = NULL);

};

