#pragma once
#include "Vetor2D.h"
#include <vector>
using namespace std;

class Matriz3x3
{
protected:
	double _11, _12, _13;
	double _21, _22, _23;
	double _31, _32, _33;

public:
	Matriz3x3();
	~Matriz3x3();

	inline void  multiplicar(Matriz3x3 &m);
	inline void identidade();
	inline void transladar(double x, double y);
	inline void escalar(double xs, double ys);
	inline void rotacionar(double r);
	inline void  rotacionar(const Vetor2D &frente, const Vetor2D &lado);

	inline void transformarVetor2Ds(vector<Vetor2D> &pontos);
	inline void transformarVetor2Ds(Vetor2D &ponto);

	void set_11(double val) { _11 = val; }
	void set_12(double val) { _12 = val; }
	void set_13(double val) { _13 = val; }

	void set_21(double val) { _21 = val; }
	void set_22(double val) { _22 = val; }
	void set_23(double val) { _23 = val; }

	void set_31(double val) { _31 = val; }
	void set_32(double val) { _32 = val; }
	void set_33(double val) { _33 = val; }
};

