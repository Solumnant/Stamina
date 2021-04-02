#ifndef _STAMINAMAX_H
#define _STAMINAMAX_H
#define	MAX_PRINT_MSG_SIZE	4096
#include <wtypes.h>

static constexpr int STAMINAMAX_VERSION_MAJOR = 1;
static constexpr int STAMINAMAX_VERSION_MINOR = 0;
static constexpr int STAMINAMAX_VERSION = STAMINAMAX_VERSION_MAJOR * 100 + STAMINAMAX_VERSION_MINOR;

namespace Max {
static enum eWARNING_LEVEL {
	LEVEL_LOG = 0,
	LEVEL_WARNING = 1,
	LEVEL_ERROR = 2,
};
}

class StaminaMax {
public:
	static void Init(void);
	static void Shutdown(void);
	static void Log(Max::eWARNING_LEVEL level, const char *fmt, ...);
	static const char *AsciiString(const TCHAR *str);
	static const TCHAR *MaxString(const char *str);
};



#endif
