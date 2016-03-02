#include "Input.h"
#include "Window.h"
#include "sfwdraw.h"
#include <cstring>

//Input::Input() : isInitialized(false)
//{
//	memset(keyRelease, 0, 400);
//	memset(keyPress, 0, 400);
//	memset(mouseRelease, 0, 10);
//	memset(mousePress, 0, 10);
//
//	return isInitialized = Window::instance().isInitialized();
//}

bool Input::step()
{
	for (unsigned i = 0; i < 400; ++i)
	{
		if (keyState[i] = sfw::getKey(i))
		{
			keyPress[i] = sfw::getTime();
		}
		else
		{
			keyRelease[i] = sfw::getTime();
		}
	}

	for (unsigned i = 0; i < 400; ++i)
	{
		if (mouseState[i] = sfw::getKey(i))
		{
			mousePress[i] = sfw::getTime();
		}
		else
		{
			mouseRelease[i] = sfw::getTime();
		}
	}

	mouseX = sfw::getMouseX();
	mouseY = sfw::getMouseY();
	return false;
}

//bool Input::getKey(unsigned key) { return keyPress[key] > keyRelease[key]; }