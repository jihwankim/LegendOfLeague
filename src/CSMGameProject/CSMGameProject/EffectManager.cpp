#include "EffectManager.h"

EffectManager::EffectManager()
{

}
EffectManager::~EffectManager()
{
	mEffectList.clear();
}

void EffectManager::Render()
{
	NNObject::Render();
}
void EffectManager::Update( float dTime )
{
	NNObject::Update( dTime );
	for (auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		if ( (*iter)->mIsEnd == true )
		{
			RemoveChild( *iter );
			iter = mEffectList.erase( iter );
			if ( iter == mEffectList.end() )
			{
				break;   
			}
		}
	}
}

void EffectManager::AddEffect( IEffect* effect , int zIndex)
{
	mEffectList.push_back( effect );
	AddChild( effect , zIndex );
}
ATypeAttackEffect* EffectManager::GetATypeAttackEffect(int index)
{
	for(auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		ATypeAttackEffect* pATypeAttackEffect = dynamic_cast<ATypeAttackEffect*>(*iter);
		if(pATypeAttackEffect != nullptr && pATypeAttackEffect->GetIndex() == index)
		{
			return pATypeAttackEffect;
		}
	}
	return nullptr;
}
BTypeAttackEffect* EffectManager::GetBTypeAttackEffect(int index)
{
	for(auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		BTypeAttackEffect* pBTypeAttackEffect = dynamic_cast<BTypeAttackEffect*>(*iter);
		if(pBTypeAttackEffect != nullptr && pBTypeAttackEffect->GetIndex() == index)
		{
			return pBTypeAttackEffect;
		}
	}
	return nullptr;
}