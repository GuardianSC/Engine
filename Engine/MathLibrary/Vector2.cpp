#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector2.h"

#pragma region "Operators"
Vector2 Vector2::operator+(const Vector2 &rhs) const { return Vector2(x + rhs.x, y + rhs.y); }

Vector2 Vector2::operator-(const Vector2 &rhs) const { return Vector2(x - rhs.x, y - rhs.y); }

Vector2 Vector2::operator/(float rhs) const { return Vector2(x / rhs, y / rhs); }

Vector2 Vector2::operator*(float f) const { return Vector2(x * f, y * f); }

Vector2 Vector2::operator*(const Vector2 &rhs) const { return Vector2(x * rhs.x, y * rhs.y); }

Vector2& Vector2::operator+=(const Vector2 &rhs) { return Vector2(x += rhs.x, y += rhs.y); }

Vector2& Vector2::operator-=(const Vector2 &rhs) { return Vector2(x -= rhs.x, y -= rhs.y); }

Vector2& Vector2::operator*=(const Vector2 &rhs) { return Vector2(x *= rhs.x, y *= rhs.y); }

Vector2& Vector2::operator/=(const Vector2 &rhs) { return Vector2(x /= rhs.x, y /= rhs.y); }

bool Vector2::operator<(const Vector2 &rhs) const { return x < rhs.x, y < rhs.y; }

bool Vector2::operator>(const Vector2 &rhs) const { return x > rhs.x, y > rhs.y; }

bool Vector2::operator<=(const Vector2 &rhs) const { return x <= rhs.x, y <= rhs.y; }

bool Vector2::operator>=(const Vector2 &rhs) const { return x >= rhs.x, y >= rhs.y; } 

bool Vector2::operator-() const { return (-x, -y); } // unary negation


//#define EPSILON 0.0001f
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
// return lhs.x == rhs.x && lhs.y == rhs.y;

bool Vector2::operator==(const Vector2 &rhs) const { return rhs.x - FLT_EPSILON < x && x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < y && y < rhs.y + FLT_EPSILON; }

bool Vector2::operator!=(const Vector2 &rhs) const { return x != rhs.x && y != rhs.y; }
#pragma endregion

#pragma region "Miscellaneous"
// Dot production tells us how much one vector extends
// in the direction of another vector
float Vector2::magnitude()
{
	return sqrtf(x * x + y * y);
}

float Vector2::lerp(float alpha, float start, float end) { return (1 - alpha)*start + (alpha)*end; }

Vector2 Vector2::fromAngle(float a) { return{ cosf(a), sinf(a) }; }

float Vector2::dot(const Vector2 &lhs, const Vector2 &rhs) { return (lhs.x * rhs.x) + (rhs.y * lhs.y); }

//assert(magnitude() != 0 && "Divide by Zero");
 Vector2 Vector2::normal(Vector2 &b) 
{ 
	float m = (b.x * b.x + b.y * b.y);
	return b / m; 
}

Vector2 Vector2::scalar(const Vector2 &a, float s) { return Vector2(a.x * s, a.y * s); }

double Vector2::distance(Vector2 &a, Vector2 &b) { return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)); }

double Vector2::length(Vector2 &a) { return sqrtf((a.x * a.x) + (a.y * a.y)); }

float angle(Vector2 &a) { return atan2(a.x, a.y); }

Vector2 Vector2::perp(const Vector2 &a) { return Vector2(-a.y, a.x); }

Vector2 Vector2::project(const Vector2 &a, const Vector2 &b, float magnitude)
{
	float pX = (((a.x * b.x) + (a.y * b.y)) * b.x / magnitude);
	float py = (((a.x * b.x) + (a.y * b.y)) * b.y / magnitude);;
	return a, b;
}

Vector2 Vector2::reflection(Vector2 &b)
{
	Vector2 r = (b - r * normal(b) * (dot(normal(b), b)));
	return r;
}
Vector2 Vector2::min(const Vector2 &a, const Vector2 &b)
{
	{ return (a.x < b.x && a.y < b.y) ? a : b; }
}
Vector2 Vector2::max(const Vector2 &a, const Vector2 &b)
{
	{ return (a.x < b.x && a.y < b.y) ? b : a; }
}
Vector2 Vector2::clamp(const Vector2 &a, const Vector2 &a_min, const Vector2 &a_max)
{
	{ return min(max(a, a_min), a_max); }
}

Vector2 Vector2::snap(const Vector2 &val, const Vector2 &lower, const Vector2 &upper)
{
	return{ val.x - lower.x < upper.x - val.x ? lower.x : upper.x, val.y - lower.y < upper.y - val.y ? lower.y : upper.y };
}

#pragma endregion