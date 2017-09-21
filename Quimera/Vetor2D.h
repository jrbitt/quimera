#pragma once
class Vetor2D
{
protected:
	double x, y;

public:
	Vetor2D();
	Vetor2D(double a, double b);
	~Vetor2D();

	double getX() const;
	double getY() const;
	void setX(double a);
	void setY(double b);

	inline void setZero();
	inline bool isZero() const;
	inline double tamanho() const;

	inline double tamanhoQuadrado()const;
	inline void normalizar();

	inline double produto(const Vetor2D& v2)const;
	inline double angulo(const Vetor2D& v2)const;
	inline int sinal(const Vetor2D& v2)const;
	inline Vetor2D perpendicular()const;
	inline void truncar(double max);
	inline double distancia(const Vetor2D &v2)const;
	inline double distanceQuadrada(const Vetor2D &v2)const;
	inline Vetor2D inverso()const;
	inline void refletir(const Vetor2D& norm);

	const Vetor2D& operator+=(const Vetor2D &rhs);
	const Vetor2D& operator-=(const Vetor2D &rhs);
	const Vetor2D& operator*=(const double& rhs);
	const Vetor2D& operator/=(const double& rhs);
	bool operator==(const Vetor2D& rhs)const;
	bool operator!=(const Vetor2D& rhs)const;

	inline Vetor2D operator*(double rhs);
	inline Vetor2D operator-(const Vetor2D &rhs);
	inline Vetor2D operator+(const Vetor2D &rhs);
	inline Vetor2D operator/(double val);
};

