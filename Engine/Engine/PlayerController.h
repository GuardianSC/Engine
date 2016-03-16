#pragma once
#include "GCData.h"

class PlayerController : public GCData<PlayerController>
{
public:
	char LEFT, RIGHT, UP;

	float speed, turnSpeed, terminalVelocity, terminalAngleVelocity;

	PlayerController() : LEFT ('A'), RIGHT('D'), UP('W'), speed(300), turnSpeed(300) {}
};