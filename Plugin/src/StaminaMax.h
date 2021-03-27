#ifndef _STAMINAMAX_H
#define _STAMINAMAX_H
static constexpr int STAMINAMAX_VERSION_MAJOR = 1;
static constexpr int STAMINAMAX_VERSION_MINOR = 0;
static constexpr int STAMINAMAX_VERSION =
STAMINAMAX_VERSION_MAJOR * 100 + STAMINAMAX_VERSION_MINOR;

namespace StaminaMax {
const char *AsciiString(const TCHAR *str) {
#ifdef UNICODE
	static char to_return[MAX_PATH];
	wcstombs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}

const TCHAR *MaxString(const char *str) {
#ifdef UNICODE
	static TCHAR to_return[MAX_PATH];
	mbstowcs(to_return, str, MAX_PATH);
	return to_return;
#else
	return str;
#endif
}
}
#endif
