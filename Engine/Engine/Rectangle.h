#pragma once
#include "Vector2.h"

struct Rectangle
{
public:

	Rectangle() : left(0), top(0), right(0), bottom(0) 
	{
		width = right - left;
		height = bottom - top;
		//min = { top, left };
		//max = { bottom, right };
	}

	Rectangle(const Rectangle &r) : left(r.left), top(r.top), right(r.right), bottom(r.bottom)
	{
		width = r.width;
		height = r.height;
		pos = { top + (width / 2), right + (height / 2) };
		//min = { top, left };
		//max = { bottom, right };
	}


	Rectangle(double l, double t, double r, double b) : left(l), top(t), right(r), bottom(b)
	{
		width = right - left;
		height = bottom - top;
		pos = { top + (width / 2), right + (height / 2) };
		min = { top, left };
		max = { bottom, right };
	}

	Rectangle(const Vector2& v1, const Vector2& v2)	: top(v1.y), left(v1.x), bottom(v2.y), right(v2.x)
	{
		width = right - left;
		height = bottom - top;
		pos = { top + (width / 2), left + (height / 2) };
		min = { top, left };
		max = { bottom, right };
	}

	~Rectangle() {}

	double top;
	double left;
	double bottom;
	double right;

	double width;
	double height;

	Vector2 pos;
	Vector2 min;
	Vector2 max;
};