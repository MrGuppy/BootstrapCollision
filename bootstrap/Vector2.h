#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator+(const Vector2& rhs);
	Vector2 operator*(const float rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator/(const Vector2& rhs);
	Vector2 operator+=(const Vector2& rhs);

	float dot(const Vector2& rhs);
	float normalise();
	float magnitude();

	operator float*();

	float x;
	float y;
};

Vector2 operator*(const float lhs, const Vector2& rhs);
Vector2 operator/(const float lhs, const Vector2& rhs);