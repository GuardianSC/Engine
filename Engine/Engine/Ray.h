#pragma once
#include "Vector2.h"

struct Ray
{
public:
	
	Ray() : pos(0, 0), direction(0, 0) {}

	~Ray() {}
	
	Vector2 pos;
	Vector2 direction;
};