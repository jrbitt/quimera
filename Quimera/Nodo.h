#pragma once
class Nodo
{
protected:
	int indice;

public:
	Nodo();
	Nodo(int i);
	~Nodo();

	int getIndice();
	void setIndice(int i);
};

