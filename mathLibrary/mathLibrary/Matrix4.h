#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

struct Matrix4
{
	Matrix4() {}
	union
	{
		float   v[16];
		float   m[4][4];
		Vector3 c[3];
	};

	Matrix4 transpose() const
	{
		Matrix4 r;
		r.c[0] = Vector4(m[0][0], m[1][0], m[2][0], m[3][0]);
		r.c[1] = Vector3(m[0][1], m[1][1], m[2][1]);
		r.c[2] = Vector3(m[0][2], m[1][2], m[2][2]);
		r.c[3] = Vector3(m[0][3], m[1][3], m[2][3]);
		return r;
	}

	static Matrix4 identity()
	{
		Matrix4 r;
		r.c[0] = Vector3(1, 0, 0);
		r.c[1] = Vector3(0, 1, 0);
		r.c[2] = Vector3(0, 0, 1);
		return r;
	}

	// angle, in degrees
	static Matrix4 rotate(float angle)
	{
		Matrix4 r = identity();
		r.c[0] = Vector3(cosf(angle), sinf(angle), 0);
		r.c[1] = Vector3(-sinf(angle), cosf(angle), 0);
		return r;
	}

	static Matrix4 scale(const Vector2 &xy)
	{
		Matrix4 r = identity();
		r.m[0][0] = xy.x;
		r.m[1][1] = xy.y;
		return r;
	}

	static Matrix4 translate(const Vector2 &xy)
	{
		Matrix4 r = identity();
		r.m[2][0] = xy.x;
		r.m[2][1] = xy.y;
		return r;
	}
};



Vector3 operator*(const Matrix4 &_A, const Vector3 &b);
Matrix4 operator*(const Matrix4 &_A, const Matrix4 &B);