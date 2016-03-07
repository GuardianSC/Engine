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
		Vector4 c[4];
	};

	Matrix4 transpose() const
	{
		Matrix4 r;
		r.c[0] = Vector4(m[0][0], m[1][0], m[2][0], m[3][0]);
		r.c[1] = Vector4(m[0][1], m[1][1], m[2][1], m[3][1]);
		r.c[2] = Vector4(m[0][2], m[1][2], m[2][2], m[3][2]);
		r.c[3] = Vector4(m[0][3], m[1][3], m[2][3], m[3][3]);
		return r;
	}

	static Matrix4 identity()
	{
		Matrix4 r;
		r.c[0] = Vector4(1, 0, 0, 0);
		r.c[1] = Vector4(0, 1, 0, 0);
		r.c[2] = Vector4(0, 0, 1, 0);
		r.c[3] = Vector4(0, 0, 0, 1);
		return r;
	}

	static Matrix4 inverse() // Help from http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
	{
		Matrix4 r;
		Matrix4 iR;
		Matrix4 m;

		float d = ((r.v[0] * r.v[5] * r.v[10] * r.v[15]) + (r.v[0] * r.v[6] * r.v[11] * r.v[13]) + (r.v[0] * r.v[7] * r.v[9] * r.v[14]) +
			(r.v[1] * r.v[4] * r.v[11] * r.v[14]) + (r.v[1] * r.v[6] * r.v[8] * r.v[15]) + (r.v[1] * r.v[7] * r.v[10] * r.v[12]) +
			(r.v[2] * r.v[4] * r.v[9] * r.v[15]) + (r.v[2] * r.v[5] * r.v[11] * r.v[12]) + (r.v[2] * r.v[7] * r.v[8] * r.v[13]) +
			(r.v[3] * r.v[4] * r.v[10] * r.v[13]) + (r.v[3] * r.v[5] * r.v[8] * r.v[14]) + (r.v[3] * r.v[6] * r.v[9] * r.v[12]) -
			(r.v[0] * r.v[5] * r.v[11] * r.v[14]) - (r.v[0] * r.v[6] * r.v[9] * r.v[15]) - (r.v[0] * r.v[7] * r.v[10] * r.v[13]) -
			(r.v[1] * r.v[4] * r.v[10] * r.v[15]) - (r.v[1] * r.v[6] * r.v[11] * r.v[12]) - (r.v[1] * r.v[7] * r.v[8] * r.v[14]) -
			(r.v[2] * r.v[4] * r.v[11] * r.v[13]) - (r.v[2] * r.v[5] * r.v[8] * r.v[15]) - (r.v[2] * r.v[7] * r.v[9] * r.v[12]) -
			(r.v[3] * r.v[4] * r.v[9] * r.v[14]) - (r.v[3] * r.v[5] * r.v[10] * r.v[12]) - (r.v[3] * r.v[6] * r.v[8] * r.v[13])); // Determinant

		bool dPass = false;
		if (d != 0) { dPass = true; } // If determinant does not equal zero, there is a matrix
		if (dPass = true)
		{
			iR.c[0] = Vector4((r.v[5] * r.v[10] * r.v[15]) + (r.v[6] * r.v[11] * r.v[13]) + (r.v[7] * r.v[9] * r.v[14]) - (r.v[5] * r.v[11] * r.v[14]) - (r.v[6] * r.v[9] * r.v[15]) - (r.v[7] * r.v[10] * r.v[13]),
				(r.v[1] * r.v[11] * r.v[14]) + (r.v[2] * r.v[9] * r.v[15]) + (r.v[3] * r.v[10] * r.v[13]) - (r.v[1] * r.v[10] * r.v[15]) - (r.v[2] * r.v[11] * r.v[13]) - (r.v[3] * r.v[9] * r.v[14]),
				(r.v[1] * r.v[6] * r.v[15]) + (r.v[2] * r.v[7] * r.v[13]) + (r.v[3] * r.v[5] * r.v[14]) - (r.v[1] * r.v[7] * r.v[14]) - (r.v[2] * r.v[5] * r.v[15]) - (r.v[3] * r.v[6] * r.v[13]),
				(r.v[1] * r.v[7] * r.v[10]) + (r.v[2] * r.v[5] * r.v[11]) + (r.v[3] * r.v[6] * r.v[9]) - (r.v[1] * r.v[6] * r.v[11]) - (r.v[2] * r.v[7] * r.v[9]) - (r.v[3] * r.v[5] * r.v[10]));
			iR.c[1] = Vector4((r.v[4] * r.v[11] * r.v[14]) + (r.v[6] * r.v[8] * r.v[15]) + (r.v[7] * r.v[10] * r.v[12]) - (r.v[4] * r.v[10] * r.v[15]) - (r.v[6] * r.v[11] * r.v[12]) - (r.v[7] * r.v[8] * r.v[14]),
				(r.v[0] * r.v[10] * r.v[15]) + (r.v[2] * r.v[11] * r.v[12]) + (r.v[3] * r.v[8] * r.v[14]) - (r.v[0] * r.v[11] * r.v[14]) - (r.v[2] * r.v[8] * r.v[15]) - (r.v[3] * r.v[10] * r.v[12]),
				(r.v[0] * r.v[7] * r.v[14]) + (r.v[2] * r.v[4] * r.v[15]) + (r.v[3] * r.v[6] * r.v[12]) - (r.v[0] * r.v[6] * r.v[15]) - (r.v[2] * r.v[7] * r.v[12]) - (r.v[3] * r.v[4] * r.v[14]),
				(r.v[0] * r.v[6] * r.v[11]) + (r.v[2] * r.v[7] * r.v[8]) + (r.v[3] * r.v[4] * r.v[10]) - (r.v[0] * r.v[7] * r.v[10]) - (r.v[2] * r.v[4] * r.v[11]) - (r.v[3] * r.v[6] * r.v[8]));
			iR.c[2] = Vector4((r.v[4] * r.v[9] * r.v[15]) + (r.v[5] * r.v[11] * r.v[12]) + (r.v[7] * r.v[8] * r.v[13]) - (r.v[4] * r.v[11] * r.v[13]) - (r.v[5] * r.v[8] * r.v[15]) - (r.v[7] * r.v[9] * r.v[12]),
				(r.v[0] * r.v[11] * r.v[13]) + (r.v[1] * r.v[8] * r.v[15]) + (r.v[3] * r.v[9] * r.v[12]) - (r.v[0] * r.v[9] * r.v[15]) - (r.v[1] * r.v[11] * r.v[12]) - (r.v[3] * r.v[8] * r.v[13]),
				(r.v[0] * r.v[5] * r.v[15]) + (r.v[1] * r.v[7] * r.v[12]) + (r.v[3] * r.v[4] * r.v[13]) - (r.v[0] * r.v[7] * r.v[13]) - (r.v[1] * r.v[4] * r.v[15]) - (r.v[3] * r.v[5] * r.v[12]),
				(r.v[0] * r.v[7] * r.v[9]) + (r.v[1] * r.v[4] * r.v[11]) + (r.v[3] * r.v[5] * r.v[8]) - (r.v[0] * r.v[5] * r.v[11]) - (r.v[1] * r.v[7] * r.v[8]) - (r.v[3] * r.v[4] * r.v[9]));
			iR.c[3] = Vector4((r.v[4] * r.v[10] * r.v[13]) + (r.v[5] * r.v[8] * r.v[14]) + (r.v[6] * r.v[9] * r.v[12]) - (r.v[4] * r.v[9] * r.v[14]) - (r.v[5] * r.v[10] * r.v[12]) - (r.v[6] * r.v[8] * r.v[13]),
				(r.v[0] * r.v[9] * r.v[14]) + (r.v[1] * r.v[10] * r.v[12]) + (r.v[2] * r.v[8] * r.v[13]) - (r.v[0] * r.v[10] * r.v[13]) - (r.v[1] * r.v[8] * r.v[14]) - (r.v[2] * r.v[9] * r.v[12]),
				(r.v[0] * r.v[6] * r.v[13]) + (r.v[1] * r.v[4] * r.v[14]) + (r.v[2] * r.v[5] * r.v[12]) - (r.v[0] * r.v[5] * r.v[14]) - (r.v[1] * r.v[6] * r.v[12]) - (r.v[2] * r.v[4] * r.v[13]),
				(r.v[0] * r.v[5] * r.v[10]) + (r.v[1] * r.v[6] * r.v[8]) + (r.v[2] * r.v[4] * r.v[9]) - (r.v[0] * r.v[6] * r.v[9]) - (r.v[1] * r.v[4] * r.v[10]) - (r.v[2] * r.v[5] * r.v[8]));

			r * iR = m;

			return m;
		}
	}

	// angle, in degrees
	static Matrix4 rotate(float angle)
	{
		Matrix4 r = identity();
		r.c[0] = Vector4(cosf(angle), sinf(angle), 0, 0);
		r.c[1] = Vector4(-sinf(angle), cosf(angle), 0, 0);
		return r;
	}

	static Matrix4 scale(const Vector3 &xyz)
	{
		Matrix4 r = identity();
		r.m[0][0] = xyz.x;
		r.m[1][1] = xyz.y;
		r.m[2][2] = xyz.z;
		return r;
	}

	static Matrix4 translate(const Vector3 &xyz)
	{
		Matrix4 r = identity();
		r.m[2][0] = xyz.x;
		r.m[2][1] = xyz.y;
		r.m[2][2] = xyz.z;
		return r;
	}

