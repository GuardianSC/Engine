#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector2.h"

#pragma region "Operators"
Vector2 Vector2::operator+(const Vector2 &rhs) { return Vector2(x + rhs.x, y + rhs.y); }

Vector2 Vector2::operator-(const Vector2 &rhs) { return Vector2(x - rhs.x, y - rhs.y); }

Vector2 Vector2::operator/(float rhs) { return Vector2(x / rhs, y / rhs); }

Vector2 Vector2::operator*(float rhs) { return Vector2(x * rhs, y * rhs); }

Vector2 Vector2::operator*(Vector2 &rhs) { return Vector2(x * rhs.x, y * rhs.y); }

Vector2& Vector2::operator+=(const Vector2 &rhs) { return Vector2(x += rhs.x, y += rhs.y); }

Vector2& Vector2::operator-=(const Vector2 &rhs) { return Vector2(x -= rhs.x, y -= rhs.y); }

Vector2& Vector2::operator*=(const Vector2 &rhs) { return Vector2(x *= rhs.x, y *= rhs.y); }

Vector2& Vector2::operator/=(const Vector2 &rhs) { return Vector2(x /= rhs.x, y /= rhs.y); }

bool Vector2::operator<(const Vector2 &rhs) { return x < rhs.x, y < rhs.y; }

bool Vector2::operator>(const Vector2 &rhs) { return x > rhs.x, y > rhs.y; }

bool Vector2::operator<=(const Vector2 &rhs) { return x <= rhs.x, y <= rhs.y; }

bool Vector2::operator>=(const Vector2 &rhs) { return x >= rhs.x, y >= rhs.y; }

bool Vector2::operator-() { return (-x, -y); } // unary negation


//#define EPSILON 0.0001f
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
// return lhs.x == rhs.x && lhs.y == rhs.y;

bool Vector2::operator==(const Vector2 &rhs) { return rhs.x - FLT_EPSILON < x && x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < y && y < rhs.y + FLT_EPSILON; }

bool Vector2::operator!=(const Vector2 &rhs) { return x != rhs.x && y != rhs.y; }
#pragma endregion

#pragma region "Miscellaneous"
// Dot production tells us how much one vector extends
// in the direction of another vector
float Vector2::magnitude()
{
	float m;
	return sqrtf(x * x + y * y);
	return m;
}

float Vector2::lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }

Vector2 Vector2::fromAngle(float a) { return{ cosf(a), sinf(a) }; }

float Vector2::dot(const Vector2 &lhs, const Vector2 &rhs) { return (lhs.x * rhs.x) + (rhs.y * lhs.y); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector2 Vector2::normal(Vector2 &a)
{ 
	float m = (a.x * a.x + a.y * a.y);
	return a / m; 
}

//Vector2 perpX(const Vector2 &a) { return Vector2(-a.y, a.x); }

//Vector2 perpY(const Vector2 &a) { return Vector2(a.y, -a.x); }

Vector2 Vector2::scalar(const Vector2 &a, float s) { return Vector2(a.x * s, a.y * s); }

Vector2 Vector2::direction(Vector2 &a, Vector2 &b) { return normal(a - b); }

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

Vector2 Vector2::reflection(Vector2 &a, Vector2 &b)
{
	Vector2 r = (a - b * normal(a) * (dot(normal(a), a)));
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

#pragma endregion