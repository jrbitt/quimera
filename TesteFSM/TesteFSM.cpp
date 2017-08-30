#include "../Quimera/Quimera.h"

#include <iostream>
#include "AgenteFSM.h"
#include "stdafx.h"
#include <time.h>
#include <Windows.h>

int main() {
	srand(time(NULL));

	AgenteFSM agente;
	agente.inicializar();
	
	gAmbiente["ver_pacman"] = false;
	gAmbiente["comer_pilula"] = false;
	gAmbiente["perde_pacman"] = false;
	gAmbiente["termina_pilula"] = false;
	gAmbiente["foi_comido"] = false;
	gAmbiente["chegou_base"] = false;

	for (;;) {
		list<Acao*>* acoes = agente.agir(&gAmbiente);
		list<Acao*>::iterator it;
		for (it = acoes->begin(); it != acoes->end(); it++) {
			(*it)->fazer();
		}

		gAmbiente["ver_pacman"] = rand()%2;
		gAmbiente["comer_pilula"] = rand() % 2;
		gAmbiente["perde_pacman"] = rand() % 2;
		gAmbiente["termina_pilula"] = rand() % 2;
		gAmbiente["foi_comido"] = rand() % 2;
		gAmbiente["chegou_base"] = rand() % 2;
		Sleep(500);
	}
	return 0;
}