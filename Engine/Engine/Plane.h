#pragma once

#include "Vector2.h"

struct Plane
{
public:
	Vector2 position;
	Vector2 normal;
	static const Plane empty;
	Plane() : position(0, 0), normal(0, 0)  {}
	Plane(const Plane &p) : position(p.position), normal(p.normal) {}
	Plane(Vector2 &_position, Vector2 &_normal) : position(_position), normal(_normal) {}
	Plane(float x, float y, Vector2 &_normal) : position(x, y), normal(_normal) {}
	Plane(Vector2 _position, float nX, float nY) : position(_position), normal(nX, nY) {}
	Plane(float x, float y, float nX, float nY) : position(x, y), normal(nX, nY) { }
	~Plane() {}

	Plane operator=(const Plane &P)
	{
		Plane p;

		p.position = P.position;
		p.normal = P.normal;

		return p;
	}
	bool operator==(const Plane &P)
	{
		if (this->position == P.position && this->normal == P.normal)
			return true;

		return false;
	}

	bool IsEqual(const Plane &P) { return (this->position == P.position && this->normal == P.normal); }
};

inline bool operator== (const Plane p1, const Plane &p2)
{
	return (p1.position == p2.position && p1.normal == p2.normal);
}
inline bool operator!= (const Plane p1, const Plane &p2)
{
	return !(p1 == p2);
}