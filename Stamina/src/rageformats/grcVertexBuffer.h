#ifndef _GRC_VERTEXBUFFER_H
#define _GRC_VERTEXBUFFER_H
#include <Xml.h>
#include <vector>
#include <rageformats/grcVertexFormat.h>


class grcVertexBuffer : IXml {
private:
	unsigned short m_flags;
	grcVertexFormat m_vertexFormat;
	char *m_data;
public:
	void Resolve(rapidxml::xml_node<> *node);
};

#endif