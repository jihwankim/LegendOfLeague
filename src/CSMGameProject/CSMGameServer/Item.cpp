#include "stdafx.h"
#include "Item.h"
#include "ClientManager.h"
#include "PlayerManager.h"

Item::Item()
{

}
Item::Item(int itemId,int gameId, Point position)
{
	mItemId = itemId;
	mGameId = gameId;
	mPosition = position;
	ItemComeResult outPacket = ItemComeResult();
	outPacket.mItemType = GetItemType();
	outPacket.mPosition = GetPosition();
	GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
}


Item::~Item(void)
{
}
void Item::ConsumeBy(int playerId)
{ 
	mIsConsumed = true; 
	mOwnerId = playerId; 
	GPlayerManager->GetPlayer(playerId)->ConsumeItem(this);
}

void Item::RemoveEffect()
{
	GPlayerManager->GetPlayer(mOwnerId)->DropItem(this);
}