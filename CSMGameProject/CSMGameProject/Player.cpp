
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"

CPlayer::CPlayer( void )
	: m_PlayerSprite(NULL)
{
	TransState(PlayerState::IDLE);
}

CPlayer::~CPlayer( void )
{
}

void CPlayer::TransState( PlayerState state )
{
	m_PlayerState = state;
	if ( m_PlayerSprite != NULL )
	{
		RemoveChild( m_PlayerSprite );
	}

	/* Player Sprite Setting */
	m_PlayerSprite = NNSprite::Create( L"Sprite/walk_0.png" );
	AddChild( m_PlayerSprite );
	 
	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	/* // */

	m_PlayerUI = PlayerUI::Create();
	AddChild( m_PlayerUI );
}


void CPlayer::Update( float dTime )
{
	NNObject::Update( dTime );

	//Move myPlayer with Game Key States.
	//Check Moving Input, and set Position to d
	if ( m_GameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )
	{   //Left
		SetPosition( GetPosition() + NNPoint( -1.f, 0.f) * dTime * 100.f );
	}
	if ( m_GameKeyStates.rightDirectKey == KEYSTATE_PRESSED )
	{   //Right
		SetPosition( GetPosition() + NNPoint( 1.f, 0.f) * dTime * 100.f );
	}
	if (m_GameKeyStates.upDirectKey == KEYSTATE_PRESSED )
	{   //UP
		SetPosition( GetPosition() + NNPoint( 0.f, -1.f) * dTime * 100.f );
	}
	if ( m_GameKeyStates.downDirectKey == KEYSTATE_PRESSED )
	{   //Down
		SetPosition( GetPosition() + NNPoint( 0.f, 1.f) * dTime * 100.f );
	}
}
void CPlayer::Render()
{
	NNObject::Render();
}