#pragma region "Operators"
	Matrix4 operator+(const Matrix4 &b)
	{
		Matrix4 temp;

		// do a member-wise addition
		for (int i = 0; i < 9; ++i)
		{
			temp.v[i] = this->v[i] + b.v[i];
		}

		return temp;
	}

	Matrix4 operator-(const Matrix4 &b)
	{
		Matrix4 temp;

		for (int i = 0; i < 9; ++i)
		{
			temp.v[i] = this->v[i] - b.v[i];
		}

		return temp;
	}

	// Matrix Matrix multiplication
	Matrix4 operator*(const Matrix4 &b)
	{
		{
			//A can now access rows as vector4
			Matrix4 r, A = this->transpose();

			/*for (size_t i = 0; i < 3; ++i)
			r.c[i] = Vector4(dot(A.c[0], B.c[i]), dot(A.c[1], B.c[i]), dot(A.c[2], B.c[i]));*/
			r.c[0] = Vector4(dot(A.c[0], b.c[0]), dot(A.c[1], b.c[0]), dot(A.c[2], b.c[0]), dot(A.c[1], b.c[0]));
			r.c[1] = Vector4(dot(A.c[0], b.c[1]), dot(A.c[1], b.c[1]), dot(A.c[2], b.c[1]), dot(A.c[3], b.c[1]));
			r.c[2] = Vector4(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]), dot(A.c[3], b.c[2]));
			r.c[3] = Vector4(dot(A.c[0], b.c[2]), dot(A.c[1], b.c[2]), dot(A.c[2], b.c[2]), dot(A.c[3], b.c[3]));

			return r;
		}
	}

	// Matrix Vector Multiplication
	Vector4 operator*(const Vector4 &b)
	{
		Matrix4 A = this->transpose();
		Vector4 r;

		r.x = dot(A.c[0], b);
		r.y = dot(A.c[1], b);
		r.z = dot(A.c[2], b);
		r.w = dot(A.c[3], b);

		return r;
	}

#pragma endregion

#pragma endregion

};

