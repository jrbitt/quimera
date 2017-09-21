#include "Vetor2D.h"
#include <math.h>
#include <limits>

using namespace std;

Vetor2D::Vetor2D()
{
	x = 0.0;
	y = 0.0;
}

Vetor2D::Vetor2D(double a, double b)
{
	x = a;
	y = b;
}


Vetor2D::~Vetor2D()
{
}

double Vetor2D::getX() const
{
	return x;
}

double Vetor2D::getY() const
{
	return y;
}

void Vetor2D::setX(double a)
{
	x = a;
}

void Vetor2D::setY(double b)
{
	y = b;
}

inline void Vetor2D::setZero()
{
	x = y = 0.0;
}

inline bool Vetor2D::isZero() const
{
	return (x*x + y*y) < (numeric_limits<double>::min)();
}

inline double Vetor2D::tamanho() const
{
	return sqrt(pow(x,2) + pow(y,2));
}

inline double Vetor2D::tamanhoQuadrado() const
{
	return (pow(x, 2) + pow(y, 2));
}

inline void Vetor2D::normalizar()
{
	double q = tamanho();
	if (q > numeric_limits<double>::epsilon()) {
		x = x / q;
		y = y / q;
	}
}

inline double Vetor2D::produto(const Vetor2D & v2) const
{
	return (x*v2.x) + (y*v2.y);
}

inline double Vetor2D::angulo(const Vetor2D & v2) const
{
	return this->produto(v2) / (this->tamanhoQuadrado()*v2.tamanhoQuadrado());
}

inline int Vetor2D::sinal(const Vetor2D & v2) const
{
	if (y*v2.x > x*v2.y)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

inline Vetor2D Vetor2D::perpendicular() const
{
	return Vetor2D(-y, x);
}

inline void Vetor2D::truncar(double max)
{
	if (this->tamanho() > max)
	{
		this->normalizar();
		*this *= max;
	}
}

inline double Vetor2D::distancia(const Vetor2D & v2) const
{
	double ys = v2.y - y;
	double xs = v2.x - x;

	return sqrt(ys*ys + xs*xs);
}

inline double Vetor2D::distanceQuadrada(const Vetor2D & v2) const
{
	double ys = v2.y - y;
	double xs = v2.x - x;

	return (ys*ys + xs*xs);
}

inline Vetor2D Vetor2D::inverso() const
{
	return Vetor2D(-this->x, -this->y);
}

inline void Vetor2D::refletir(const Vetor2D & norm)
{
	*this += norm.inverso() * this->produto(norm) * 2.0;
}

const Vetor2D & Vetor2D::operator+=(const Vetor2D & v)
{
	x += v.x;
	y += v.y;

	return *this;
}

const Vetor2D & Vetor2D::operator-=(const Vetor2D & v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

const Vetor2D & Vetor2D::operator*=(const double & v)
{
	x *= v;
	y *= v;

	return *this;
}

const Vetor2D & Vetor2D::operator/=(const double & v)
{
	x /= v;
	y /= v;

	return *this;
}

bool Vetor2D::operator==(const Vetor2D & v) const
{
	bool a = false, b = false;
	if (fabs(x - v.x) < 1E-12)
	{
		a =true;
	}
	if (fabs(y - v.y) < 1E-12)
	{
		b = true;
	}
	return a&&b;
}

bool Vetor2D::operator!=(const Vetor2D & v) const
{
	return (x != v.x) || (y != v.y);
}

inline Vetor2D Vetor2D::operator*(double rhs)
{
	Vetor2D r(*this);
	r *= rhs;
	return r;
}

//overload the - operator
inline Vetor2D Vetor2D::operator-(const Vetor2D &rhs)
{
	Vetor2D r(*this);
	r.x -= rhs.x;
	r.y -= rhs.y;

	return r;
}

//overload the + operator
inline Vetor2D Vetor2D::operator+(const Vetor2D &rhs)
{
	Vetor2D r(*this);
	r.x += rhs.x;
	r.y += rhs.y;

	return r;
}

//overload the / operator
inline Vetor2D Vetor2D::operator/(double val)
{
	Vetor2D r(*this);
	r.x /= val;
	r.y /= val;

	return r;
}