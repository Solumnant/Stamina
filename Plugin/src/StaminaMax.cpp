#include <StaminaMax.h>
#include <stdio.h>

void StaminaMax::Init(void) {
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
	Log(Max::LEVEL_LOG, "Hooked stamina-max.dll");
}



void StaminaMax::Shutdown(void) {
	Log(Max::LEVEL_LOG, "Freed stamina-max.dll");
#ifdef DEBUG
	FreeConsole();
#endif
}


void StaminaMax::Log(Max::eWARNING_LEVEL level, const char *fmt, ...) {
	va_list		argptr;
	char		msg[MAX_PRINT_MSG_SIZE];

	va_start(argptr, fmt);
	vsnprintf(msg, sizeof(msg), fmt, argptr);
	va_end(argptr);
	msg[sizeof(msg) - 1] = 0;
	switch (level) {
		case Max::LEVEL_LOG:
			printf("[STAMINA-MAX][LOG]:" " " "%s\n", msg);
			break;
		case Max::LEVEL_WARNING:
			printf("[STAMINA-MAX][WARNING]:" " " "%s\n", msg);
			break;
		case Max::LEVEL_ERROR:
			printf("[STAMINA-MAX][ERROR]:" " " "%s\n", msg);
			::MessageBox(0, MaxString(msg), 0, 0);
			break;
		default:
			printf("[STAMINA-MAX][PRINT]:" " " "%s\n", msg);
			break;
	}
}

const char *StaminaMax::AsciiString(const TCHAR *str) {
#ifdef UNICODE
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}


const TCHAR *StaminaMax::MaxString(const char *str) {
#ifdef UNICODE
	static TCHAR to_return[MAX_PATH];
	mbstowcs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}