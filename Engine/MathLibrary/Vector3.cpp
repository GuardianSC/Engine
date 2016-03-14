#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector3.h"

#pragma region "Operators"
Vector3 Vector3::operator+(const Vector3 &rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }

Vector3 Vector3::operator-(const Vector3 &rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }

Vector3 Vector3::operator*(float rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }

Vector3 Vector3::operator*(Vector3 &rhs) const { return Vector3(x * rhs.x, y * rhs.y, z * rhs.z); }

Vector3 Vector3::operator/(float rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }

Vector3& Vector3::operator+=(const Vector3 &rhs) { return Vector3(x += rhs.x, y += rhs.y, z += rhs.z); }

Vector3&Vector3::operator-=(const Vector3 &rhs) { return Vector3(x -= rhs.x, y -= rhs.y, z -= rhs.z); }

Vector3& Vector3::operator*=(const Vector3 &rhs) { return Vector3(x *= rhs.x, y *= rhs.y, z *= rhs.z); }

Vector3& Vector3::operator/=(const Vector3 &rhs) { return Vector3(x /= rhs.x, y /= rhs.y, z /= rhs.z); }

bool Vector3::operator<(const Vector3 &rhs) const { return x < rhs.x, y < rhs.y, z < rhs.z; }

bool Vector3::operator>(const Vector3 &rhs) const { return x > rhs.x, y > rhs.y, z > rhs.z; }

bool Vector3::operator<=(const Vector3 &rhs) { return x <= rhs.x, y <= rhs.y, z += rhs.z; }

bool Vector3::operator>=(const Vector3 &rhs) { return x >= rhs.x, y <= rhs.y, z >= rhs.z; }

bool Vector3::operator-() const { return (-x, -y, -z); } // unary negation

//#define EPSILON 0.0001f
// return lhs.x == rhs.x && lhs.y == rhs.y;
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
bool Vector3::operator==(const Vector3 &rhs) const { return rhs.x - FLT_EPSILON < x && x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < y && y < rhs.y + FLT_EPSILON && rhs.z - FLT_EPSILON < z && z < rhs.z + FLT_EPSILON; }
#pragma endregion

#pragma region "Miscellaneous"

float Vector3::magnitude() const { return sqrtf(x*x + y*y + z*z); }

float Vector3::lerp(float alpha, float start, float end) { return (1 - alpha)*start + (alpha)*end; }

//double dot(const Vector3 &v) 
//{
//	float x, y, z;
//	return ((v.x * x) + (v.y * y) + (v.z * z)); 
//}
double Vector3::dot(const Vector3 &b) { return ((x * b.x) + (y * b.y) + (z * b.z)); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector3 Vector3::normal(const Vector3 &b)
{
	Vector3 n;
	float m = (x * x + y * y + z * z);
	n.x = (x / m);
	n.y = (y / m);
	n.z = (z / m);
	return n;
}

Vector3 Vector3::cross(const Vector3 &b) { return Vector3((y * b.z) - (z * b.y), (z * b.x) - (x * b.z), (x * b.y) - (y * b.x)); }

Vector3 Vector3::scalar(float s) { return Vector3(x * s, y * s, z * s); }

double Vector3::distance(Vector3 &b) { return sqrtf((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y) + (b.z - z) * (b.z - z)); }

double Vector3::length() { return sqrtf((x * x) + (y * y) + (z * z)); }

Vector3 Vector3::reflection(const Vector3 &b)
{
	Vector3 r = (b - r * normal(b) * (dot(normal(b), b)));
	return r;
}

Vector3 Vector3::min(const Vector3 &a, const Vector3 &b)
{
	{ return (a.x < b.x && a.y < b.y && a.z < b.z) ? a : b; }
}
Vector3 Vector3::max(const Vector3 &a, const Vector3 &b)
{
	{ return (a.x < b.x && a.y < b.y && a.z < b.z) ? b : a; }
}
Vector3 Vector3::clamp(const Vector3 &a, const Vector3 &a_min, const Vector3 &a_max)
{
	{ return min(max(a, a_min), a_max); }
}

#pragma endregion