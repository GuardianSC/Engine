#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vector4
{
	float x, y, z, w;

	Vector4() {}
	Vector4(float a_x, float a_y, float a_z, float a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}

	float magnitude() const { return sqrtf(x*x + y*y + z*z + w*w); }

	float lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }

};

#pragma region "Operators"
Vector4 operator+(const Vector4  &lhs, const Vector4 &rhs);

Vector4 operator-(const Vector4  &lhs, const Vector4 &rhs);

Vector4 operator*(const Vector4 &lhs, float rhs);

Vector4 operator*(const Vector4 &lhs, Vector4 &rhs);

Vector4 operator/(const Vector4 &lhs, float rhs);

Vector4& operator+=(const Vector4 &lhs, const Vector4 &rhs);

Vector4& operator-=(const Vector4 &lhs, const Vector4 &rhs);

Vector4& operator*=(const Vector4 &lhs, const Vector4 &rhs);

Vector4& operator/=(const Vector4 &lhs, const Vector4 &rhs);

bool operator <(const Vector4 &lhs, const Vector4 &rhs);

bool operator >(const Vector4 &lhs, const Vector4 &rhs);

bool operator <=(const Vector4 &lhs, const Vector4 &rhs);

bool operator >=(const Vector4 &lhs, const Vector4 &rhs);

bool operator--(const Vector4 &a); // unary negation(?)

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
inline bool operator==(const Vector4 &lhs, const Vector4 &rhs);
#pragma endregion

#pragma region "Miscellaneous"
float dot(const Vector4 &lhs, const Vector4 &rhs);

//assert(magnitude() != 0 && "Divide by Zero");
Vector4 normal(const Vector4 &a);

Vector4 scalar(const Vector4 &a, float s);

Vector4 direction(Vector4 &a, Vector4 &b);

double distance(Vector4 &a, Vector4 &b);

double length(Vector4 &a);

Vector4 reflection(Vector4 a, Vector4 r);

#pragma endregion


