#ifndef _STAMINA_PRIMITIVES_H
#define _STAMINA_PRIMITIVES_H

#include <stdlib.h>

inline float ToFloat(const char *string) {
	Stamina::Log(LEVEL_LOG, "Calling ToFloat");
	return atof(string);
}

inline int ToInt(const char *string) {
	return atoi(string);
}


#endif