#include <core/Stamina.h>
#include <stdio.h>
#include <time/timestamp.h>


void Stamina::Init(void) {
	Log(LEVEL_LOG, "Hooked stamina-core.dll - Version %i", STAMINACORE_VERSION);
}

void Stamina::Shutdown(void) {
	Log(LEVEL_LOG, "Freed stamina-core.dll");
}

//#define NO_PRINT
void Stamina::Log(eWARNING_LEVEL level, const char *fmt, ...) {
#ifndef NO_PRINT
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
#endif

}

const char *Stamina::AsciiString(const WCHAR *str) {
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
}
