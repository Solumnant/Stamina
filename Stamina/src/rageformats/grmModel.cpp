#include <rageformats/grmModel.h>

void grmModel::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}
	node = node->first_node();
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("RenderMask", child->name()) == 0) {
			m_renderMask = (char)atof(child->first_attribute()->value());
		}
		if (strcmp("Flags", child->name()) == 0) {
			m_flags = (char)atof(child->first_attribute()->value());
		}
		if (strcmp("HasSkin", child->name()) == 0) {
			m_hasSkin = (char)atof(child->first_attribute()->value());
		}
		if (strcmp("BoneIndex", child->name()) == 0) {
			m_boneIndex = (char)atof(child->first_attribute()->value());
		}
		if (strcmp("Unknown1", child->name()) == 0) {
			m_unk1 = (char)atof(child->first_attribute()->value());
		}
	}
	m_geometries.Resolve(node->first_node("Geometries"));
}