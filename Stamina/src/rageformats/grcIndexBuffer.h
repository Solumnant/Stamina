#ifndef _GRC_INDEXBUFFER_H
#define _GRC_INDEXBUFFER_H

#include <Xml.h>
#include <vector>

class grcIndexBuffer : IXml {
private:
	std::vector<unsigned short> m_data;
	unsigned int m_indexCount;
public:
	grcIndexBuffer() {
		m_indexCount = 0;
	}
	void Resolve(rapidxml::xml_node<> *node);

	std::vector<unsigned short> &GetData(void) {
		return m_data;
	}

	unsigned int GetIndexCount(void) {
		return m_indexCount;
	}
};

#endif