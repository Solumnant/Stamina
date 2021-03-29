#ifndef _GRC_VERTEXBUFFER_H
#define _GRC_VERTEXBUFFER_H
#include <Xml.h>
#include <vector>
#include <rageformats/grcVertexFormat.h>


class grcVertexBuffer : IXml {
private:
	unsigned short m_flags;
	unsigned char m_vertexSize;
	grcVertexFormat m_vertexFormat;
	char *m_data;
public:
	void Resolve(rapidxml::xml_node<> *node);

	grcVertexFormat &GetVertexFormat(void) {
		return m_vertexFormat;
	}

	unsigned int GetStride() {
		return m_vertexSize;
	}

	char *GetData(void) {
		return m_data;
	}
};

#endif