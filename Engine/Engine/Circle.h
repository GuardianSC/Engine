#pragma once
#include "Vector2.h"

struct Circle
{
public:
	Circle() : pos(0, 0), radius(0.0) {}

	~Circle() {}

	Vector2 pos;
	double radius;

};