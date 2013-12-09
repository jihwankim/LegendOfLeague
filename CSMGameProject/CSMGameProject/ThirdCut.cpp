#include "ThirdCut.h"
#include "NNApplication.h"

ThirdCut::ThirdCut()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mBackground = NNSprite::Create( L"Sprite/StoryScene_2.png" );
	mBackground->SetPosition( width/2, height/2 );
	mBackground->SetCenter( mBackground->GetImageWidth()/2.f, mBackground->GetImageHeight()/2.f );
	AddChild( mBackground );

	mStoryTextBox = NNSprite::Create( L"Sprite/StoryTextBox.png");
	mStoryTextBox->SetPosition( width/2, height/2 + 200.f );
	mStoryTextBox->SetCenter( mStoryTextBox->GetImageWidth()/2.f, mStoryTextBox->GetImageHeight()/2.f );
	AddChild( mStoryTextBox );

	mText = NNLabel::Create( L"현재 정령왕은 신틸리케입니다. \n신틸레케는 최선을 다해 자신의 소명을 다하였습니다.", L"맑은 고딕", 20.f );
	AddChild( mText );

	mText->SetPosition( 100.f, 460.f );
	mText->SetBold( true );
}
ThirdCut::~ThirdCut()
{

}

void ThirdCut::Render()
{
	StoryCut::Render();
}
void ThirdCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}