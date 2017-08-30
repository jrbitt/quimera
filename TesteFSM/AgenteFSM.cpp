#include "stdafx.h"
#include "AgenteFSM.h"
#include "../Quimera/Quimera.h"

#include <iostream>
#include "Escrever.h"

AgenteFSM::AgenteFSM()
{
}


AgenteFSM::~AgenteFSM()
{
}

void AgenteFSM::inicializar(Ambiente * a)
{
	//Criar a maquina de estados finitos
	MaquinaDeEstadosFinitos *maquina = new MaquinaDeEstadosFinitos;
	controle = maquina;

	ver_pacman.setCondicao(new CondicaoAmbiente("ver_pacman"));
	comer_pilula.setCondicao(new CondicaoAmbiente("comer_pilula"));
	perde_pacman.setCondicao(new CondicaoAmbiente("perde_pacman"));
	termina_pilula.setCondicao(new CondicaoAmbiente("termina_pilula"));
	foi_comido.setCondicao(new CondicaoAmbiente("foi_comido"));
	chegou_base.setCondicao(new CondicaoAmbiente("chegou_base"));

	//Adicionar os estados-alvo nas transições
	ver_pacman.setEstadoAlvo(&perseguir);
	comer_pilula.setEstadoAlvo(&fugir);
	perde_pacman.setEstadoAlvo(&vaguear);
	termina_pilula.setEstadoAlvo(&vaguear);
	foi_comido.setEstadoAlvo(&retornarBase);
	chegou_base.setEstadoAlvo(&vaguear);

	//Adicionar transições aos estados
	vaguear.addTransicao(&ver_pacman);
	vaguear.addTransicao(&comer_pilula);

	perseguir.addTransicao(&perde_pacman);
	perseguir.addTransicao(&comer_pilula);

	fugir.addTransicao(&foi_comido);
	fugir.addTransicao(&termina_pilula);

	retornarBase.addTransicao(&chegou_base);

	//Adicionar as ações aos estados
	vaguear.addAcao(new Escrever("vagueando..."), AO_EXECUTAR);
	perseguir.addAcao(new Escrever("perseguindo..."), AO_EXECUTAR);
	fugir.addAcao(new Escrever("fugindo..."), AO_EXECUTAR);
	retornarBase.addAcao(new Escrever("retornando..."), AO_EXECUTAR);

	maquina->addEstado(&vaguear);
	maquina->addEstado(&perseguir);
	maquina->addEstado(&fugir);
	maquina->addEstado(&retornarBase);

	maquina->setEstadoInicial(&vaguear);

}
