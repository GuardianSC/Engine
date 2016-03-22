#include "Assets.h"
#include "sfwdraw.h"
#include "Window.h"

struct Matrix4 { float m[16]; };

Matrix4 matrix3to4(const float *m, float Z)
{
	return
	{ m[0],m[1], 0, m[2],
		m[3],m[4], 0, m[5],
		0 ,  0 , 1 ,  0,
		m[6],m[7], Z, m[8] };
}

void Assets::loadTexture(const std::string &name, const char *path)
{
	assert(Window::instance().isInitialized() && "Window is not initialized!");

	Texture temp;
	temp.handle = sfw::loadTextureMap(path);
	temp.height = sfw::getTextureHeight(temp.handle);
	temp.width = sfw::getTextureWidth(temp.handle);

	textures[name] = temp;
}

void Assets::drawTexture(const std::string &name, const Matrix3 &m/* = Matrix3::identity()*/)
{
	sfw::drawTextureMatrix(getTexture(name).handle, 0, WHITE, m.v);
}

Assets::Texture Assets::getTexture(const std::string &name) { return textures[name]; }