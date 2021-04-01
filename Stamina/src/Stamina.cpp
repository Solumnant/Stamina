#include <Stamina.h>
#include <stdio.h>



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

	va_start(argptr, fmt);
	vsnprintf(msg, sizeof(msg), fmt, argptr);
	va_end(argptr);
	msg[sizeof(msg) - 1] = 0;
	switch (level) {
		case LEVEL_LOG:
			printf("[STAMINA-CORE][LOG]:" " " "%s\n", msg);
			break;
		case LEVEL_WARNING:
			printf("[STAMINA-CORE][WARNING]:" " " "%s\n", msg);
			break;
		case LEVEL_ERROR:
			printf("[STAMINA-CORE][ERROR]:" " " "%s\n", msg);
			::MessageBox(0, msg, 0, 0);
			break;
		default:
			printf("[STAMINA-CORE][PRINT]:" " " "%s\n", msg);
			break;
	}

}

const char *Stamina::AsciiString(const WCHAR *str) {
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
}
