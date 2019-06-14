#include "SwordSlashWeapon.h"



SwordSlashWeapon::SwordSlashWeapon()
{
	type = eType::SWORDSLASHWEAPON;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, SWORDSLASHWEAPON_TIME_WAIT_ANI);
}


SwordSlashWeapon::~SwordSlashWeapon()
{
}

void SwordSlashWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt);

	// update for check collision

	isFinish = (sprite->GetCurrentFrame() == 3);

	int StartFrame = SWORDSLASHWEAPON_ANI_START; // ánh xạ chỉ số frame bằng level thay vì ifelse 
	int EndFrame = SWORDSLASHWEAPON_ANI_END;


	if (StartFrame <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < EndFrame)
		sprite->Update(dt);
	else
	{
		sprite->SelectFrame(StartFrame);
	}


	//DebugOut(L"update ani SWORDSLASHWEAPON dt = %d, tich luy = %d\n", dt, sprite->timeAccumulated);

}

void SwordSlashWeapon::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == -1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);


	if (IS_DEBUG_RENDER_BBOX)
	{
		if (sprite->GetCurrentFrame() == SWORDSLASHWEAPON_ANI_START || sprite->GetCurrentFrame() == SWORDSLASHWEAPON_ANI_START + 1)
			return; // frame đầu và frame chuẩn bị đánh thì vẽ BBOX
	}
}

void SwordSlashWeapon::Attack(float X, float Y, int Direction)
{


	Weapon::Attack(X, Y, Direction);

	UpdatePositionFitRyu();
	sprite->SelectFrame(SWORDSLASHWEAPON_ANI_START);
	sprite->ResetTime();
	//Sound::GetInstance()->Play(eSound::soundWhip);
}

void SwordSlashWeapon::UpdatePositionFitRyu()
{
	if (direction == -1)
	{
		this->x = x - 22;
		this->y = y + 1;
	}
}

void SwordSlashWeapon::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (direction == 1)
	{
		left = x + 22;
		top = y + 5;
		right = x + 40;
		bottom = y + 13;
	}
	else
	{
		left = x;
		top = y + 5;
		right = x + 18;
		bottom = y + 13;

	}
}

void SwordSlashWeapon::RenderIcon(float X, float Y)
{
}

bool SwordSlashWeapon::isCollision(GameObject * obj)
{
	if (sprite->GetCurrentFrame() == SWORDSLASHWEAPON_ANI_START || sprite->GetCurrentFrame() == SWORDSLASHWEAPON_ANI_END)
		return false; // frame đầu và frame chuẩn bị đánh thì ko xét va chạm

	return Weapon::isCollision(obj);
}
