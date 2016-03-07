#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>

struct Vector2
{
	float x, y;

	Vector2() {}
	Vector2(float a_x, float a_y) : x(a_x), y(a_y) {}

	float magnitude(const Vector2 &a)  
	{
		float m;
		return sqrtf(a.x * a.x + a.y * a.y); 
		return m;
	}

	



	float lerp(float alpha, float start, float end) { (1 - alpha)*start + (alpha)*end; }

	static Vector2 fromAngle(float a) { return{ cosf(a), sinf(a) }; }
};

#pragma region "Operators"
Vector2 operator+(const Vector2  &lhs, const Vector2 &rhs);

Vector2 operator-(const Vector2  &lhs, const Vector2 &rhs);

Vector2 operator/(const Vector2 &lhs, float rhs);

Vector2 operator*(const Vector2 &lhs, float rhs);

Vector2 operator*(const Vector2 &lhs, Vector2 &rhs);

Vector2& operator+=(const Vector2 &lhs, const Vector2 &rhs);

Vector2& operator-=(const Vector2 &lhs, const Vector2 &rhs);

Vector2& operator*=(const Vector2 &lhs, const Vector2 &rhs);

Vector2& operator/=(const Vector2 &lhs, const Vector2 &rhs);

bool operator <(const Vector2 &lhs, const Vector2 &rhs);

bool operator >(const Vector2 &lhs, const Vector2 &rhs);

bool operator <=(const Vector2 &lhs, const Vector2 &rhs);

bool operator >=(const Vector2 &lhs, const Vector2 &rhs);

bool operator--(const Vector2 &a); // unary negation(?)


//#define EPSILON 0.0001f
//return fabsf(rhs.x - lhs.x) < FLT_EPSILON && fabsf(rhs.y - lhs.y) < FLT_EPSILON;
// return lhs.x == rhs.x && lhs.y == rhs.y;

bool operator==(const Vector2 &lhs, const Vector2 &rhs);

bool operator!=(const Vector2 &lhs, const Vector2 &rhs);
#pragma endregion

#pragma region "Miscellaneous"
// Dot production tells us how much one vector extends
// in the direction of another vector
float dot(const Vector2 &lhs, const Vector2 &rhs);

//assert(magnitude() != 0 && "Divide by Zero");
Vector2 normal(Vector2 &a);

Vector2 perpX(const Vector2 &a);

Vector2 perpY(const Vector2 &a);

Vector2 scalar(const Vector2 &a, float s);

Vector2 direction(Vector2 &a, Vector2 &b);

double distance(Vector2 &a, Vector2 &b);

double length(Vector2 &a);
//Vector2 angle() {}

Vector2 perp(const Vector2 &a, const Vector2 &b);

float dot(const Vector2 &a, const Vector2 &b);

Vector2 project(const Vector2 &a, const Vector2 &b, float magnitude);

#pragma endregion

#pragma region "Reflection"
//Vector2 reflectionX(const Vector2 &a) { return(Vector2(-a.x, a.y)); }
//
//Vector2 reflectionY(const Vector2 &a) { return (Vector2(a.x, -a.y)); }
//
//Vector2 reflection(const Vector2 &a) { return (Vector2(-a.x, -a.y)); }

Vector2 reflection(Vector2 a, Vector2 r);

#pragma endregion