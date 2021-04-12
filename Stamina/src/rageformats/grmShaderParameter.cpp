#include <rageformats/grmShaderParameter.h>

void grmShaderParameter::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}

	m_name = node->first_attribute("name")->value();

	if (strcmp("Texture", node->first_attribute("type")->value()) == 0) {
		m_type = 0;
		if (node->first_node()) {
			m_samplerTxd = node->first_node("Name")->value();
		}
	} else if (strcmp("Vector", node->first_attribute("type")->value()) == 0) {
		m_type = 1;
		m_samplerTxd = NULL;
		m_values = ParseVec4(node);
	} else if (strcmp("Array", node->first_attribute("type")->value()) == 0) {
		m_type = 2;
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
			Vector4 temp;
			temp = ParseVec4(child);
			m_array.push_back(temp);
		}
	}
}
