#include <rageformats/grcVertexBuffer.h>
#include "grcVertexBuffer.h"

void grcVertexBuffer::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}

	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Flags", child->name()) == 0) {
			m_flags = (unsigned short)atof(child->first_attribute()->value());
		}

		if ((strcmp("Data", child->name()) == 0) ||
			(strcmp("Data1", child->name()) == 0) ||
			(strcmp("Data2", child->name()) == 0)) {
			void *pData = child->first_node()->value();

			char *value = strtok((char*)pData, " \r\n");
			while (value) {
				m_data.push_back(atof(value));
				value = strtok(NULL, " \r\n");
			}
		}
	}

	m_vertexFormat.Resolve(node->first_node("Layout"));

	for (int k = 0; k < 16; k++) {
		if (m_vertexFormat.GetMask() & (1 << k)) {
			m_vertexFormat.GetComponentCountOffset((int&)m_vertexSize, k);
		}
	}

	m_vertexCount = m_data.size() / m_vertexSize;
}
