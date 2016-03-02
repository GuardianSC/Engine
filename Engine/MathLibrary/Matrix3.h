#pragma once
#include "Vector2.h"
#include "Vector3.h"

struct Matrix3
{
	union
	{
		float   v[9];
		float   m[3][3];
		Vector3 c[3];
	};

	Matrix3() {}

	Matrix3 transpose() const
	{
		Matrix3 r;
		r.c[0] = Vector3(m[0][0], m[1][0], m[2][0]);
		r.c[1] = Vector3(m[0][1], m[1][1], m[2][1]);
		r.c[2] = Vector3(m[0][2], m[1][2], m[2][2]);
		return r;
	}

	static Matrix3 identity()
	{
		Matrix3 r;	
		r.c[0] = Vector3(1, 0, 0);
		r.c[1] = Vector3(0, 1, 0);
		r.c[2] = Vector3(0, 0, 1);
		return r;
	}

	static Matrix3 inverse() // Help from http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
	{
		Matrix3 r, iR, m;
		float d = ((r.v[0] * r.v[4] * r.v[8]) + (r.v[3] * r.v[7] * r.v[2]) + (r.v[6] * r.v[1] * r.v[5]) - (r.v[0] * r.v[7] * r.v[5]) - (r.v[6] * r.v[4] * r.v[2]) - (r.v[3] * r.v[1] * r.v[8])); // Determinant

		bool dPass = false;
		if (d != 0) { dPass = true; } // If determinant does not equal zero, there is a matrix
		if (dPass = true)
		{
			iR.c[0] = Vector3((r.v[4] * r.v[8]) - (r.v[5] * r.v[7]), (r.v[2] * r.v[7]) - (r.v[1] * r.v[8]), (r.v[1] * r.v[5]) - (r.v[2] * r.v[4]));
			iR.c[1] = Vector3((r.v[5] * r.v[6]) - (r.v[3] * r.v[8]), (r.v[0] * r.v[8]) - (r.v[2] * r.v[6]), (r.v[2] * r.v[3]) - (r.v[0] * r.v[5]));
			iR.c[2] = Vector3((r.v[3] * r.v[7]) - (r.v[4] * r.v[6]), (r.v[1] * r.v[6]) - (r.v[0] * r.v[7]), (r.v[0] * r.v[4]) - (r.v[1] * r.v[3]));

			r * iR = m;

			return m;
		}
	}

	// angle, in degrees
	static Matrix3 rotate(float angle)
	{
		Matrix3 r = identity();
		r.c[0] = Vector3(cosf(angle), sinf(angle), 0);
		r.c[1] = Vector3(-sinf(angle), cosf(angle), 0);
		return r;
	}

	static Matrix3 scale(const Vector2 &xy)
	{
		Matrix3 r = identity();
		r.m[0][0] = xy.x;
		r.m[1][1] = xy.y;
		return r;
	}

	static Matrix3 translate(const Vector2 &xy)
	{
		Matrix3 r = identity();
		r.m[2][0] = xy.x;
		r.m[2][1] = xy.y;
		return r;
	}
};

#pragma region "Operators"
Matrix3 operator+(const Matrix3 &_A, const Matrix3 &b) 
{ 
	// create a temporary matrix to hold the result
	Matrix3 temp;

	// do a member-wise addition
	for (int i = 0; i < 9; ++i)
	{
		temp.v[i] = _A.v[i] + b.v[i];
	}

	return temp;
}

Matrix3 operator+=(const Matrix3 &_A, const Matrix3 &b) 
{ 
	Matrix3 temp;

	for (int i = 0; i < 9; ++i)
	{
		//temp.v[i] = _A.v[i] += b.v[i];
	}

	return temp;
	}

Matrix3 operator-(const Matrix3 &_A, const Matrix3 &b)
{
	Matrix3 temp;

	for (int i = 0; i < 9; ++i)
	{
		temp.v[i] = _A.v[i] - b.v[i];
	}

	return temp;
}

Matrix3 operator-=(const Matrix3 &_A, const Matrix3 &b)
{
	Matrix3 temp;

	for (int i = 0; i < 9; ++i)
	{
		//temp.v[i] = _A.v[i] -= b.v[i];
	}

	return temp;
}

// Matrix Matrix Multiplication
Matrix3 operator*(const Matrix3 &_A, const Matrix3 &b)
{
	{
		Matrix3 r;
		Matrix3 A = _A.transpose(); //A can now access rows as vector3

		/*for (size_t i = 0; i < 3; ++i)
		   r.c[i] = Vector3(dot(A.c[0], B.c[i]), dot(A.c[1], B.c[i]), dot(A.c[2], B.c[i]));*/
		r.c[0] = Vector3(dot(A.c[0], b.c[0]), dot(A.c[1], b.c[0]), dot(A.c[2], b.c[0]));
		r.c[1] = Vector3(dot(A.c[0], b.c[1]), dot(A.c[1], b.c[1]), dot(A.c[2], b.c[1]));
		r.c[2] = Vector3(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]));

		return r;
	}
}

//Matrix3 operator*=(const Matrix3 &_A, const Matrix3 &b)
//{
//	{
//		//A can now access rows as vector3
//		Matrix3 r, A = _A.transpose();
//
//		/*for (size_t i = 0; i < 3; ++i)
//		r.c[i] = Vector3(dot(A.c[0], B.c[i]), dot(A.c[1], B.c[i]), dot(A.c[2], B.c[i]));*/
//		r.c[0] = Vector3(dot(A.c[0], b.c[0]), dot(A.c[1], b.c[0]), dot(A.c[2], b.c[0]));
//		r.c[1] = Vector3(dot(A.c[0], b.c[1]), dot(A.c[1], b.c[1]), dot(A.c[2], b.c[1]));
//		r.c[2] = Vector3(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]));
//
//		return r;
//	}
//}

//Matrix Vector Multiplication
Vector3 operator*(const Matrix3 &_A, const Vector3 &b)
{
	Matrix3 A = _A.transpose();
	Vector3 r;

	r.x = dot(A.c[0], b);
	r.y = dot(A.c[1], b);
	r.z = dot(A.c[2], b);

	return r;
}

#pragma endregion