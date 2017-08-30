#pragma once
#include "Condicao.h"
#include "Ambiente.h"

class CondicaoAmbiente :
	public Condicao
{
private:
	string var;

public:
	CondicaoAmbiente(string v);
	~CondicaoAmbiente();

	bool testar();
};

