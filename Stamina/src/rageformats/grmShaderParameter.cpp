#include <rageformats/grmShaderParameter.h>
#include <Stamina.h>

void grmShaderParameter::Resolve(rapidxml::xml_node<> *node) {
	m_name = node->first_attribute("name")->value();
	m_type = strcmp("Texture", (node->first_attribute("type")->value())) ? (char)1 : (char)0;

	if ((int)m_type == 0) {
		m_samplerTxd = node->first_node()->value();
	} else if ((int)m_type == 1) {
		m_samplerTxd = NULL;
		m_values = ParseVec4(node);
	}
}
