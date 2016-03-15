#pragma once
#include "System.h"
#include "Entity.h"
#include "Time.h"

class LifeSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->lifetime > -1;
	}

	void update(Handle<Entity> i)
	{
		if (i->lifespan->lifetime > i->lifespan->lifespan)
			Entity::free(i);
		else
		i->lifespan->lifetime += Time::instance().getDeltaTime();
	}
};