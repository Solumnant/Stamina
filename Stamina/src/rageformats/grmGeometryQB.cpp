#include <rageformats/grmGeometryQB.h>

void grmGeometryQB::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("ShaderIndex", child->name()) == 0) {
			m_shaderidx = (unsigned short) atof(child->first_attribute()->value());
		}
		if (strcmp("BoundingBoxMin", child->name()) == 0) {
			m_bbMin = ParseVec4(child);
		}
		if (strcmp("BoundingBoxMax", child->name()) == 0) {
			m_bbMax = ParseVec4(child);
		}
	}
	m_vertexBuffer.Resolve(node->first_node("VertexBuffer"));
	m_indexBuffer.Resolve(node->first_node("IndexBuffer"));
}
