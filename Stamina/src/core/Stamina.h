#ifndef _STAMINA_CORE_H
#define _STAMINA_CORE_H
#include <wtypes.h>

#define	MAX_PRINT_MSG_SIZE	4096

static enum eWARNING_LEVEL {
	LEVEL_LOG = 0,
	LEVEL_WARNING = 1,
	LEVEL_ERROR = 2,
};

static constexpr int STAMINACORE_VERSION_MAJOR = 1;
static constexpr int STAMINACORE_VERSION_MINOR = 0;
static constexpr int STAMINACORE_VERSION = STAMINACORE_VERSION_MAJOR * 100 + STAMINACORE_VERSION_MINOR;

class Stamina {
public:
	static void Init(void);
	static void Shutdown(void);
	static void Log(eWARNING_LEVEL level, const char *fmt, ...);
	static const char *AsciiString(const WCHAR *str);
};

#endif