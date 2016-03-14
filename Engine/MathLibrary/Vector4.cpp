#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector4.h"

#pragma region "Operators"
Vector4 Vector4::operator+(const Vector4 &rhs) { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }

Vector4 Vector4::operator-(const Vector4 &rhs) { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }

Vector4 Vector4::operator*(float rhs) { return Vector4(x * rhs, y * rhs, z * rhs, w * rhs); }

Vector4 Vector4::operator*(Vector4 &rhs) { return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w); }

Vector4 Vector4::operator/(float rhs) { return Vector4(x / rhs, y / rhs, z / rhs, w / rhs); }

Vector4& Vector4::operator+=(const Vector4 &rhs) { return Vector4(x += rhs.x, y += rhs.y, z += rhs.z, w += rhs.w); }

Vector4& Vector4::operator-=(const Vector4 &rhs) { return Vector4(x -= rhs.x, y -= rhs.y, z -= rhs.z, w -= rhs.w); }

Vector4& Vector4::operator*=(const Vector4 &rhs) { return Vector4(x *= rhs.x, y *= rhs.y, z *= rhs.z, w *= rhs.w); }

Vector4& Vector4::operator/=(const Vector4 &rhs) { return Vector4(x /= rhs.x, y /= rhs.y, z /= rhs.z, w /= rhs.w); }

bool Vector4::operator<(const Vector4 &rhs) { return x < rhs.x, y < rhs.y, z < rhs.z, w < rhs.w; }

bool Vector4::operator>(const Vector4 &rhs) { return x > rhs.x, y > rhs.y, z > rhs.z, w > rhs.w; }

bool Vector4::operator<=(const Vector4 &rhs) {return (x <= rhs.x, y <= rhs.y, z <= rhs.z, w <= rhs.w); }

bool Vector4::operator>=(const Vector4 &rhs) { return (x >= rhs.x, y >= rhs.y, z >= rhs.z, w >= rhs.w); }

bool Vector4::operator-() { return (-x, -y, -z, -w); } // unary negation

												  //#define EPSILON 0.0001f
												  // return lhs.x == rhs.x && lhs.y == rhs.y;
												  //return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
inline bool operator==(const Vector4 &lhs, const Vector4 &rhs) { return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON && rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON; }
#pragma endregion

#pragma region "Miscellaneous"
float Vector4::magnitude() const{ return sqrtf(x*x + y*y + z*z + w*w); }

float Vector4::lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }

float Vector4::dot(const Vector4 &rhs) { return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector4 Vector4::normal(float magnitude)
{
	Vector4 n;
	magnitude = (x * x + y * y + z * z);
	n.x = (x / magnitude);
	n.y = (y / magnitude);
	n.z = (z / magnitude);
	n.w = (w / magnitude);
	return n;
}

Vector4 Vector4::scalar(float s) { return Vector4(x * s, y * s, z * s, w * s); }

Vector4 Vector4::direction(Vector4 &b) { return normal(x - b.x, y - b.y, z - b.z, w - b.w); }

double Vector4::distance(Vector4 &b) { return sqrtf((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y) + (b.z - z) * (b.z - z) + (b.w - w) * (b.w - w)); }

double Vector4::length() { return sqrtf((x * x) + (y * y) + (z * z) + (w * w)); }

Vector4 Vector4::reflection(Vector4 &a, Vector4 &b)
{
	Vector4 r = ((a - r) * normal(a) * (dot(normal(a), a)));
	return r;
}

Vector4 Vector4::min(const Vector4 &a, const Vector4 &b)
{
	{ return (a.x < b.x && a.y < b.y && a.z < b.z && a.w < b.w) ? a : b; }
}
Vector4 Vector4::max(const Vector4 &a, const Vector4 &b)
{
	{ return (a.x < b.x && a.y < b.y && a.z < b.z && a.w < b.w) ? b : a; }
}
Vector4 Vector4::clamp(const Vector4 &a, const Vector4 &a_min, const Vector4 &a_max)
{
	{ return min(max(a, a_min), a_max); }
}

#pragma endregion