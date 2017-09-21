#include "Matriz3x3.h"
#include <cmath>


Matriz3x3::Matriz3x3()
{
	_11 = 0.0; _12 = 0.0; _13 = 0.0;
	_21 = 0.0; _22 = 0.0; _23 = 0.0;
	_31 = 0.0; _32 = 0.0; _33 = 0.0;
}


Matriz3x3::~Matriz3x3()
{
}

inline void Matriz3x3::multiplicar(Matriz3x3 & m)
{
	Matriz3x3 mat_temp;

	//primeira linha
	mat_temp._11 = (_11*m._11) + (_12*m._21) + (_13*m._31);
	mat_temp._12 = (_11*m._12) + (_12*m._22) + (_13*m._32);
	mat_temp._13 = (_11*m._13) + (_12*m._23) + (_13*m._33);

	//segunda
	mat_temp._21 = (_21*m._11) + (_22*m._21) + (_23*m._31);
	mat_temp._22 = (_21*m._12) + (_22*m._22) + (_23*m._32);
	mat_temp._23 = (_21*m._13) + (_22*m._23) + (_23*m._33);

	//terceira
	mat_temp._31 = (_31*m._11) + (_32*m._21) + (_33*m._31);
	mat_temp._32 = (_31*m._12) + (_32*m._22) + (_33*m._32);
	mat_temp._33 = (_31*m._13) + (_32*m._23) + (_33*m._33);

	set_11(mat_temp._11);
	set_12(mat_temp._12);
	set_13(mat_temp._13);

	set_21(mat_temp._21);
	set_22(mat_temp._22);
	set_23(mat_temp._23);

	set_31(mat_temp._31);
	set_32(mat_temp._32);
	set_33(mat_temp._33);
}

inline void Matriz3x3::identidade()
{
	_11 = 1; _12 = 0; _13 = 0;
	_21 = 0; _22 = 1; _23 = 0;
	_31 = 0; _32 = 0; _33 = 1;
}

inline void Matriz3x3::transladar(double x, double y)
{
	Matriz3x3 mat;

	mat._11 = 1; mat._12 = 0; mat._13 = 0;

	mat._21 = 0; mat._22 = 1; mat._23 = 0;

	mat._31 = x; mat._32 = y; mat._33 = 1;

	multiplicar(mat);
}

inline void Matriz3x3::escalar(double xs, double ys)
{
	Matriz3x3 mat;

	mat._11 = xs; mat._12 = 0; mat._13 = 0;

	mat._21 = 0; mat._22 = ys; mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	multiplicar(mat);
}

inline void Matriz3x3::rotacionar(double r)
{
	Matriz3x3 mat;

	double s = sin(r);
	double c = cos(r);

	mat._11 = c;  mat._12 = s; mat._13 = 0;

	mat._21 = -s; mat._22 = c; mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	multiplicar(mat);
}

inline void Matriz3x3::rotacionar(const Vetor2D & frente, const Vetor2D & lado)
{
	Matriz3x3 mat;
	mat._11 = frente.getX();  mat._12 = frente.getY(); mat._13 = 0;

	mat._21 = lado.getX(); mat._22 = lado.getY(); mat._23 = 0;

	mat._31 = 0; mat._32 = 0; mat._33 = 1;

	multiplicar(mat);
}

inline void Matriz3x3::transformarVetor2Ds(vector<Vetor2D>& pontos)
{
	for (unsigned int i = 0; i<pontos.size(); ++i)
	{
		double tempX = (_11*pontos[i].getX()) + (_21*pontos[i].getY()) + (_31);

		double tempY = (_12*pontos[i].getX()) + (_22*pontos[i].getY()) + (_32);

		pontos[i].setX(tempX);

		pontos[i].setY(tempY);

	}
}

inline void Matriz3x3::transformarVetor2Ds(Vetor2D & ponto)
{
	double tempX = (_11*ponto.getX()) + (_21*ponto.getY()) + (_31);

	double tempY = (_12*ponto.getX()) + (_22*ponto.getY()) + (_32);

	ponto.setX(tempX);

	ponto.setY(tempY);
}
