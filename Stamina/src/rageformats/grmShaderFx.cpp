#include <rageformats/grmShaderFx.h>
#include <utils/JenkinsHash.h>

void grmShaderFx::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}

	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Name", child->name()) == 0) {
			m_name = HashString(child->value());
		}
		if (strcmp("FileName", child->name()) == 0) {
			m_fileName = HashString(child->value());
		}
		if (strcmp("RenderBucket", child->name()) == 0) {
			m_renderBucket = (char)atof(child->first_attribute()->value());
		}
		
	}

	m_parameters.Resolve(node->first_node("Parameters"));
}