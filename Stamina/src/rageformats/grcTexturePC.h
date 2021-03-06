#ifndef _GRCTEXTUREPC_H
#define _GRCTEXTUREPC_H

#include <xml/Xml.h>

class grcTexturePC : IXml {
private:
	const char *m_name;
	unsigned int m_unk32;
	const char *m_usage;
	const char *m_usageFlags;
	unsigned int m_extraFlags;
	unsigned short m_width;
	unsigned short m_height;
	char m_levels;
	const char *m_format;
	const char *m_fileName;
public:
	void Resolve(rapidxml::xml_node<> *node);
};

#endif