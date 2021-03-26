#include <Stamina.h>
#include <stdio.h>

void Stamina::Log(eWARNING_LEVEL level, const char *fmt, ...) {
	va_list		argptr;
	char		msg[MAX_PRINT_MSG_SIZE];

	va_start(argptr, fmt);
	vsnprintf(msg, sizeof(msg), fmt, argptr);
	va_end(argptr);
	msg[sizeof(msg) - 1] = 0;
	switch (level) {
		case LEVEL_LOG:
			printf("[LOG]:" " " "%s\n", msg);
			break;
		case LEVEL_WARNING:
			printf("[WARNING]:" " " "%s\n", msg);
			break;
		case LEVEL_ERROR:
			printf("[ERROR]:" " " "%s\n", msg);
			::MessageBox(0, MaxString(msg), 0, 0);
			break;
		default:
			printf("[PRINT]:" " " "%s\n", msg);
			break;
	}

}

const char *Stamina::AsciiString(const TCHAR *str) {
#ifdef UNICODE
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}

const TCHAR *Stamina::MaxString(const char *str) {
#ifdef UNICODE
	static TCHAR to_return[MAX_PATH];
	mbstowcs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}