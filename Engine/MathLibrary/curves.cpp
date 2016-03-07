#include "curves.h"
#include "Vector2.h"
#include "Vector3.h"

/*
Could make an object to represent a chain of curves.
*/

Vector2 bezierQuad(const Vector2 &start, const Vector2 &cp1, const Vector2 &end, float t);
Vector2 bezierCubic(const Vector2 &start, const Vector2 &cp1, const Vector2 &cp2, const Vector2 &end, float t);
Vector2 hermiteSpline(const Vector2 &start, const Vector2 &end, const Vector2 &stan, const Vector2 &tend, float t);
Vector2 cardinalSpline(const Vector2 &start, const Vector2 &cp1, const Vector2 &end, float a, float t);

Vector3 bezierQuad(const Vector3 &start, const Vector3 &cp1, const Vector3 &end, float t);
Vector3 bezierCubic(const Vector3 &start, const Vector3 &cp1, const Vector3 &cp2, const Vector3 &end, float t);
Vector3 hermiteSpline(const Vector3 &start, const Vector3 &end, const Vector3 &stan, const Vector3 &tend, float t);
Vector3 cardinalSpline(const Vector3 &start, const Vector3 &cp1, const Vector3 &end, float a, float t);