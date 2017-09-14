#pragma once
class Aresta
{
protected:
	int origem;
	int destino;
	float custo;

public:
	Aresta(int de, int para, float c=1.0f);
	Aresta(int de, int para);
	Aresta();
	~Aresta();

	void setOrigem(int de);
	void setDestino(int para);
	void setCusto(float c);

	int getOrigem();
	int getDestino();
	float getCusto();
};

