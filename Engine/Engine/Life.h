#pragma once
#include "GCData.h"

class Life : public GCData<Life>
{
public:
	float lifetime;
	float lifespan;

	Life() : lifetime(0), lifespan(5) {}
	~Life() {}
};