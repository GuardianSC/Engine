#pragma once
#include "Vector2.h"

struct Ray
{
public:
	Vector2 position;
	Vector2 direction;
	float length;
	static const Ray empty;

	Ray() : position(0, 0), direction(0, 0), length(0) {}
	Ray(const Ray &r) : position(r.position), direction(r.direction), length(r.length) {}
	Ray(Vector2 &_position, Vector2 &_direction, float l) : position(_position), direction(_direction), length(l) {}
	Ray(float x, float y, Vector2 &_direction, float l) : position(x, y), direction(_direction), length(l) { }
	Ray(Vector2 &_position, float dX, float dY, float l) : position(_position), direction(dX, dY), length(l) { }
	Ray(float x, float y, float dX, float dY, float l) : position(x, y), direction(dX, dY), length(l) { }
	~Ray() {}
	
	Ray operator=(const Ray& R)
	{
		Ray r;

		r.position = R.position;
		r.direction = R.direction;
		r.length = R.length;

		return r;
	}
	bool operator==(const Ray& R)
	{
		if (this->position == R.position && this->direction == R.direction && this->length == R.length) 
			return true;

		return false;
	}

	bool IsEqual(const Ray &R) { return (this->position == R.position && this->direction == R.direction && this->length == R.length); }
};

inline bool operator== (const Ray r1, const Ray &r2)
{
	return (r1.position == r2.position && r1.direction == r2.direction && r1.length == r2.length);
}
inline bool operator!= (const Ray r1, const Ray &r2)
{
	return !(r1 == r2);
}