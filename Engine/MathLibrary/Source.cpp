#include "mat4.h"
#include "tmat.h"
#include "tvec.h"
#include "Shapes.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include <cassert>

#pragma region Vector2

float magnitude(const vec2 &a) // mag = sqrt(x^2 + y^2)
{
	float m;
	m = sqrt((a.x * a.x) + (a.y * a.y));
	return m;
}


vec2 normal(const vec2 &a, float magnitude)
{
	vec2 n;
	float m = magnitude;
	n.x = (a.x / magnitude);
	n.y = (a.y / magnitude);
	return n;
}

vec2 perp(const vec2 &a)
{
	/*vec2 pX;
	vec2 Py;
	pX = a.y;
	pY = -a.x;*/
}

float dot(const vec2 &a, const vec2 &b)
{
	float d = ((a.x * b.x) + (a.y * b.y));
	return d;
}

// dot(a,b) * normal(b)
vec2 project(const vec2 &a, const vec2 &b, float magnitude) 
{
	float pX = (((a.x * b.x) + (a.y * b.y)) * b.x / magnitude);
	float py = (((a.x * b.x) + (a.y * b.y)) * b.y / magnitude);;
	return a, b;
}

#pragma endregion

#pragma region Vector3

float magnitude(const vec3 &a)
{
	float m;
	m = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return m;
}

vec3 normal(const vec3 &a, float magnitude)
{
	vec3 n;
	float m = magnitude;
	n.x = (a.x / magnitude);
	n.y = (a.y / magnitude);
	n.z = (a.z / magnitude);
	return n;
}

float dot(const vec3 &a, const vec3 &b)
{
	float d = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
	return d;
}

#pragma endregion

int main()
{

	system("pause");
	return 0;
}