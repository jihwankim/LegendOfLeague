#include "stdafx.h"
#include "DTypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

DTypeAttack::DTypeAttack(float angle, Point startPosition, Player* ownerPlayer):mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition),Skill(ownerPlayer)
{
	mOwnerPlayer = ownerPlayer;
	GSkillManager->AddSkill(this);

	Bullet* bullet = new Bullet(mOwnerPlayer);
	bullet->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * 30.f);
	bullet->SetShape(CIRCLE);
	bullet->SetRadius(30.f);
	bullet->SetDamage(14);
	bullet->SetLifeTime(0);

	DTypeAttackShootResult outPacket = DTypeAttackShootResult();
	outPacket.mPlayerId = ownerPlayer->GetPlayerInfo().mPlayerId;
	GClientManager->BroadcastPacket(nullptr,&outPacket, mOwnerPlayer->GetGameId());
}


DTypeAttack::~DTypeAttack(void)
{
}

void DTypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool DTypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}