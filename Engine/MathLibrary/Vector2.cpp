#include <cmath>
#include <cassert>
#include <cfloat>
#include "Vector2.h"

//struct Vector2
//{
//	float x, y;
//
//	Vector2() {}
//	Vector2(float a_x, float a_y) : x(a_x), y(a_y) {}
//
//	float magnitude() const { return sqrtf(x*x + y*y); }
//
//	float lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }
//
//	static Vector2 fromAngle(float a) { return{ cosf(a), sinf(a) }; }
//};

#pragma region "Operators"
Vector2 operator+(const Vector2  &lhs, const Vector2 &rhs) { return Vector2(lhs.x + rhs.x, lhs.y + rhs.y); }

Vector2 operator-(const Vector2  &lhs, const Vector2 &rhs) { return Vector2(lhs.x - rhs.x, lhs.y - rhs.y); }

Vector2 operator/(const Vector2 &lhs, float rhs) { return Vector2(lhs.x / rhs, lhs.y / rhs); }

Vector2 operator*(const Vector2 &lhs, float rhs) { return Vector2(lhs.x * rhs, lhs.y * rhs); }

Vector2 operator*(const Vector2 &lhs, Vector2 &rhs) { return Vector2(lhs.x * rhs.x, lhs.y * rhs.y); }

Vector2& operator+=(const Vector2 &lhs, const Vector2 &rhs) { return Vector2(lhs += rhs); }

Vector2& operator-=(const Vector2 &lhs, const Vector2 &rhs) { return Vector2(lhs -= rhs); }

Vector2& operator*=(const Vector2 &lhs, const Vector2 &rhs) { return Vector2(lhs *= rhs); }

Vector2& operator/=(const Vector2 &lhs, const Vector2 &rhs) { return Vector2(lhs /= rhs); }

bool operator <(const Vector2 &lhs, const Vector2 &rhs) { return lhs.x < rhs.x, lhs.y < rhs.y; }

bool operator >(const Vector2 &lhs, const Vector2 &rhs) { return lhs.x > rhs.x, lhs.y > rhs.y; }

bool operator <=(const Vector2 &lhs, const Vector2 &rhs) { return lhs <= rhs; }

bool operator >=(const Vector2 &lhs, const Vector2 &rhs) { return lhs >= rhs; }

bool operator--(const Vector2 &a) { return --a; } // unary negation(?)


												  //#define EPSILON 0.0001f
												  //return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
												  // return lhs.x == rhs.x && lhs.y == rhs.y;

bool operator==(const Vector2 &lhs, const Vector2 &rhs) { return rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON && rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON; }

bool operator!=(const Vector2 &lhs, const Vector2 &rhs) { return lhs.x != rhs.x && lhs.y != rhs.y; }
#pragma endregion

#pragma region "Miscellaneous"
// Dot production tells us how much one vector extends
// in the direction of another vector
float dot(const Vector2 &lhs, const Vector2 &rhs) { return (lhs.x * rhs.x) + (rhs.y * lhs.y); }

//assert(magnitude() != 0 && "Divide by Zero");
Vector2 normal(Vector2 &a) { return a / a.magnitude; }

Vector2 perpX(const Vector2 &a) { return Vector2(-a.y, a.x); }

Vector2 perpY(const Vector2 &a) { return Vector2(a.y, -a.x); }

Vector2 scalar(const Vector2 &a, float s) { return Vector2(a.x * s, a.y * s); }

Vector2 direction(Vector2 &a, Vector2 &b) { return normal(a - b); }

double distance(Vector2 &a, Vector2 &b) { return sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)); }

double length(Vector2 &a) { return sqrtf((a.x * a.x) + (a.y * a.y)); }

//Vector2 angle(Vector2 &a, Vector2 &b) 
//{
//
//}

Vector2 perp(const Vector2 &a, const Vector2 &b)
{
    b = (a.y, -a.x);
	return b;
}

float dot(const Vector2 &a, const Vector2 &b)
{
	float d = ((a.x * b.x) + (a.y * b.y));
	return d;
}

Vector2 project(const Vector2 &a, const Vector2 &b, float magnitude)
{
	float pX = (((a.x * b.x) + (a.y * b.y)) * b.x / magnitude);
	float py = (((a.x * b.x) + (a.y * b.y)) * b.y / magnitude);;
	return a, b;
}

#pragma endregion

#pragma region "Reflection"

Vector2 reflection(Vector2 &a, Vector2 &b)
{
	Vector2 r;
	r = (a - b * normal(a) * (dot(normal(a), a)));
	return r;
}

#pragma endregion