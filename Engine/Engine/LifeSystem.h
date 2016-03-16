#pragma once
#include "System.h"
#include "Entity.h"
#include "Time.h"

class LifeSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->life > -1;
	}
	void update(Handle<Entity> i)
	{
		if (i->life->lifetime > i->life->lifespan)
			Entity::free(i);
		else
			i->life->lifetime += Time::instance().getDeltaTime();
	}
};