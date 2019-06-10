#include "TextureManager.h"

TextureManager* TextureManager::__Instance = NULL;

TextureManager * TextureManager::GetInstance()
{
	if (__Instance == NULL)
		__Instance = new TextureManager();
	return __Instance;
}

void TextureManager::AddTexture(eType type, Texture *texture)
{
	_ArrTextures[type] = texture;
}

Texture * TextureManager::GetTexture(eType type)
{
	return _ArrTextures[type];
}

void TextureManager::LoadResource()
{
	// Intro
	

	//board
	
	//map
	AddTexture(eType::MAP1, new Texture("Resources/map/NG3-1.png", 79, 1, 79));

	//gameobject ground
	AddTexture(eType::TEX_GROUND3101, new Texture("Resources/Ground/Ground3101.png"));
	AddTexture(eType::TEX_GROUND3102, new Texture("Resources/Ground/Ground3102.png"));
	AddTexture(eType::TEX_GROUND3103, new Texture("Resources/Ground/Ground3103.png"));
	AddTexture(eType::TEX_GROUND3104, new Texture("Resources/Ground/Ground3104.png"));
	AddTexture(eType::TEX_GROUND3105, new Texture("Resources/Ground/Ground3105.png"));
	AddTexture(eType::TEX_GROUND3106, new Texture("Resources/Ground/Ground3106.png"));
	AddTexture(eType::TEX_GROUND3107, new Texture("Resources/Ground/Ground3107.png"));
	AddTexture(eType::TEX_GROUND3108, new Texture("Resources/Ground/Ground3108.png"));
	
	

	//item
	




	// Weapon
	


	//player
	

	//effect
	



	//enemy
	


	//boss
	/*AddTexture(eType::PHANTOMBAT, new Texture("Resources/boss/0.png", 3, 1, 3));*/



}

TextureManager::TextureManager()
{
	LoadResource();
}


TextureManager::~TextureManager()
{
	SAFE_DELETE(__Instance);
}
