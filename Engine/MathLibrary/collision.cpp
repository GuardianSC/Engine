#include <cmath>
#include <list>
#include <algorithm>
#include "collision.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Shapes.h"

// DSAT calculates the Separating Axis Theorem in 1-D
	// We can calculate the results along the x and y axis separately,
	// and just pick the shortest one
CollisionData DSAT(float amin, float amax, float bmin, float bmax, Vector2 axis)
{
	float pDr = amax - bmin;
	float pDl = bmax - amin;

	float pD = std::fminf(pDr, pDl);

	float H = std::copysignf(1, pDr - pDl);


	return{ pD > 0, pD, axis*H };
}

CollisionData iTest(const AABB &a, const AABB &b)
{
	auto cdx = DSAT(a.min().x, a.max().x, b.min().x, b.max().x, { 1, 0 });
	auto cdy = DSAT(a.min().y, a.max().y, b.min().y, b.max().y, { 0, 1 });

	return cdx.depth < cdy.depth ? cdx : cdy;
}

CollisionData iTest(Circle &a, const AABB &b)
{
	// Snap is just a clamp that includes interior spaces
	// We can create a circle to represent the clamping point
	// and just use the circle vs circle test.
	Circle cp = { Vector2::snap(a.position, b.min(), b.max()), 0 };

	// If the circle's position was inside of the AABB
	// And we use the clamp, our normal will get messed up.
	// To fix that, we need to know whether we clamped from outside
	// or snapped from inside. If so, we need to swap the operands.
	if (b.min() < a.position && a.position < b.max())
		std::swap(a, cp);

	// circle circle test
	return iTest(a, cp);
}

CollisionData iTest(const AABB &a, const Ray &b)
{
	// Separating AABB sides into planes
	Vector2 aabbP1 = (a.min(), a.halfextents); // Down
	Vector2 aabbP2 = (a.max(), a.halfextents); // Up
	Vector2 aabbP1 = (a.min(), a.halfextents); // Left
	Vector2 aabbP2 = (a.max(), a.halfextents); // Right

	// finding each plane's distance to ray
	//d1 = ;
}

CollisionData iTest(const AABB  &a, const Plane  &b)
{
	CollisionData cd = b.normal * (a.position - b.position) <= ;
	return cd;
}

CollisionData iTest(const Circle &a, const Circle &b)
{
	CollisionData cd;
	auto diff = b.position - a.position;

	cd.normal = Vector2::normal(diff);
	cd.depth = (b.radius + a.radius) - diff.magnitude();
	cd.result = cd.depth > 0;

	return cd;
}