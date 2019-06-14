#include "ThrowCross.h"



ThrowCross::ThrowCross(Camera * camera)
{
	type = eType::THROWCROSS;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, 70);


	_spriteIcon = new Sprite(TextureManager::GetInstance()->GetTexture(eType::ITEMTHROWCROSS), 0);

	isFinish = true;
	this->camera = camera;
}


ThrowCross::~ThrowCross()
{
	//if (Sound::GetInstance()->isPlaying(eSound::soundAxe))
	//	Sound::GetInstance()->Stop(eSound::soundAxe);
}

void ThrowCross::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!camera->checkObjectInCamera(x, y, (float)GetWidth(), (float)GetHeight())) // xử lí ra khỏi cam thì kết thúc
	{
		isFinish = true;

		//if (Sound::GetInstance()->isPlaying(eSound::soundAxe))
			//Sound::GetInstance()->Stop(eSound::soundAxe);

		return;
	}

	GameObject::Update(dt); //update dt dx d 
	vy += THROWCROSS_GRAVITY * dt * 2;

	y += dy;
	x += dx;

	sprite->Update(dt);
}

void ThrowCross::Attack(float X, float Y, int Direction)
{
	if (isFinish == false)
		return;
	Weapon::Attack(X, Y, Direction);
	//UpdatePositionFitSimon();
	vx = THROWCROSS_SPEED_X * Direction;
	vy = -THROWCROSS_SPEED_Y;

	//Sound::GetInstance()->Play(eSound::soundAxe, true);
}

void ThrowCross::RenderIcon(float X, float Y)
{
	_spriteIcon->Draw(X, Y);
}
