#include <rageformats/grcVertexBuffer.h>
#include "grcVertexBuffer.h"

void grcVertexBuffer::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Flags", child->name()) == 0) {
			m_flags = (unsigned short)atof(child->first_attribute()->value());
		}
		if ((strcmp("Data", child->name()) == 0) ||
			(strcmp("Data1", child->name()) == 0) ||
			(strcmp("Data2", child->name()) == 0)) {
			m_data = child->first_node()->value();
		}
	}
	m_vertexFormat.Resolve(node->first_node("Layout"));
}
