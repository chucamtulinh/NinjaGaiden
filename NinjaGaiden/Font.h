#ifndef __FONT_H__
#define __FONT_H__

#include "Sprite.h"
#include "Texture.h"
#include "GameDefine.h"
#include <string>

#include "TextureManager.h"

class Font
{
private:
	Sprite * _sprite;
	Texture * _texture;

public:
	Font();
	~Font();
	void Draw(float x, float y, const std::string & s);
};

#endif 