#if !defined(_FUNCTIONS_HPP_) && (defined(COD2_VERSION) || defined(COD_VERSION))
#define _FUNCTIONS_HPP_

/* MAKE FUNCTIONS STATIC, SO THEY CAN BE IN EVERY FILE */

// CoD2 1.2 = 80601F2
static int trap_Argc()
{
	#if COD2_VERSION == COD2_VERSION_1_0
		return *(int *)0x0819BE80;
	#elif COD2_VERSION == COD2_VERSION_1_2
		return *(int *)0x0819E080;
	#elif COD2_VERSION == COD2_VERSION_1_3
		return *(int *)0x0819F100;
	#else
		#warning trap_Argc() return *(int *)NULL;
		return *(int *)NULL;
	#endif
}

typedef int (*trap_Argv_t)(unsigned int param, char *buf, int bufLen);
#if COD2_VERSION == COD2_VERSION_1_0
	static trap_Argv_t trap_Argv = (trap_Argv_t)0x08060074;
#elif COD2_VERSION == COD2_VERSION_1_2
	static trap_Argv_t trap_Argv = (trap_Argv_t)0x08060280;
#elif COD2_VERSION == COD2_VERSION_1_3
	static trap_Argv_t trap_Argv = (trap_Argv_t)0x08060278;
#else
	#warning static trap_Argv_t trap_Argv = (trap_Argv_t)NULL;
	static trap_Argv_t trap_Argv = (trap_Argv_t)NULL;
#endif


typedef int (*ClientCommand_t)(int clientNum);
#if COD2_VERSION == COD2_VERSION_1_0
	static ClientCommand_t ClientCommand = (ClientCommand_t)0x080FE998; // search 'say_team' and see code xref function
	static int hook_ClientCommand_call = 0x0808F281;
#elif COD2_VERSION == COD2_VERSION_1_2
	static ClientCommand_t ClientCommand = (ClientCommand_t)0x08100D1E;
	static int hook_ClientCommand_call = 0x08090B0C;
#elif COD2_VERSION == COD2_VERSION_1_3
	static ClientCommand_t ClientCommand = (ClientCommand_t)0x08100E62;
	static int hook_ClientCommand_call = 0x08090BA0;
#else
	#warning static ClientCommand_t ClientCommand = (ClientCommand_t)NULL;
	#warning static int hook_ClientCommand_call = NULL;
	static ClientCommand_t ClientCommand = (ClientCommand_t)NULL;
	static int hook_ClientCommand_call = (int)NULL;
#endif

typedef int (*Cvar_VariableValue_t)(const char *var_name);
#if COD2_VERSION == COD2_VERSION_1_0
	static Cvar_VariableValue_t CvarVariableValue = (Cvar_VariableValue_t)0x080B0BB6;
#elif COD2_VERSION == COD2_VERSION_1_2
	static Cvar_VariableValue_t CvarVariableValue = (Cvar_VariableValue_t)0x080B2E66;
#elif COD2_VERSION == COD2_VERSION_1_3
	static Cvar_VariableValue_t CvarVariableValue = (Cvar_VariableValue_t)0x080B2FAA;
#else
	#warning static Cvar_VariableValue_t CvarVariableValue = NULL;
	static Cvar_VariableValue_t CvarVariableValue = (Cvar_VariableValue_t)NULL;
#endif

#if COD2_VERSION == COD2_VERSION_1_0
	static int hook_ServerCommand_call = 0x080941F2;
	static int hook_ConnectionlessPacket = 0x08093F1E;
	static int fsrestrict_ServerCommand = 0x0808C8F2;
#elif COD2_VERSION == COD2_VERSION_1_2
	static int hook_ServerCommand_call = 0x0809606C;
	static int hook_ConnectionlessPacket = 0x08095894;
	static int fsrestrict_ServerCommand = 0x0808DAAF;
#elif COD2_VERSION == COD2_VERSION_1_3
	static int hook_ServerCommand_call = 0x08096126;
	static int hook_ConnectionlessPacket = 0x0809594E;
	static int fsrestrict_ServerCommand = 0x0808DB6F;
#else
	#warning static int hook_ServerCommand_call = NULL;
	#warning static int hook_ConnectionlessPacket = NULL;
	#warning static int fsrestrict_ServerCommand = NULL;
	static int hook_ServerCommand_call = (int)NULL;
	static int hook_ConnectionlessPacket = (int)NULL;
	static int fsrestrict_ServerCommand = (int)NULL;
#endif

typedef short (*codscript_call_callback_entity_t)(int self, int callback, int params);
#if COD2_VERSION == COD2_VERSION_1_0
	static codscript_call_callback_entity_t codscript_call_callback_entity = (codscript_call_callback_entity_t)0x08118DF4; // search 'badMOD'

#elif COD2_VERSION == COD2_VERSION_1_2
	static codscript_call_callback_entity_t codscript_call_callback_entity = (codscript_call_callback_entity_t)0x0811B128;
#elif COD2_VERSION == COD2_VERSION_1_3
	static codscript_call_callback_entity_t codscript_call_callback_entity = (codscript_call_callback_entity_t)0x0811B284;
#else
	#warning static codscript_call_callback_entity_t codscript_call_callback_entity = (codscript_call_callback_entity_t)NULL;
	static codscript_call_callback_entity_t codscript_call_callback_entity = (codscript_call_callback_entity_t)NULL;
#endif

typedef int (*codscript_callback_finish_t)(short callback_handle);
#if COD2_VERSION == COD2_VERSION_1_0
	static codscript_callback_finish_t codscript_callback_finish = (codscript_callback_finish_t)0x08083B8E;
#elif COD2_VERSION == COD2_VERSION_1_2
	static codscript_callback_finish_t codscript_callback_finish = (codscript_callback_finish_t)0x0808410A;
#elif COD2_VERSION == COD2_VERSION_1_3
	static codscript_callback_finish_t codscript_callback_finish = (codscript_callback_finish_t)0x080841D6;
#else
	#warning static codscript_callback_finish_t codscript_callback_finish = (codscript_callback_finish_t)NULL;
	static codscript_callback_finish_t codscript_callback_finish = (codscript_callback_finish_t)NULL;
#endif

#endif
