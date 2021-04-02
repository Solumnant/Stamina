#include <StaminaMax.h>
#include <stdio.h>
#include <time/timestamp.h>

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
	char		*current_time = timestamp();
	va_start(argptr, fmt);
	vsnprintf(msg, sizeof(msg), fmt, argptr);
	va_end(argptr);
	msg[sizeof(msg) - 1] = 0;
	switch (level) {
		case Max::LEVEL_LOG:
			printf("[%s] [STAMINA-MAX ] [LOG]:" " " "%s\n", current_time, msg);
			break;
		case Max::LEVEL_WARNING:
			printf("[%s] [STAMINA-MAX ] [WRN]:" " " "%s\n", current_time, msg);
			break;
		case Max::LEVEL_ERROR:
			printf("[%s] [STAMINA-MAX ] [ERR]:" " " "%s\n", current_time, msg);
			::MessageBox(0, MaxString(msg), 0, 0);
			break;
		default:
			printf("[%s] [STAMINA-MAX ] [PRT]:" " " "%s\n", current_time, msg);
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