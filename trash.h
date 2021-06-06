#pragma once

#ifdef THISCALL
#undef THISCALL
#endif

#ifdef _WIN32
#define THISCALL __thiscall
#else
#define THISCALL
#endif

constexpr char const
#ifdef _WIN32
* pattern = "\x64\xA1\x00\x00" \
"\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x51" \
"\x68\x18\x0E\x00\x00\xE8\xFF\xFF\xFF\xFF\x83" \
"\xC4\x04\x89\x04\x24\x85\xC0\xC7\x44\x24\xFF" \
"\x00\x00\x00\x00\x74\x16",
* mask = "xxxxxxxxxxxxxxxx????x????xxxxxxxxxxx?xxxxxx",

* pattern_connect = "\x83\xEC\x08\x56\x8B\xF1\x8A\x46\x68\x84\xC0\x75\x09\x33\xC0\x5E",
* mask_connect = "xxxxxxxxxxxxxxxx";
#else
* pattern = "\x04\x24\xFF\xFF" \
"\xFF\xFF\x89\x75\xFF\x89\x5D\xFF\xE8\xFF\xFF" \
"\xFF\xFF\x89\x04\x24\x89\xC6\xE8\xFF\xFF\xFF" \
"\xFF\x89\xF0\x8B\x5D\xFF\x8B\x75\xFF\x89\xEC" \
"\x5D\xC3",
* mask = "xx????xx?xx?x????xxxxxx????xxxx?xx?xxxx",

* pattern_connect = "\x55\x31\xC0\x89\xE5\x53\x83\xEC\x14\x8B\x5D\x08\x80\x7B\x68\x00\x75\x06\x83\xC4\x14\x5B\x5D\xC3\xC7\x45\xF4\x00\x00\x00\x00\x8D\x45\xF8\x89\x44\x24\x08\xB8\x70\x94\x15\x08\x89\x44\x24\x04",
* mask_connect = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

#endif

std::shared_ptr<urmem::hook> hkRakNet;
std::shared_ptr<urmem::hook> hkConnect;

namespace Addresses 
{
#ifdef _WIN32
	enum RakServerOffset 
	{
		SEND = 7,
		GET_PLAYER_ID_FROM_INDEX = 58
	};
#else
	enum RakServerOffset 
	{
		SEND = 9,
		GET_PLAYER_ID_FROM_INDEX = 59
	};
#endif

	urmem::address_t
		PTR_RAKSERVER{},
		FUNC_RAKSERVER__SEND{},
		FUNC_RAKSERVER__GET_PLAYER_ID_FROM_INDEX{};

	void InitRakServer(urmem::address_t rakserver, urmem::address_t* vmt) 
	{
		PTR_RAKSERVER = rakserver;

		FUNC_RAKSERVER__SEND = vmt[RakServerOffset::SEND];
		FUNC_RAKSERVER__GET_PLAYER_ID_FROM_INDEX = vmt[RakServerOffset::GET_PLAYER_ID_FROM_INDEX];
	}
};