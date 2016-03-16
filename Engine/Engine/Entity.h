#pragma once
#include "GCData.h"

#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Life.h"
#include "PlayerController.h"
#include "Sprite.h"

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
	Handle<PlayerController> controller;
	Handle<Sprite> sprite;

	void onFree()
	{
		Transform::free(transform.index);
		Rigidbody::free(rigidbody.index);
		Collider::free(collider.index);
		Life::free(life.index);
		PlayerController::free(controller.index);
		Sprite::free(sprite.index);
	}
};

