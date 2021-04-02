#include <Stamina.h>
#include <stdio.h>
#include <time/timestamp.h>




//static constexpr int STAMINACORE_VERSION_MAJOR = 1;
//static constexpr int STAMINACORE_VERSION_MINOR = 0;
//static constexpr int STAMINACORE_VERSION = STAMINACORE_VERSION_MAJOR * 100 + STAMINACORE_VERSION_MINOR;

void Stamina::Init(void) {
#ifdef DEBUG
	if (!AllocConsole()) {
		MessageBox(NULL, "Failed To Open Console", NULL, MB_OK);
		return;
	}
	//const char *output = "stamina-output.log.txt";
	FILE *file;
	freopen_s(&file, "CONOUT$", "w", stdout);
	freopen_s(&file, "CONIN$", "r", stdin);

	//freopen_s(&file, output, "w", stdout);
#endif
	Log(LEVEL_LOG, "Hooked stamina-core.dll");
}



void Stamina::Shutdown(void) {
	Log(LEVEL_LOG, "Freed stamina-core.dll");
#ifdef DEBUG
	FreeConsole();
#endif
}


void Stamina::Log(eWARNING_LEVEL level, const char *fmt, ...) {
	va_list		argptr;
	char		msg[MAX_PRINT_MSG_SIZE];
	char		*current_time = timestamp();
	va_start(argptr, fmt);
	vsnprintf(msg, sizeof(msg), fmt, argptr);
	va_end(argptr);
	msg[sizeof(msg) - 1] = 0;
	switch (level) {
		case LEVEL_LOG:
			printf("[%s] [STAMINA-CORE] [LOG]:" " " "%s\n", current_time, msg);
			break;
		case LEVEL_WARNING:
			printf("[%s] [STAMINA-CORE] [WRN]:" " " "%s\n", current_time, msg);
			break;
		case LEVEL_ERROR:
			printf("[%s] [STAMINA-CORE] [ERR]:" " " "%s\n", current_time, msg);
			::MessageBox(0, msg, 0, 0);
			break;
		default:
			printf("[%s] [STAMINA-CORE] [PRT]:" " " "%s\n", current_time, msg);
			break;
	}

}

const char *Stamina::AsciiString(const WCHAR *str) {
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
}
