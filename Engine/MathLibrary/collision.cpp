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
	auto cdX = DSAT(a.min().x, a.max().x, b.min().x, b.max().x, { 1, 0 });
	auto cdY = DSAT(a.min().y, a.max().y, b.min().y, b.max().y, { 0, 1 });

	return cdX.depth < cdY.depth ? cdX : cdY;
}

CollisionData iTest(const AABB &a, Circle &b)
{
	// Snap is just a clamp that includes interior spaces
	// We can create a circle to represent the clamping point
	// and just use the circle vs circle test.
	Circle cp = { Vector2::snap(b.position, a.min(), a.max()), 0 };

	// If the circle's position was inside of the AABB
	// And we use the clamp, our normal will get messed up.
	// To fix that, we need to know whether we clamped from outside
	// or snapped from inside. If so, we need to swap the operands.
	if (a.min() < a.position && a.position < a.max())
		std::swap(b, cp);

	// circle circle test
	return iTest(b, cp);
}

CollisionData iTest(const AABB &a, const Ray &b)
{
	CollisionData cd;
	int dH = -(a.halfextentH * b.direction);
	int dW = -(a.halfextentW * b.direction);
	bool canCollide;
	// Separating AABB sides into planes
	Vector2 aabbP1 = (a.min(), a.halfextentH); // Down
	Vector2 aabbP2 = (a.max(), a.halfextentH); // Up
	Vector2 aabbP3 = (a.min(), a.halfextentW); // Left
	Vector2 aabbP4 = (a.max(), a.halfextentW); // Right

	// finding each plane's distance to ray
	double d1 = (a.halfextentH * (b.position * a.position)) / dH; // Down
	double d2 = (a.halfextentH * (b.position * a.position)) / dH; // Up
	double d3 = (a.halfextentW * (b.position * a.position)) / dW; // Left
	double d4 = (a.halfextentW * (b.position * a.position)) / dW; // Right

	if (dH != 0) { canCollide = false; }
	if (dW != 0) { canCollide = false; }

	if (canCollide = true)
	{
		//finding min and max distances of each AABB plane
		/*double dMin = Vector2::min();
		double dMax = Vector2::min();*/
	}
}

CollisionData iTest(const AABB  &a, const Plane  &b)
{
	CollisionData cd;
	// Separating AABB sides into planes
	Vector2 aabbP1 = (a.min(), a.halfextentH); // Down
	Vector2 aabbP2 = (a.max(), a.halfextentH); // Up
	Vector2 aabbP3 = (a.min(), a.halfextentW); // Left
	Vector2 aabbP4 = (a.max(), a.halfextentW); // Right
		
	CollisionData::depth = b.normal * (a.position - b.position) <= a.halfextentW * fabs(Vector2::dot(b.normal, aabbP4)) + a.halfextentH * fabs(Vector2::dot(b.normal, aabbP2));
	return cd.depth;

	if (CollisionData::depth > 0) { CollisionData::collide = true; }
}

CollisionData iTest(const Circle &a, const Circle &b)
{
	CollisionData cd;
	auto diff = b.position - a.position;

	cd.normal = Vector2::normal(diff);
	cd.depth = (b.radius + a.radius) - diff.magnitude();
	cd.collide = cd.depth > 0;

	return cd;
}

CollisionData iTest(const Circle &a, const Plane  &b)
{
	CollisionData cd;
	cd.depth = b.normal * (a.position - b.position);

	if (cd.depth <= a.radius) { cd.collide = true; }
}

CollisionData iTest(const Circle &a, const Ray &b)
{
	CollisionData cd;
	double d = cosf(a.position - b.position) * b.direction;

	// Closest point on ray to circle
	double cp = b.position + b.direction * Vector2::clamp((a.position - b.position) * b.direction, 0, b.length);

	if (cp <= a.radius) { cd.collide = true; }
}

CollisionData iTest(const Ray &a, const Plane &b)
{
	CollisionData cd = (b.normal * (b.position - a.position) / -(b.normal * a.direction));
	bool canCollide = false;
	if (-(b.normal * a.direction) > 0)
	{
		canCollide = true;
	}

	if (canCollide = true)
	{
		if (0 <= cd && cd >= a.length)
		{
			{ cd.collide = true; }
		}
	}
}

