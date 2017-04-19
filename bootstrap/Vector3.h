#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	float x;
	float y;
	float z;

	Vector3 operator+(const Vector3& rhs);
	Vector3 operator*(const float rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator/(const Vector3& rhs);
	Vector3 operator+=(const Vector3& rhs);
	Vector3 cross(const Vector3& rhs);
	float dot(const Vector3 rhs);
	float normalise();
	float magnitude();

	operator float*();


};

Vector3 operator*(const float lhs, const Vector3& rhs);
Vector3 operator/(const float lhs, const Vector3& rhs);