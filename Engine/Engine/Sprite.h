#pragma once
#include <string>
#include "GCData.h"
#include "Vector2.h"

class Sprite : public GCData<Sprite>
{
public:
	Vector2 offset;
	Vector2 dimension;
	float angle;

	std::string assetName;

	Sprite() : offset({}), dimension({1,1}), angle(0), assetName("") {} // ({}) = ({0,0})
};