#ifndef _GRC_INDEXBUFFER_H
#define _GRC_INDEXBUFFER_H
#include <Xml.h>
#include <vector>
class grcIndexBuffer : IXml {
private:
	char *m_data;
public:
	void Resolve(rapidxml::xml_node<> *node);
};

#endif