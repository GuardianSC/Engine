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
Vector4 operator+(const Vector4  &lhs, const Vector4 &rhs) { return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }

Vector4 operator-(const Vector4  &lhs, const Vector4 &rhs) { return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }

Vector4 operator*(const Vector4 &lhs, float rhs) { return Vector4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }

Vector4 operator*(const Vector4 &lhs, Vector4 &rhs) { return Vector4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }

Vector4 operator/(const Vector4 &lhs, float rhs) { return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs); }

Vector4& operator+=(const Vector4 &lhs, const Vector4 &rhs) { return Vector4(lhs += rhs); }

Vector4& operator-=(const Vector4 &lhs, const Vector4 &rhs) { return Vector4(lhs -= rhs); }

Vector4& operator*=(const Vector4 &lhs, const Vector4 &rhs) { return Vector4(lhs *= rhs); }

Vector4& operator/=(const Vector4 &lhs, const Vector4 &rhs) { return Vector4(lhs /= rhs); }

bool operator <(const Vector4 &lhs, const Vector4 &rhs) { return lhs.x < rhs.x, lhs.y < rhs.y, lhs.z < rhs.z, lhs.w < rhs.w; }

bool operator >(const Vector4 &lhs, const Vector4 &rhs) { return lhs.x > rhs.x, lhs.y > rhs.y, lhs.z > rhs.z, lhs.w > rhs.w; }

bool operator <=(const Vector4 &lhs, const Vector4 &rhs) { return lhs <= rhs; }

bool operator >=(const Vector4 &lhs, const Vector4 &rhs) { return lhs >= rhs; }

bool operator--(const Vector4 &a) { return --a; } // unary negation(?)

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
inline bool operator==(const Vector4 &lhs, const Vector4 &rhs) { return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON && rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON; }
#pragma endregion

#pragma region "Miscellaneous"
float dot(const Vector4 &lhs, const Vector4 &rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector4 normal(const Vector4 &a) { return a / a.magnitude(); }

Vector4 scalar(const Vector4 &a, float s) { return Vector4(a.x * s, a.y * s, a.z * s, a.w * s); }

Vector4 direction(Vector4 &a, Vector4 &b) { return normal(a) - normal(b); }

double distance(Vector4 &a, Vector4 &b) { return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z) + (b.w - a.w) * (b.w - a.w)); }

double length(Vector4 &a) { return sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)); }

#pragma endregion

Vector4 reflection(Vector4 a, Vector4 r)
{
	r = ((a - r) * normal(a) * (dot(normal(a), a)));
	return r;
}