#include <pawn/amx/amx.h>
#include <pawn/plugincommon.h>
#include <iterator>
#include <vector>

#include <raknet/bitstream.h>
#include <raknet/networktypes.h>

std::vector<int> fuel = { 0, 13000, 16200, 16400, 16450, 16500, 16550, 16570, 16600, 16630, 16660, 16670, 16680, 16700, 16720, 16740, 16750, 16760, 16776, 16780, 16790, 16800, 16810, 16815, 16820, 16830, 16840, 16845, 16855, 16860, 16870, 16880, 16885, 16895, 16900, 16905, 16907, 16910, 16915, 16920, 16925, 16926, 16930, 16935, 16940, 16945, 16947, 16950, 16955, 16960, 16965, 16967, 16970, 16975, 16980, 16985, 16987, 16990, 16995, 17000, 17005, 17007, 17010, 17015, 17020, 17023, 17025, 17027, 17030, 17031, 17033, 17035, 17037, 17039, 17041, 17043, 17045, 17047, 17049, 17051, 17953, 17055, 17057, 17059, 17061, 17063, 17065, 17067, 17089, 17071, 17073, 17075, 17077, 17079, 17081, 17083, 17085, 17087, 17089, 17091, 17093, 17095 };
  
typedef void(*logprintf_t)(const char* format, ...);
logprintf_t logprintf;

extern void *pAMXFunctions;
void **ppPluginData;

#include "net.h"

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	ppPluginData = ppData;
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)(ppData[PLUGIN_DATA_LOGPRINTF]);

	if (!net::init(ppData[PLUGIN_DATA_LOGPRINTF]))
		logprintf((" * arz could not initialize net module"));
	else
		logprintf((" * arz 1.2 patched samp03svr successfully."));
	return true;
}

bool CheckNumberOfArguments(AMX* amx, const cell* params, int num_expected)
{
	if (((int)params[0] / (int)sizeof(cell)) >= num_expected)
		return true;

	amx_RaiseError(amx, AMX_ERR_PARAMS);
	return false;
}

static cell AMX_NATIVE_CALL n_arz_Eat(AMX* amx, cell* params)
{
	enum
	{
		args_size,
		arg_playerid,
		arg_eat,
		__dummy_elem_, num_args_expected = __dummy_elem_ - 1
	};

	if (!CheckNumberOfArguments(amx, params, num_args_expected))
		return 0;

	if (params[arg_eat] <= 100)
	{
		RakNet::BitStream arz;
		arz.Write(((uint8_t)(220u)));
		arz.Write(((uint8_t)(4u)));
		arz.Write(((uint8_t)(params[arg_eat])));
		net::Send(&arz, 1, 9, '\0', net::GetPlayerIDFromIndex(params[arg_playerid]), false);
	}

	return 1;
}

static cell AMX_NATIVE_CALL n_arz_Hud(AMX* amx, cell* params)
{
	enum
	{
		args_size,
		arg_playerid,
		arg_style,
		__dummy_elem_, num_args_expected = __dummy_elem_ - 1
	};

	if (!CheckNumberOfArguments(amx, params, num_args_expected))
		return 0;

	if (params[arg_style] <= 2)
	{
		RakNet::BitStream arz;
		arz.Write(((uint8_t)(220u)));
		arz.Write(((uint8_t)(10u)));
		arz.Write(((uint8_t)(params[arg_style])));
		net::Send(&arz, 1, 9, '\0', net::GetPlayerIDFromIndex(params[arg_playerid]), false);
	}
	return 1;
}

static cell AMX_NATIVE_CALL n_arz_Radar(AMX* amx, cell* params)
{
	enum
	{
		args_size,
		arg_playerid,
		arg_style,
		__dummy_elem_, num_args_expected = __dummy_elem_ - 1
	};

	if (!CheckNumberOfArguments(amx, params, num_args_expected))
		return 0;

	if (params[arg_style] <= 2)
	{
		RakNet::BitStream arz;
		arz.Write(((uint8_t)(220u)));
		arz.Write(((uint8_t)(11u)));
		arz.Write(((uint8_t)(params[arg_style])));
		net::Send(&arz, 1, 9, '\0', net::GetPlayerIDFromIndex(params[arg_playerid]), false);
	}

	return 1;
}

static cell AMX_NATIVE_CALL n_arz_Speed(AMX* amx, cell* params)
{
	enum
	{
		args_size,
		arg_playerid,
		arg_style,
		__dummy_elem_, num_args_expected = __dummy_elem_ - 1
	};

	if (!CheckNumberOfArguments(amx, params, num_args_expected))
		return 0;

	if (params[arg_style] <= 2)
	{
		RakNet::BitStream arz;
		arz.Write(((uint8_t)(220u)));
		arz.Write(((uint8_t)(6u)));
		arz.Write(((uint8_t)(params[arg_style])));
		net::Send(&arz, 1, 9, '\0', net::GetPlayerIDFromIndex(params[arg_playerid]), false);
	}
	return 1;
}

static cell AMX_NATIVE_CALL n_arz_Benz(AMX* amx, cell* params)
{

	enum
	{
		args_size,
		arg_playerid,
		arg_benz,
		__dummy_elem_, num_args_expected = __dummy_elem_ - 1
	};

	if (!CheckNumberOfArguments(amx, params, num_args_expected))
		return 0;

	if (params[arg_benz] <= 100)
	{
		RakNet::BitStream arz;
		arz.Write(((uint8_t)(220u)));
		arz.Write(((uint8_t)(9u)));
		arz.Write(((uint8_t)(0u)));
		arz.Write(((uint8_t)(0u)));
		arz.Write(((uint16_t)(fuel(params[arg_benz]))));
		net::Send(&arz, 1, 9, '\0', net::GetPlayerIDFromIndex(params[arg_playerid]), false);
	}
	return 1;
}

static AMX_NATIVE_INFO plugin_natives[] =
{
	{ "arz_Hud", n_arz_Hud },
	{ "arz_Radar", n_arz_Radar },
	{ "arz_Speed", n_arz_Speed },
	{ "arz_Eat", n_arz_Eat },
	{ "arz_Benz", n_arz_Benz },
};

PLUGIN_EXPORT void PLUGIN_CALL Unload() {}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	amx_Register(amx, plugin_natives, (int)arraysize(plugin_natives));
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) 
{
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}
