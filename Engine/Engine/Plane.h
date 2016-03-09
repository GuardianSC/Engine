#pragma once

#include "Vector2.h"

struct Plane
{
public:
	
	Plane() : pos(0, 0), normal(0, 0)  {}

	~Plane() {}

	Vector2 pos;
	Vector2 normal;


};