#ifndef __RYU_H__
#define __RYU_H__
#include "Sprite.h"
#include "Camera.h"
#include "GameObject.h"
#include "Weapon.h"
#include "CrouchSlashWeapon.h"
#include "SwordSlashWeapon.h"
#include "Texture.h"
#include "GameDefine.h"

#define Ryu_POSITION_DEFAULT  25.0f, 206.0f // heightboard 100

#define Ryu_BBOX_WIDTH 17
#define Ryu_BBOX_HEIGHT 32
#define Ryu_BBOX_SITTING_HEIGHT 24
#define Ryu_BBOX_JUMPING_HEIGHT 30
#define Ryu_BBOX_JUMPING_WIDTH 20

#define PULL_UP_Ryu_AFTER_SITTING 8.0f // Kéo Ryu lên 8px sau khi ngồi rồi đứng dậy, tránh overlaping do BBOX bottom thu lại khi ngồi

#define Ryu_VJUMP 0.3f
#define Ryu_VJUMP_HURTING 0.2f // nhảy lúc bị đau
#define PULL_UP_Ryu_AFTER_JUMPING 8.0f // Kéo Ryu lên 8px sau khi nhảy, tránh overlaping do BBOX bottom thu lại khi nhảy

#define Ryu_GRAVITY 0.001f
#define Ryu_GRAVITY_JUMPING 0.001f
#define Ryu_GRAVITY_HURTING 0.001f

#define Ryu_RUNNING_SPEED 0.12f //0.12f
#define Ryu_JUMPING_SPEED 0.06f

#define Ryu_STATE_IDLE 0
#define Ryu_STATE_RUNNING 1

#define Ryu_ANI_RUNNING_BEGIN 1
#define Ryu_ANI_RUNNING_END 3

#define Ryu_ANI_IDLE 0

#define Ryu_ANI_JUMPING_BEGIN 11
#define Ryu_ANI_JUNPING_END 14

#define Ryu_ANI_SITTING 7



/*Ani đang ngồi đánh*/
#define Ryu_ANI_SITTING_ATTACKING_BEGIN 8
#define Ryu_ANI_SITTING_ATTACKING_END 10

/*Ani đang đứng đánh*/
#define Ryu_ANI_STANDING_ATTACKING_BEGIN 4
#define Ryu_ANI_STANDING_ATTACKING_END 6

/* Time Ani attack */
#define Ryu_TIME_WAIT_ANI_ATTACKING 80// thời gian thời của mỗi frame khi tấn công
#define Ryu_TIME_WAIT_ANI_JUMPING 80 // thời gian mỗi frame nhảy


#define Ryu_ANI_HURTING 12


#define TIME_FREEZE_MAX 500


#define Ryu_DEFAULT_HEALTH 16
#define Ryu_DEFAULT_MANACOLLECT 0
#define Ryu_DEFAULT_SCORE 0
#define Ryu_DEFAULT_LIVES 3

#define Ryu_UNTOUCHABLE_TIME 2000
class Ryu : public GameObject
{
private:
	Sprite * _sprite_death;

	int ManaCollect; // số lượng item heart người chơi nhặt được
	int Lives; // số mạng của Ryu
	int score; // điểm

	bool isFreeze; // Trạng thái đóng băng thay đổi màu liên tục
	DWORD TimeFreeze; // thời gian đã đóng băng

	D3DXVECTOR2 PositionBackup;


	bool isRunning_Backup;
	bool isJumping_Backup;
	bool isSitting_Backup;
	bool isAttacking_Backup;
	bool isOnStair_Backup;
	int isProcessingOnStair_Backup;
	int directionStair_Backup;
	int directionY_Backup;
	int directionAfterGo;

	float AutoGoX_Distance; // khoảng cách Ryu cần tự đi
	float AutoGoX_Speed; // vận tốc đi tự động
	float AutoGoX_DirectionGo; // hướng tự động đi
	float AutoGoX_Backup_X; // lưu vị trí trước khi đi tự động

	bool isAutoGoX = 0; // đang ở chế độ auto go?

	bool isDeath;

	eType TypeWeaponCollect; // loại vũ khí phụ đang giữ

	Camera * camera;
	//Sound * sound;
	bool isUseDoubleShot;


public:

	bool isAttacking;
	bool isHurting;
	bool isRunning;
	bool isJumping;
	bool isSitting;

	int directionY; // hướng đi theo trục y của Ryu

	bool untouchable;
	DWORD untouchable_start;

	bool isCollisionAxisYWithGround = false; // Đang va chạm với đất theo trục y

	DWORD TimeWaitedAfterDeath;


public:
	Ryu(Camera* camera);
	~Ryu();

	unordered_map<eType, Weapon*> mapWeapon;

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);

	void Sit();

	void Stop();
	void ResetSit();

	void Go();
	void Jump();
	void Right();
	void Left();

	void SetHurt(LPCOLLISIONEVENT e);

	void SetManaCollect(int h);
	int GetManaCollect();

	void CollisionWithGround(const vector<LPGAMEOBJECT> *coObjects = NULL);

	//bool isCollisionWithItem(Item * objItem);


	void Attack(eType typeWeapon);

	int GetLives();
	void SetLives(int l);
	int GetScore();
	void SetScore(int s);

	bool GetFreeze();
	void SetFreeze(int f);
	void UpdateFreeze(DWORD dt);

	void StartUntouchable();



	void SetAutoGoX(int DirectionGo, int DirectionBackup, float Dx, float Speed); // set các thông số auto và backup các trạng thái hiện tại
	bool GetIsAutoGoX(); // kiểm tra có đang ở chế độ auto go?

	void RestoreBackupAutoGoX(); // khôi phục trạng thái

	bool LoseLife(); // thiết lập lại 1 số thứ sau khi Ryu mất mạng
	void SetPositionBackup(float X, float Y);  // lưu vị trí cần backup để Ryu die thì bắt đầu lại từ đây


	void SetDeath();
	bool GetIsDeath();
	void SetIsDeath(bool b);

	eType GetTypeWeaponCollect();
	void SetTypeWeaponCollect(eType t);
	void ProcessWeaponCollect(eType t);
	bool IsUsingWeapon(eType typeWeapon);

	bool GetIsUseDoubleShot();
	void SetIsUseDoubleShot(bool b);

	void Init(); // khởi tạo lại các trạng thái, ManaCollect, Heath, Lives, Score
	void Reset(); // khởi tạo lại các trạng thái.

};

#endif
