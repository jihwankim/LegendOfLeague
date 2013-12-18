
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class DTypeSkillEffect : public IEffect
{
public:
	DTypeSkillEffect(float angle, NNPoint startPosition);
	virtual ~DTypeSkillEffect();

	void Render();
	void Update(float dTime);

	void CreateDustEffect();
	void Crash();

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
};
class DTypeAttackEffect : public IEffect
{
public :
	DTypeAttackEffect(float angle, NNPoint startPoint);
	virtual ~DTypeAttackEffect();

	void Render();
	void Update(float dTime);
	void Explose();

private :
	bool mIsCrash;
	NNAnimation *mBullet;
	NNAnimation *mExplosion;
	float mAngle;
	float mSpeed;
	CPlayer *mFollower;
};