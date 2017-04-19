#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::~Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	return result;
}

Vector3 Vector3::operator+=(const Vector3& rhs)
{
	Vector3 result;
	result.x += rhs.x;
	result.y += rhs.y;
	result.z += rhs.z;
	return result;
}

Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	return result;
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	return result;
}

Vector3 operator/(const float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	return result;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	return result;
}

Vector3 Vector3::operator/(const Vector3& rhs)
{
	Vector3 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;
	result.z = z / rhs.z;
	return result;
}

float Vector3::magnitude()
{
	float result;
	result = sqrtf((x * x) + (y * y) + (z * z));
	return result;
}

Vector3::operator float*()
{
	return &x;
}

float Vector3::dot(const Vector3 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

float Vector3::normalise()
{
	float mag = magnitude();
	x = x / mag;
	y = y / mag;
	z = z / mag;
	return mag;
}

Vector3 Vector3::cross(const Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	return result;
}

Vector3 operator/(const float & lhs, const Vector3 rhs)
{
	Vector3 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	return result;
}
