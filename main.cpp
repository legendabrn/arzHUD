#include <pawn/amx/amx.h>
#include <pawn/plugincommon.h>
#include <iterator>

#include <raknet/bitstream.h>
#include <raknet/networktypes.h>

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

int benz_arz_hueta(int no_format)
{
	switch (no_format)
	{
	case 0:
		return 13000;
	case 1:
		return 16200;
	case 2:
		return 16400;
	case 3:
		return 16450;
	case 4:
		return 16500;
	case 5:
		return 16550;
	case 6:
		return 16570;
	case 7:
		return 16600;
	case 8:
		return 16630;
	case 9:
		return 16660;
	case 10:
		return 16670;
	case 11:
		return 16680;
	case 12:
		return 16700;
	case 13:
		return 16720;
	case 14:
		return 16740;
	case 15:
		return 16750;
	case 16:
		return 16760;
	case 17:
		return 16776;
	case 18:
		return 16780;
	case 19:
		return 16790;
	case 20:
		return 16800;
	case 21:
		return 16810;
	case 22:
		return 16815;
	case 23:
		return 16820;
	case 24:
		return 16830;
	case 25:
		return 16840;
	case 26:
		return 16845;
	case 27:
		return 16855;
	case 28:
		return 16860;
	case 29:
		return 16870;
	case 30:
		return 16880;
	case 31:
		return 16885;
	case 32:
		return 16895;
	case 33:
		return 16900;
	case 34:
		return 16905;
	case 35:
		return 16907;
	case 36:
		return 16910;
	case 37:
		return 16915;
	case 38:
		return 16920;
	case 39:
		return 16925;
	case 40:
		return 16926;
	case 41:
		return 16930;
	case 42:
		return 16935;
	case 43:
		return 16940;
	case 44:
		return 16945;
	case 45:
		return 16947;
	case 46:
		return 16950;
	case 47:
		return 16955;
	case 48:
		return 16960;
	case 49:
		return 16965;
	case 50:
		return 16967;
	case 51:
		return 16970;
	case 52:
		return 16975;
	case 53:
		return 16980;
	case 54:
		return 16985;
	case 55:
		return 16987;
	case 56:
		return 16990;
	case 57:
		return 16995;
	case 58:
		return 17000;
	case 59:
		return 17005;
	case 60:
		return 17007;
	case 61:
		return 17010;
	case 62:
		return 17015;
	case 63:
		return 17020;
	case 64:
		return 17023;
	case 65:
		return 17025;
	case 66:
		return 17027;
	case 67:
		return 17030;
	case 68:
		return 17031;
	case 69:
		return 17033;
	case 70:
		return 17035;
	case 71:
		return 17037;
	case 72:
		return 17039;
	case 73:
		return 17041;
	case 74:
		return 17043;
	case 75:
		return 17045;
	case 76:
		return 17047;
	case 77:
		return 17049;
	case 78:
		return 17051;
	case 79:
		return 17953;
	case 80:
		return 17055;
	case 81:
		return 17057;
	case 82:
		return 17059;
	case 83:
		return 17061;
	case 84:
		return 17063;
	case 85:
		return 17065;
	case 86:
		return 17067;
	case 87:
		return 17089;
	case 88:
		return 17071;
	case 89:
		return 17073;
	case 90:
		return 17075;
	case 91:
		return 17077;
	case 92:
		return 17079;
	case 93:
		return 17081;
	case 94:
		return 17083;
	case 95:
		return 17085;
	case 96:
		return 17087;
	case 97:
		return 17089;
	case 98:
		return 17091;
	case 99:
		return 17093;
	case 100:
		return 17095;
	default:
		return 0;
	}
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
		arz.Write(((uint16_t)(benz_arz_hueta(params[arg_benz]))));
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