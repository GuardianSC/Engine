#include <iostream>
#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
#include "Factory.h"
#include "DebugDraw.h"
#include "RigidbodyDynamics.h"
#include "LifeSystem.h"
#include "CollisionDetection.h"
#include "DynamicResolution.h"
#include "PlayerSystem.h"
#include "RenderSystem.h"
#include "Assets.h"


void main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Factory::makeBall({ 40,  40 },  {10,10},  400,  40)->rigidbody->addTorque(1000);
	Factory::makeBall({ 80,  200 },  { 100,0}, 120, 120);
	auto e = Factory::makeBall({ 720, 200 }, {}, 60, 1);

	Assets::instance().loadTexture("Soldier", "../Engine/player.png");
	e->controller = PlayerController::make();
	e->sprite = Sprite::make();
	e->sprite->assetName = "soldier";
	e->sprite->dimension = Vector2{ 72,72 };

	DebugDraw debugDraw;
	RigidbodyDynamics rigidbodyDynamics;
	LifeSystem lifeSystem;
	CollisionDetection collisionDetection;
	DynamicResolution dynamicResolution;
	PlayerSystem playerSystem;
	RenderSystem renderSystem;

	while (window.step())
	{
		input.step();
		time.step();

		debugDraw.step();
		//std::cout << e->rigidbody->force << std::endl;
		
		playerSystem.step();
		rigidbodyDynamics.step();
		lifeSystem.step();
		collisionDetection.step();
		dynamicResolution.step();
		playerSystem.step();
	}

	time.term();
	input.term();
	window.term();
}