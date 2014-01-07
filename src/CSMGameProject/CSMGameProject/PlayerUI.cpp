
#include "PlayerUI.h"
#include "Player.h"
#include "NNApplication.h"
#include "PlayerManager.h"
#include "NNInputSystem.h"
#include "EffectManager.h"

#include "EmoticonEffect.h"

PlayerUI::PlayerUI(NNObject *follower)
{
	mFollower = follower;
}

PlayerUI::~PlayerUI()
{
}

void PlayerUI::Init()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mHpBar[BLUE] = NNSprite::Create( L"Resource/Sprite/UI/GameUI/BlueHpBar.png" );
	mHpBar[RED] = NNSprite::Create(L"Resource/Sprite/UI/GameUI/RedHpBar.png");
	mHpBar[2] = NNSprite::Create(L"Resource/Sprite/UI/GameUI/MyHpBar.png");

	mHpBar[BLUE]->SetPosition( 0.f, -40.f );
	mHpBar[RED]->SetPosition(0.f, -40.f);
	mHpBar[2]->SetPosition(0.f, -40.f);

	CPlayer *temp = dynamic_cast<CPlayer*>(mFollower);
	wsprintf(mNicknameBuf, L"%s", temp->GetNickname().c_str());// L"NICKNAME");
	mNickname = NNLabel::Create(mNicknameBuf, L"���� ����", 10.f);
	mNickname->SetPosition(0.f, -50.f);

	AddChild(mHpBar[BLUE]);
	AddChild(mHpBar[RED]);
	AddChild(mHpBar[2]);
	AddChild(mNickname, 99);

	mIsMyPlayer = CPlayerManager::GetInstance()->GetMyPlayer() == temp;
	SetCenter( mHpBar[BLUE]->GetImageWidth()/2.f, mHpBar[BLUE]->GetImageHeight()/2.f );

	mTeam = -1;
}

void PlayerUI::Render()
{
	NNObject::Render();
}

void PlayerUI::Update( float dTime )
{
	NNObject::Update( dTime );

	mHpBar[BLUE]->SetVisible(false);
	mHpBar[RED]->SetVisible(false);
	mHpBar[2]->SetVisible(false);

	if (mIsMyPlayer == true)
		mTeam = 2;
	else if (mTeam == -1)
	{
		mTeam = (TeamColor)(dynamic_cast<CPlayer*>(mFollower)->GetTeam());
		return;
	}
	
	
	mHpBar[mTeam]->SetVisible(true);
	mHpBar[mTeam]->SetScale(mHp / 50.f, 1.f);

	

}