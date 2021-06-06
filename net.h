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

	class thiscall_hooks 
	{
	public:
		static int THISCALL hook_connect(void* dis, int a1)
		{
			RakNet::BitStream arz;
			arz.Write(((uint8_t)(220u)));
			arz.Write(((uint8_t)(6u)));
			arz.Write(((uint8_t)(2u)));
			Send(&arz, 1, 9, '\0', GetPlayerIDFromIndex(a1), false);
			arz.Reset();
			arz.Write(((uint8_t)(220u)));
			arz.Write(((uint8_t)(10u)));
			arz.Write(((uint8_t)(2u)));
			Send(&arz, 1, 9, '\0', GetPlayerIDFromIndex(a1), false);
			arz.Reset();
			arz.Write(((uint8_t)(220u)));
			arz.Write(((uint8_t)(11u)));
			arz.Write(((uint8_t)(2u)));
			Send(&arz, 1, 9, '\0', GetPlayerIDFromIndex(a1), false);
			return hkConnect->call<urmem::calling_convention::thiscall, int>(dis, a1);
		}
	};

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
		urmem::address_t addr_raknet, addr_connect;

		scan.init((urmem::address_t)addr_server);

		scan.find(pattern, mask, addr_raknet);
		scan.find(pattern_connect, mask_connect, addr_connect);

		hkRakNet = std::make_shared<urmem::hook>(addr_raknet - 7, urmem::get_func_addr(&GetRakServerInterface));
		//hkConnect = std::make_shared<urmem::hook>(addr_connect, urmem::get_func_addr(&thiscall_hooks::hook_connect));

		return true;
	}
};

#endif