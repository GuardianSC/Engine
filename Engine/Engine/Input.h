#pragma once

class Input
{
	Input() : isInitialized(false) {}
	bool isInitialized;

	float keyRelease[400];
	float keyPress[400];
	bool keyState[400];
	bool mouseState[10];

	float mouseRelease[10];
	float mousePress[10];



	float mouseX, mouseY;
public:
	static Input &instance() { static Input instance; return instance; }

	bool init();
	bool step();
	void term();

	bool getKey(unsigned, float threshold = 0); // True if key is down
	bool getKeyPress(unsigned); // True on frame key is pressed
	bool getKeyReleased(unsigned); // True on frame key is released

	bool getMouse(unsigned); // True if key is down
	bool getMousePress(unsigned); // True on frame key is pressed
	bool getMouseReleased(unsigned); // True on frame key is released

	float getMouseX();
	float getMouseY();
};