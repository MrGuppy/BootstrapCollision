#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2(float a, float b, float c, float d);
	Matrix2();
	~Matrix2();

	Matrix2 operator*(const Matrix2& rhs); //M * M
	Vector2 operator*(const Vector2& rhs); //V * M

	Vector2& operator[](const int rhs); // subscript operator returning with reference

	void setRotate(const float a); // set rotate

	operator float*();


	float m[4];
};
