#include "grmShaderGroup.h"

void grmShaderGroup::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Unknown30", child->name()) == 0) {
			m_unk = atof(child->first_attribute()->value());
		}
	}
}
