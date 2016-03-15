#pragma once
#include "Vector2.h"

struct Circle
{
public:
	Vector2 position;
	double radius;
	static const Circle empty;

	Circle() : position(0, 0), radius(0.0) {}
	Circle(const Circle &c) : position(c.position), radius(c.radius){}
	Circle(Vector2 &_position, double _radius) : position(_position), radius(_radius) {}
	Circle(float x, float y, double _radius) : position(x, y), radius(_radius) {}
	Circle(Vector2 _position, double r) : position(_position), radius(r) {}
	//Circle(float x, float y, double r) : position(x, y), radius(r) {}
	~Circle() {}

	Circle operator=(const Circle &C)
	{
		Circle c;

		c.position = C.position;
		c.radius = C.radius;

		return c;
	}
	bool operator==(const Circle &C)
	{
		if (this->position == C.position && this->radius == C.radius)
			return true;

		return false;
	}

	bool IsEqual(const Circle &C) { return (this->position == C.position && this->radius == C.radius); }
};

inline bool operator== (const Circle c1, const Circle &c2)
{
	return (c1.position == c2.position && c1.radius == c2.radius);
}
inline bool operator!= (const Circle r1, const Circle &r2)
{
	return !(r1 == r2);
}