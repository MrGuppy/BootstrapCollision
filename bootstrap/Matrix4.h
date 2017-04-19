#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4(float a, float b, float c, float d, 
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float f_m, float n, float o, float p);
	Matrix4();
	~Matrix4();

	Matrix4 operator*(const Matrix4& rhs);
	Vector4 operator*(const Vector4& rhs);

	Vector4& operator[](const int rhs);

	void setRotateX(const float a);
	void setRotateY(const float a);
	void setRotateZ(const float a);
	void setRotateW();

	operator float*();

	//float fp v cast operator
	//float fp m cast operator

	float m[16];
};