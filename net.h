#ifndef _NET_H_
#define _NET_H_

#include <raknet/bitstream.h>
#include <raknet/networktypes.h>
#include <string.h>
#include "urmem.hpp"
#include "trash.h"

namespace net 
{
	AMX* amx;

	const PlayerID GetPlayerIDFromIndex(int index) 
	{
		return urmem::call_function<urmem::calling_convention::thiscall, PlayerID>(Addresses::FUNC_RAKSERVER__GET_PLAYER_ID_FROM_INDEX, Addresses::PTR_RAKSERVER, index);
	}

	bool Send(RakNet::BitStream* bitStream, int priority, int reliability, char orderingChannel, PlayerID playerId, bool broadcast) 
	{
		return urmem::call_function<urmem::calling_convention::thiscall, bool>(Addresses::FUNC_RAKSERVER__SEND, Addresses::PTR_RAKSERVER, bitStream, priority, reliability, orderingChannel, playerId, broadcast);
	}

	static urmem::address_t GetRakServerInterface() 
	{
		const auto rakserver = hkRakNet->call<urmem::calling_convention::cdeclcall, urmem::address_t>();
		const auto vmt = urmem::pointer(rakserver).field<urmem::address_t*>(0);
		Addresses::InitRakServer(rakserver, vmt);
		return rakserver;
	}

	static bool init(void* addr_server)
	{
		urmem::sig_scanner scan;
		urmem::address_t addr_raknet;

		scan.init((urmem::address_t)addr_server);

		scan.find(pattern, mask, addr_raknet);
		hkRakNet = std::make_shared<urmem::hook>(addr_raknet - 7, urmem::get_func_addr(&GetRakServerInterface));
		return true;
	}
};

#endif
