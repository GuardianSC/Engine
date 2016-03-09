#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector3.h"

#pragma region "Operators"
Vector3 operator+(const Vector3  &lhs, const Vector3 &rhs) { return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

Vector3 operator-(const Vector3  &lhs, const Vector3 &rhs) { return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

Vector3 operator*(const Vector3 &lhs, float rhs) { return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }

Vector3 operator*(const Vector3 &lhs, Vector3 &rhs) { return Vector3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z); }

Vector3 operator/(const Vector3 &lhs, float rhs) { return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs); }

Vector3& operator+=(const Vector3 &lhs, const Vector3 &rhs) { return Vector3(lhs += rhs); }

Vector3& operator-=(const Vector3 &lhs, const Vector3 &rhs) { return Vector3(lhs -= rhs); }

Vector3& operator*=(const Vector3 &lhs, const Vector3 &rhs) { return Vector3(lhs *= rhs); }

Vector3& operator/=(const Vector3 &lhs, const Vector3 &rhs) { return Vector3(lhs /= rhs); }

bool operator <(const Vector3 &lhs, const Vector3 &rhs) { return lhs.x < rhs.x, lhs.y < rhs.y, lhs.z < rhs.z; }

bool operator >(const Vector3 &lhs, const Vector3 &rhs) { return lhs.x > rhs.x, lhs.y > rhs.y, lhs.z > rhs.z; }

bool operator <=(const Vector3 &lhs, const Vector3 &rhs) { return lhs <= rhs; }

bool operator >=(const Vector3 &lhs, const Vector3 &rhs) { return lhs >= rhs; }

bool operator-(const Vector3 &a) { return -a; } // unary negation

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
bool operator==(const Vector3 &lhs, const Vector3 &rhs) { return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON && rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON; }
#pragma endregion

#pragma region "Miscellaneous"

//double dot(const Vector3 &v) 
//{
//	float x, y, z;
//	return ((v.x * x) + (v.y * y) + (v.z * z)); 
//}
double dot(const Vector3 &a, const Vector3 &b) { return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z)); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector3 normal(const Vector3 &a)
{
	Vector3 n;
	float m = (a.x * a.x + a.y * a.y + a.z * a.z);
	n.x = (a.x / m);
	n.y = (a.y / m);
	n.z = (a.z / m);
	return n;
}

Vector3 cross(const Vector3 &a, const Vector3 &b) { return Vector3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x)); }

Vector3 scalar(const Vector3 &a, float s) { return Vector3(a.x * s, a.y * s, a.z * s); }

Vector3 direction(Vector3 &a, Vector3 &b) { return normal(a - b); }

double distance(Vector3 &a, Vector3 &b) { return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z)); }

double length(Vector3 &a) { return sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z)); }

Vector3 reflection(const Vector3 a, const Vector3 r)
{
	Vector3 n = normal(a);
	
	//r = ((a - r) * normal(a) * (dot(normal(a), a)));
	return r;
}

#pragma endregion