#include "curves.h"
#include "Vector2.h"
#include "Vector3.h"

Vector2 bezierQuad(const Vector2 &start, const Vector2 &cp1, const Vector2 &end, float t)
{
	Vector2 mid1 = Vector2::lerp(start, cp1, end);

	Vector2 mid2 = Vector2::lerp(cp1, end, t);

	return Vector2::lerp(mid1, mid2, t);
}
Vector2 bezierCubic(const Vector2 &start, const Vector2 &cp1, const Vector2 &cp2, const Vector2 &end, float t)
{
	Vector2 mid1 = Vector2::lerp(start, cp1, cp2);

	Vector2 mid2 = Vector2::lerp(cp1, cp2, end);

	Vector2 mid3 = Vector2::lerp(cp2, end, t);

	return Vector2::lerp(mid1, mid2, mid3, t);
}
Vector2 hermiteSpline(const Vector2 &start, const Vector2 &end, const Vector2 &stan, const Vector2 &tend, float t)
{
	float tsq = t * t;

	float tcub = tsq * t;

	float h0 = 2 * tcub - 3 * tsq + 1;

	float h1 = -2 * tcub + 3 * tsq;

	float h2 = tcub - 2 * tsq + t;

	float h3 = tcub - tsq;

	Vector2 point = h0 * start + h1 * stan + h2 * end + h3 * tend;

	return point;
}
Vector2 cardinalSpline(const Vector2 &start, const Vector2 &cp1, const Vector2 &end, float a, float t)
{
	Vector2 tan0 = (cp1 – start) * a;
	Vector2 tan1 = (end – cp1) * a;
	float tsq = t * t;
	float tcub = tsq * t;
	float h0 = 2 * tcub - 3 * tsq + 1;
	float h1 = -2 * tcub + 3 * tsq;
	float h2 = tcub - 2 * tsq + t;
	float h3 = tcub - tsq;
	Vector2 point = h0 * start + h2 * tan0 + h1 * cp1 + h3 * tan1;
	return point;
}

Vector3 bezierQuad(const Vector3 &start, const Vector3 &cp1, const Vector3 &end, float t)
{
	Vector3 mid1 = Vector3::lerp(start, cp1, end);

	Vector3 mid2 = Vector3::lerp(cp1, end, t);

	return Vector3::lerp(mid1, mid2, t);
}
Vector3 bezierCubic(const Vector3 &start, const Vector3 &cp1, const Vector3 &cp2, const Vector3 &end, float t)
{
	Vector3 mid1 = Vector3::lerp(start, cp1, cp2);

	Vector3 mid2 = Vector3::lerp(cp1, cp2, end);

	Vector3 mid3 = Vector3::lerp(cp2, end, t);

	return Vector3::lerp(mid1, mid2, mid3, t);
}
Vector3 hermiteSpline(const Vector3 &start, const Vector3 &end, const Vector3 &stan, const Vector3 &tend, float t)
{
	float tsq = t * t;

	float tcub = tsq * t;

	float h0 = 2 * tcub - 3 * tsq + 1;

	float h1 = -2 * tcub + 3 * tsq;

	float h2 = tcub - 2 * tsq + t;

	float h3 = tcub - tsq;

	Vector3 point = h0 * start + h1 * stan + h2 * end + h3 * tend;

	return point;
}
Vector3 cardinalSpline(const Vector3 &start, const Vector3 &cp1, const Vector3 &end, float a, float t)
{
	Vector3 tan0 = (cp1 – start) * a;
	Vector3 tan1 = (end – cp1) * a;
	float tsq = t * t;
	float tcub = tsq * t;
	float h0 = 2 * tcub - 3 * tsq + 1;
	float h1 = -2 * tcub + 3 * tsq;
	float h2 = tcub - 2 * tsq + t;
	float h3 = tcub - tsq;
	Vector3 point = h0 * start + h2 * tan0 + h1 * cp1 + h3 * tan1;
	return point;
}