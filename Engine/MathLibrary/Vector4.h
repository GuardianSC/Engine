#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vector4
{
	float x, y, z, w;

	Vector4() {}
	Vector4(float a_x, float a_y, float a_z, float a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}



#pragma region "Operators"
	Vector4 operator+(const Vector4 &rhs) const;

	Vector4 operator-(const Vector4 &rhs) const;

	Vector4 operator*(float rhs) const;

	Vector4 operator*(Vector4 &rhs) const;

	Vector4 operator/(float rhs) const;

	Vector4& operator+=(const Vector4 &rhs);

	Vector4& operator-=(const Vector4 &rhs);

	Vector4& operator*=(const Vector4 &rhs);

	Vector4& operator/=(const Vector4 &rhs);

	bool operator<(const Vector4 &rhs) const;

	bool operator>(const Vector4 &rhs) const;

	bool operator<=(const Vector4 &rhs) const;

	bool operator>=(const Vector4 &rhs) const;

	bool operator-() const; // unary negation

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
	bool operator==(const Vector4 &rhs);
#pragma endregion

#pragma region "Miscellaneous"
	float magnitude() const;

	float lerp(float alpha, float start, float end);

	float dot(const Vector4 &rhs);

	//assert(magnitude() != 0 && "Divide by Zero");
	Vector4 normal(const Vector4 &b);

	Vector4 scalar(float s);

	double distance(Vector4 &b);

	double length();

	Vector4 reflection(Vector4 &b);
		
	Vector4 min(const Vector4 &a, const Vector4 &b);

	Vector4 max(const Vector4 &a, const Vector4 &b);

	Vector4 clamp(const Vector4 &a, const Vector4 &a_min, const Vector4 &a_max);

#pragma endregion



};

