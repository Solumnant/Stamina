#ifndef _STAMINA_COMMON_H
#define _STAMINA_COMMON_H
#include <wtypes.h>

#define	MAX_PRINT_MSG_SIZE	4096

static enum eWARNING_LEVEL {
	LEVEL_LOG = 0,
	LEVEL_WARNING = 1,
	LEVEL_ERROR = 2,
};

class Stamina {
public:
	static void Init(void);
	static void Shutdown(void);
	static void Log(eWARNING_LEVEL level, const char *fmt, ...);
	static const char *AsciiString(const TCHAR *str);
	static const TCHAR *MaxString(const char *str);
};

#endif