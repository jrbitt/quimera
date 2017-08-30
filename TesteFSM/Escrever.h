#pragma once
#include "../Quimera/Quimera.h"

class Escrever: public Acao
{
private:
	string msg;

public:
	Escrever(string m);
	~Escrever();

	void fazer();
};

