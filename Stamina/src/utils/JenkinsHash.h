#ifndef _JOOAT_H
#define _JOOAT_H

inline unsigned int HashString(const char *string) {
	unsigned int hash = 0;

	for (; *string; ++string) {
		hash += *string;
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
}

#endif