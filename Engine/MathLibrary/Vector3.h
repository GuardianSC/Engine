#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vector3
{
public:
	float x, y, z;
	Vector3() {}
	Vector3(float a_x, float a_y, float a_z): x(a_x), y(a_y), z(a_z) {}

#pragma region "Operators"
	Vector3 operator+(const Vector3 &rhs) const;

	Vector3 operator- (const Vector3 &rhs) const;

	Vector3 operator*(float rhs) const;

	Vector3 operator*(Vector3 &rhs) const;

	Vector3 operator/(float rhs) const;

	Vector3& operator+=(const Vector3 &rhs);

	Vector3& operator-=(const Vector3 &rhs);

	Vector3& operator*=(const Vector3 &rhs);

	Vector3& operator/=(const Vector3 &rhs);

	bool operator<(const Vector3 &rhs) const;

	bool operator>(const Vector3 &rhs) const;

	bool operator<=(const Vector3 &rhs);

	bool operator>=(const Vector3 &rhs);

	bool operator-() const; // unary negation

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
	bool operator==(const Vector3 &rhs) const;
#pragma endregion

#pragma region "Miscellaneous"

	float magnitude() const;

	float lerp(float alpha, float start, float end);

	double dot(const Vector3 &v);

	double dot(const Vector3 &a, const Vector3 &b);

	//assert(magnitude() != 0 && "Divide by Zero");
	Vector3 normal(const Vector3 &b);

	Vector3 cross(const Vector3 &b);

	Vector3 scalar(float s);

	double distance(Vector3 &b);

	double length();

	Vector3 reflection(const Vector3 &b);

	Vector3 min(const Vector3 &a, const Vector3 &b);

	Vector3 max(const Vector3 &a, const Vector3 &b);

	Vector3 clamp(const Vector3 &a, const Vector3 &a_min, const Vector3 &a_max);
#pragma endregion
};