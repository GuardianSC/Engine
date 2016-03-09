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

	Rectangle operator= (const Rectangle r)
	{
		Rectangle a;

		a.pos = r.pos;

		a.left = r.left;
		a.right = r.right;
		a.top = r.top;
		a.bottom = r.bottom;

		a.width = r.width;
		a.height = r.height;

		a.min = r.min;
		a.max = r.max;

		return a;
	}

	Rectangle operator== (const Rectangle &r)
	{
		return (this->left == r.left && this->right == r.right && this->top == r.top && this->bottom == r.bottom);
	}

	bool IsEqual(Rectangle& r)
	{
		return (this->left == r.left && this->right == r.right && this->top == r.top && this->bottom == r.bottom);
	}
	double top;
	double left;
	double bottom;
	double right;

	double width;
	double height;

	Vector2 pos;
	Vector2 min;
	Vector2 max;

	static const Rectangle empty;
};