
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"

class HPUpdateHandler : public NNBaseHandler
{
public:
	HPUpdateHandler();
	virtual ~HPUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	HPUpdateResult mHPUpdateResult;
};

class MouseAngleUpdateHandler : public NNBaseHandler
{
public:
	MouseAngleUpdateHandler();
	virtual ~MouseAngleUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	MouseAngleUpdateRequest mMouseAngleUpdateRequest;
	MouseAngleUpdateResult mMouseAngleUpdateResult;
};

class GameKeyStatesUpdateHandler : public NNBaseHandler
{
public:
	GameKeyStatesUpdateHandler();
	virtual ~GameKeyStatesUpdateHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );
	GameKeyStatesUpdateRequest mGameKeyStatesUpdateRequest;
	GameKeyStatesUpdateResult mGameKeyStatesUpdateResult;
};

class LoginHandler : public NNBaseHandler
{
public:
	LoginHandler();
	virtual ~LoginHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginRequest mLoginRequestPacket;
	LoginResult mLoginResultPacket;
};

class LoginBroadcastHandler : public NNBaseHandler
{
public:
	LoginBroadcastHandler();
	virtual ~LoginBroadcastHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginBroadcastResult mLoginBroadcastResultPacket;
};

class LogoutHandler : public NNBaseHandler
{
public:
	LogoutHandler();
	virtual ~LogoutHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LogoutResult mLogoutResultPacket;
};