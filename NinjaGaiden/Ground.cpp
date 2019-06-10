#include "Ground.h"




Ground::Ground(float X, float Y, int W, int H, int Model)
{
	model = Model;
	switch (Model)
	{
	case GROUND3101:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3101); 
		break;
	case GROUND3102:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3102); 
		break;
	case GROUND3103:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3103);
		break;
	case GROUND3104:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3104);
		break;
	case GROUND3105:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3105);
		break;
	case GROUND3106:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3106);
		break;
	case GROUND3107:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3107);
		break;
	case GROUND3108:
		texture = TextureManager::GetInstance()->GetTexture(eType::TEX_GROUND3108);
		break;
	default:
		DebugOut(L"[Ground] Get Texture that bai! Ko nhan dang duoc Model!\n");
		break;
	}

	type = eType::GROUND;
	sprite = new Sprite(texture, 1000);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
}

void Ground::Render(Camera * camera)
{
	if (IS_DEBUG_RENDER_BBOX)
		RenderBoundingBox(camera);

	//return;

	D3DXVECTOR2 pos = camera->Transform(x, y);

	for (int i = 0; i < (int)ceil(width / texture->GetFrameWidth()); i++)
		for (int j = 0; j < (int)ceil(height / texture->GetFrameHeight()); j++)
			sprite->Draw(pos.x + i * texture->GetFrameWidth(), pos.y + j * texture->GetFrameHeight());

	//int vtd = 0;
	//if (x < camera->GetXCam())
	//	vtd =  (camera->GetXCam() - x) / texture->GetFrameWidth();

	//int vtc = (int)ceil(width / texture->GetFrameWidth());// min((int)ceil(width / texture->GetFrameWidth()), vtd + camera->GetWidth() / texture->GetFrameWidth());


	//for (int i = vtd; i < vtc; i++)
	//	for (int j = 0; j < (int)ceil(height / texture->GetFrameHeight()); j++)
	//		sprite->Draw((int)pos.x + i * texture->GetFrameWidth(), (int)pos.y + j * texture->GetFrameHeight());
	//
	//for (int i = 0; i < (int)ceil(width / texture->GetFrameWidth()); i++)
	//	for (int j = 0; j < (int)ceil(height / texture->GetFrameHeight()); j++)
	//		sprite->Draw((int)pos.x + i * texture->GetFrameWidth(), (int)pos.y + j * texture->GetFrameHeight());
	// 

}

void Ground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + (float)ceil(width / texture->GetFrameWidth())*texture->GetFrameWidth();
	b = y + (float)ceil(height / texture->GetFrameHeight())*texture->GetFrameHeight();
}

int Ground::GetModel()
{
	return model;
}
