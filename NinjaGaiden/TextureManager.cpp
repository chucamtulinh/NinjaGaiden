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
	AddTexture(eType::MAP1, new Texture("Resources/Maps/NG3-1.png", 79, 1, 79));

	//gameobject ground
	AddTexture(eType::TEX_GROUND3101, new Texture("Resources/Ground/ground3101.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3102, new Texture("Resources/Ground/ground3102.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3103, new Texture("Resources/Ground/ground3103.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3104, new Texture("Resources/Ground/ground3104.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3105, new Texture("Resources/Ground/ground3105.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3106, new Texture("Resources/Ground/ground3106.png", 1, 1, 1));	
	AddTexture(eType::TEX_GROUND3107, new Texture("Resources/Ground/ground3107.png", 1, 1, 1));
	AddTexture(eType::TEX_GROUND3108, new Texture("Resources/Ground/ground3108.png", 1, 1, 1));
	
	//gameobject itemcontainer
	AddTexture(eType::ITEMCONTAINER_31, new Texture("Resources/Sprites/Enemies/ItemContainer.png", 2, 1, 2));

	//item
	




	// Weapon
	


	//player
	AddTexture(eType::RYU, new Texture("Resources/Sprites/Ryu/Idle.png", 1, 1, 1));

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
