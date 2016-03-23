#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vector2
{
	float x, y;

	Vector2() {}
	Vector2(double a_x, double a_y) : x(a_x), y(a_y) {}

#pragma region "Operators"
	Vector2 operator+(const Vector2 &rhs) const;

	Vector2 operator-(const Vector2 &rhs) const;

	Vector2 operator*(float f) const;

	Vector2 operator*(const Vector2 &rhs) const;

	Vector2 operator/(float rhs) const;

	Vector2& operator+=(const Vector2 &rhs);

	Vector2& operator-=(const Vector2 &rhs);

	Vector2& operator*=(const Vector2 &rhs);

	Vector2& operator/=(const Vector2 &rhs);

	bool operator<(const Vector2 &rhs) const;

	bool operator>(const Vector2 &rhs) const;

	bool operator<=(const Vector2 &rhs) const;

	bool operator>=(const Vector2 &rhs) const;

	bool operator-() const; // unary negation


//#define EPSILON 0.0001f
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
// return lhs.x == rhs.x && lhs.y == rhs.y;

	bool operator==(const Vector2 &rhs) const;

	bool operator!=(const Vector2 &rhs) const;
#pragma endregion

#pragma region "Miscellaneous"
	// Dot production tells us how much one vector extends in the direction of another vector

	float magnitude();

	static float lerp(float alpha, float start, float end);

	static Vector2 fromAngle(float a);

	static float dot(const Vector2 &lhs, const Vector2 &rhs);

	//assert(magnitude() != 0 && "Divide by Zero");
	static Vector2 normal(Vector2 &b);

	Vector2 scalar(const Vector2 &a, float s);

	double distance(Vector2 &a, Vector2 &b);

	double length(Vector2 &a);

	float angle();

	static Vector2 perp(const Vector2 &a);

	Vector2 project(const Vector2 &a, const Vector2 &b, float magnitude);

	Vector2 reflection(Vector2 &b);

	Vector2 min(const Vector2 &a, const Vector2 &b);

	Vector2 max(const Vector2 &a, const Vector2 &b);

	static Vector2 clamp(const Vector2 &a, const Vector2 &a_min, const Vector2 &a_max);

	static Vector2 snap(const Vector2 &val, const Vector2 &lower, const Vector2 &upper);

#pragma endregion

};

