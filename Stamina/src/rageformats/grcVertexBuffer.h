#ifndef _GRC_VERTEXBUFFER_H
#define _GRC_VERTEXBUFFER_H
#include <Xml.h>
#include <vector>
#include <rageformats/grcVertexFormat.h>


class grcVertexBuffer : IXml {
private:
	unsigned char m_vertexSize;
	unsigned short m_flags;
	unsigned int m_vertexCount;
	grcVertexFormat m_vertexFormat;
	std::vector<float> m_data;
public:
	grcVertexBuffer() {
		m_vertexSize = 0;
		m_vertexCount = 0;
	}
	void Resolve(rapidxml::xml_node<> *node);

	grcVertexFormat &GetVertexFormat(void) {
		return m_vertexFormat;
	}

	unsigned short GetStride() {
		return m_vertexSize;
	}

	unsigned int GetVertexCount() {
		return m_vertexCount;
	}

	std::vector<float> &GetData(void) {
		return m_data;
	}
};

#endif