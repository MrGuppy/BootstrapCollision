#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = d;
	m[4] = e;
	m[5] = f;
	m[6] = g;
	m[7] = h;
	m[8] = i;
}

Matrix3::Matrix3()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;

	m[3] = 0;
	m[4] = 1;
	m[5] = 0;

	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

Matrix3::~Matrix3()
{
}

void Matrix3::setRotateX(const float a)
{

	m[0] = 1;
	m[1] = 0;
	m[2] = 0;

	m[3] = 0;
	m[4] = cosf(a);
	m[5] = sinf(a);

	m[6] = 0;
	m[7] = -sinf(a);
	m[8] = cosf(a);
}

void Matrix3::setRotateY(const float a)
{
	m[0] = cosf(a);
	m[1] = 0;
	m[2] = -sinf(a);

	m[3] = 0;
	m[4] = 1;
	m[5] = 0;

	m[6] = sinf(a);
	m[7] = 0;
	m[8] = cosf(a);
}

void Matrix3::setRotateZ(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = 0;

	m[3] = -sinf(a);
	m[4] = cosf(a);
	m[5] = 0;

	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

Matrix3::operator float*()
{
	return &m[0];
}

Matrix3 Matrix3::operator*(const Matrix3 & rhs)
{
	Matrix3 result;
	result.m[0] = m[0] * rhs.m[0] + m[3] * rhs.m[1] + m[6] * rhs.m[2];
	result.m[1] = m[1] * rhs.m[0] + m[4] * rhs.m[1] + m[7] * rhs.m[2];
	result.m[2] = m[2] * rhs.m[0] + m[5] * rhs.m[1] + m[8] * rhs.m[2];

	result.m[3] = m[0] * rhs.m[3] + m[3] * rhs.m[4] + m[6] * rhs.m[5];
	result.m[4] = m[1] * rhs.m[3] + m[4] * rhs.m[4] + m[7] * rhs.m[5];
	result.m[5] = m[2] * rhs.m[3] + m[5] * rhs.m[4] + m[8] * rhs.m[5];

	result.m[6] = m[0] * rhs.m[6] + m[3] * rhs.m[7] + m[6] * rhs.m[8];
	result.m[7] = m[1] * rhs.m[6] + m[4] * rhs.m[7] + m[7] * rhs.m[8];
	result.m[8] = m[2] * rhs.m[6] + m[5] * rhs.m[7] + m[8] * rhs.m[8];

	return result;
}

Vector3 Matrix3::operator*(const Vector3 & rhs)
{
	Vector3 result;
	result.x = m[0] * rhs.x + m[3] * rhs.y + m[6] * rhs.z;
	result.y = m[1] * rhs.x + m[4] * rhs.y + m[7] * rhs.z;
	result.z = m[2] * rhs.x + m[5] * rhs.y + m[8] * rhs.z;
	return result;
}

Vector3& Matrix3::operator[](const int rhs)
{
	return *(Vector3*)(m + 3 * rhs);
}
