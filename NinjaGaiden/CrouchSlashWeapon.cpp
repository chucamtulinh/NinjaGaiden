#include "CrouchSlashWeapon.h"



CrouchSlashWeapon::CrouchSlashWeapon()
{
	type = eType::CROUCHSLASHWEAPON;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new Sprite(texture, CROUCHSLASHWEAPON_TIME_WAIT_ANI);
}


CrouchSlashWeapon::~CrouchSlashWeapon()
{
}

void CrouchSlashWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt);

	// update for check collision

	isFinish = (sprite->GetCurrentFrame() == 2);

	int StartFrame = CROUCHSLASHWEAPON_ANI_START; // ánh xạ chỉ số frame bằng level thay vì ifelse 
	int EndFrame = CROUCHSLASHWEAPON_ANI_END;


	if (StartFrame <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < EndFrame)
		sprite->Update(dt);
	else
	{
		sprite->SelectFrame(StartFrame);
	}


	//DebugOut(L"update ani CROUCHSLASHWEAPON dt = %d, tich luy = %d\n", dt, sprite->timeAccumulated);

}

void CrouchSlashWeapon::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == -1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);


	if (IS_DEBUG_RENDER_BBOX)
	{
		if (sprite->GetCurrentFrame() == CROUCHSLASHWEAPON_ANI_START || sprite->GetCurrentFrame() == CROUCHSLASHWEAPON_ANI_START + 1)
			return; // frame đầu và frame chuẩn bị đánh thì vẽ BBOX
	}

}




void CrouchSlashWeapon::Attack(float X, float Y, int Direction)
{


	Weapon::Attack(X, Y, Direction);

	UpdatePositionFitRyu();
	sprite->SelectFrame(CROUCHSLASHWEAPON_ANI_START);
	sprite->ResetTime();
	//Sound::GetInstance()->Play(eSound::soundWhip);
}

void CrouchSlashWeapon::UpdatePositionFitRyu()
{
	if (direction == -1)
	{
		this->x = x - 75;
		this->y -= 2;

	}
	else
	{
		this->x = x - 25;
		this->y -= 2;
	}
}

void CrouchSlashWeapon::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{	
	if (direction == 1)
	{
		left = x;
		top = y;
		right = x + texture->GetFrameWidth();
		bottom = y + texture->GetFrameHeight();
	}
	else
	{
		left = x;
		top = y;
		right = x + texture->GetFrameWidth();
		bottom = y + texture->GetFrameHeight();

	}
}

void CrouchSlashWeapon::RenderIcon(float X, float Y)
{
}

bool CrouchSlashWeapon::isCollision(GameObject * obj)
{
	if (sprite->GetCurrentFrame() == CROUCHSLASHWEAPON_ANI_START || sprite->GetCurrentFrame() == CROUCHSLASHWEAPON_ANI_START + 1)
		return false; // frame đầu và frame chuẩn bị đánh thì ko xét va chạm

	return Weapon::isCollision(obj);
}
