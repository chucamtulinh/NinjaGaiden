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
	AddTexture(eType::TEX_GROUND3102, new Texture("Resources/Ground/ground3109.png", 1, 1, 1));

	//gameobject itemcontainer
	AddTexture(eType::ITEMCONTAINER_31, new Texture("Resources/Sprites/Enemies/ItemContainer.png", 2, 1, 2));

	//item





	// Weapon
	AddTexture(eType::CROUCHSLASHWEAPON, new Texture("Resources/Weapon/CrouchSlashWeapon.png", 4, 1, 4));
	AddTexture(eType::SWORDSLASHWEAPON, new Texture("Resources/Weapon/SwordSlashWeapon.png", 4, 1, 4));

	//player
	AddTexture(eType::RYU, new Texture("Resources/Sprites/Ryu/Ryu_fix.png", 21, 1, 21));
	AddTexture(eType::RYU_DEATH, new Texture("Resources/Sprites/Ryu/.png")); //  chưa load death

	//effect




	//enemy
	AddTexture(eType::SWORDMAN, new Texture("Resources/Sprites/Enemies/SwordMan.png", 3, 1, 3));


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
