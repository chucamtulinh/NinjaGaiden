#pragma once
namespace Define
{
	const float PLAYER_MAX_JUMP_VELOCITY = 150.0f; //van toc nhay lon nhat
	const float PLAYER_MIN_JUMP_VELOCITY = -150.0f; //van toc nhay thap nhat
	const float PLAYER_MAX_RUNNING_SPEED = 75.0f; //toc do chay nhanh nhat cua player
	const float PLAYER_BOTTOM_RANGE_FALLING = 8.0f; // do dai va cham voi bottom neu nhu va cham bottom nho hon thi player se bi roi xuong
}
// ID cua Sprite, object
enum eType
{
	RYU = 01,
	RYU_TRANS = 02,
	RYU_DEADTH = 03,

	// object nen


	// object




	// weapon



	// item


	// other
	RENDERBBOX = 105,

	// Enemy


	//BOSS


	// Intro

};

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif