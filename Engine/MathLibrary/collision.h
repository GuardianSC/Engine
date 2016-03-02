//#pragma once
//#include "Shapes.h"
//
//struct CollisionData // Wrapper for Minimum Translation Vector
//{
//    bool  collides;         
//    float PenetrationDepth; 
//    Vector2  CollisionNormal;  
//	Vector2  PointOfContact;
//};
//
//// Some distance formula
//float point_plane_dist  (const Vector2 &a, const plane &b);
//float ray_plane_dist    (const ray  &a, const plane &b);
//
//// SAT algorithm!
//CollisionData sat_hull          (const ConvexHull &A, const ConvexHull &B);
//
//// optimized edge-cases
//CollisionData sat_hull_circle   (const ConvexHull &A, const circle     &b); // use radius in all axes of convex hull
//CollisionData sat_hull_ray      (const ConvexHull &A, const ray        &b); // combination of circle and plane algorithms, freebie
//CollisionData sat_hull_plane    (const ConvexHull &A, const plane      &b); // only axis is the plane
//CollisionData sat_hull_AABB     (const ConvexHull &A, const aabb       &b); // aabb only contributes 2 axes
//
//
//// determine whether or not the shapes are overlapping... fast!
//bool iTest_aabb         (const aabb   &a, const aabb   &b);
//bool iTest_aabb_circle  (const aabb   &a, const circle &b);
//bool iTest_aabb_plane   (const aabb   &a, const plane  &b);
//bool iTest_aabb_ray     (const aabb   &a, const ray	   &b);
//bool iTest_circle       (const circle &a, const circle &b);
//bool iTest_circle_plane (const circle &a, const plane  &b);
//bool iTest_circle_ray   (const circle &a, const ray    &b);
//bool iTest_ray_plane    (const ray    &a, const plane  &b);
//
//
//// Calculate the Minimum Translation Vector
//// same algorithms as the fast ones, but we're fetching more data
//CollisionData mtv_aabb           (const aabb   &a, const aabb   &b);
//CollisionData mtv_aabb_circle    (const aabb   &a, const circle &b);
//CollisionData mtv_aabb_plane     (const aabb   &a, const plane  &b);
//CollisionData mtv_aabb_ray       (const aabb   &a, const ray    &b);
//CollisionData mtv_circle         (const circle &a, const circle &b);
//CollisionData mtv_circle_plane   (const circle &a, const plane  &b);
//CollisionData mtv_circle_ray     (const circle  &a, const ray    &b);
//CollisionData mtv_ray_plane      (const ray     &a, const plane  &b);

#pragma once
#include "Shapes.h"
#include "VMath.h"

struct CollisionData // Wrapper for Minimum Translation Vector
{
	bool     isOverlap;         // Did we collide?
	float    PenetrationDepth;
	Vector2  CollisionNormal;   // CollisionNormal * PenetrationDepth = Minimum Translation Vector, also called the impulse vector, very important! 
	Vector2  PointOfContact;    // optional.
};

// Some distance formula
float point_plane_dist(const Vector2 &a, const Plane &b);
float ray_plane_dist(const Ray     &a, const Plane &b);

// All of the basic tests
CollisionData iTest(const AABB   &a, const AABB   &b);
CollisionData iTest(const AABB   &a, const Circle &b);
CollisionData iTest(const AABB   &a, const Ray    &b);
CollisionData iTest(const AABB   &a, const Plane  &b);

CollisionData iTest(const Circle &a, const Circle &b);
CollisionData iTest(const Circle &a, const Plane  &b);
CollisionData iTest(const Circle &a, const Ray    &b);

CollisionData iTest(const Ray    &a, const Plane  &b);

// Convex Hull vs remaining shapes
CollisionData iTest(const ConvexHull &A, const ConvexHull &B);
CollisionData iTest(const ConvexHull &A, const Circle     &b);
CollisionData iTest(const ConvexHull &A, const Ray        &b);
CollisionData iTest(const ConvexHull &A, const Plane      &b);
CollisionData iTest(const ConvexHull &A, const AABB       &b);

// flip overloads for lhs/rhs
inline CollisionData iTest(const Circle &b, const AABB   &a) { return iTest(a, b); }
inline CollisionData iTest(const Plane  &b, const AABB   &a) { return iTest(a, b); }
inline CollisionData iTest(const Ray    &b, const AABB   &a) { return iTest(a, b); }

inline CollisionData iTest(const Plane  &b, const Circle &a) { return iTest(a, b); }
inline CollisionData iTest(const Ray    &b, const Circle &a) { return iTest(a, b); }

inline CollisionData iTest(const Plane  &b, const Ray    &a) { return iTest(a, b); }

inline CollisionData iTest(const Circle &b, const ConvexHull &A) { return iTest(A, b); }
inline CollisionData iTest(const Ray    &b, const ConvexHull &A) { return iTest(A, b); }
inline CollisionData iTest(const Plane  &b, const ConvexHull &A) { return iTest(A, b); }
inline CollisionData iTest(const AABB   &b, const ConvexHull &A) { return iTest(A, b); }