
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"

class DTypeSkillEffect : public IEffect
{
public:
	DTypeSkillEffect(float angle, NNPoint startPosition, int playerId);
	virtual ~DTypeSkillEffect();

	void Render();
	void Update(float dTime);

	void CreateDustEffect();
	void Crash();
	int GetIndex(){ return mPlayerId; }

private:
	NNSprite *mTemp;
	NNAnimation *mDashEffect;
	NNAnimation *mExplosionEffect;
	NNPoint mDustPoint;
	float mDustTimeCount;
	float mDustCreateTerm;
	float mDistance;
	float mSpeed;
	float mAngle;
	bool mIsCrash;
	int mPlayerId;
	CPlayer* mPlayer;
};
class DTypeAttackEffect : public IEffect
{
public :
	DTypeAttackEffect(int PlayerID);
	virtual ~DTypeAttackEffect();

	void Render();
	void Update(float dTime);

private :
	NNAnimation *mSlash;
	CPlayer *mFollower;
};