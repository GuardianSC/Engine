#pragma once
#include "GCData.h"

#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Life.h"

struct Entity : GCData<Entity>
{
	// Name
	// Tag
	// Active
	// TypeID

	Handle<Transform> transform;
	Handle<Rigidbody> rigidbody;
	Handle<Collider > collider;
	Handle<Life> life;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
		Life::free(life.index);
	}
};

