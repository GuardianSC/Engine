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

	float magnitude() const { return sqrtf(x*x + y*y + z*z); }

	float lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }

};

#pragma region "Operators"
Vector3 operator+(const Vector3  &lhs, const Vector3 &rhs);

Vector3 operator-(const Vector3  &lhs, const Vector3 &rhs);

Vector3 operator*(const Vector3 &lhs, float rhs);

Vector3 operator*(const Vector3 &lhs, Vector3 &rhs);

Vector3 operator/(const Vector3 &lhs, float rhs);

Vector3& operator+=(const Vector3 &lhs, const Vector3 &rhs);

Vector3& operator-=(const Vector3 &lhs, const Vector3 &rhs);

Vector3& operator*=(const Vector3 &lhs, const Vector3 &rhs);

Vector3& operator/=(const Vector3 &lhs, const Vector3 &rhs);

bool operator <(const Vector3 &lhs, const Vector3 &rhs);

bool operator >(const Vector3 &lhs, const Vector3 &rhs);

bool operator <=(const Vector3 &lhs, const Vector3 &rhs);

bool operator >=(const Vector3 &lhs, const Vector3 &rhs);

bool operator--(const Vector3 &a); // unary negation(?)

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
inline bool operator==(const Vector3 &lhs, const Vector3 &rhs);
#pragma endregion

#pragma region "Miscellaneous"

double dot(const Vector3 &v);
double dot(const Vector3 &a, const Vector3 &b);

//assert(magnitude() != 0 && "Divide by Zero");
Vector3 normal(const Vector3 &a, float magnitude);

Vector3 cross(const Vector3 &a, const Vector3 &b);

Vector3 scalar(const Vector3 &a, float s);

Vector3 direction(Vector3 &a, Vector3 &b);

double distance(Vector3 &a, Vector3 &b);

double length(Vector3 &a);

Vector3 reflection(const Vector3 a, const Vector3 r);

#pragma endregion