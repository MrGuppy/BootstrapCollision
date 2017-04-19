#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	float x;
	float y;
	float z;
	float w;

	Vector4 operator+(const Vector4& rhs);
	Vector4 operator*(const float rhs);
	Vector4 operator-(const Vector4& rhs);
	Vector4 operator/(const Vector4& rhs);
	Vector4 operator+=(const Vector4& rhs);
	Vector4 Vector4::cross(const Vector4& rhs);

	float dot(const Vector4 rhs);
	float normalise();
	float magnitude();

	operator float*();


};

Vector4 operator*(const float lhs, const Vector4& rhs);
Vector4 operator/(const float lhs, const Vector4& rhs);