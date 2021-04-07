#include <rageformats/gtaDrawable.h>
#include <Stamina.h>

void gtaDrawable::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Name", child->name()) == 0) {
			m_name = child->value();
		}
		if (strcmp("BoundingSphereCenter", child->name()) == 0) {
			m_bsCenter = ParseVec3(child);
		}
		if (strcmp("BoundingSphereRadius", child->name()) == 0) {
			m_bsRadius = atof(child->first_attribute()->value());
		}
		if (strcmp("BoundingBoxMin", child->name()) == 0) {
			m_bbMin = ParseVec3(child);
		}
		if (strcmp("BoundingBoxMax", child->name()) == 0) {
			m_bbMax = ParseVec3(child);
		}
		if (strcmp("LodDistHigh", child->name()) == 0) {
			m_lodDist.x = atof(child->first_attribute()->value());
		}
		if (strcmp("LodDistMed", child->name()) == 0) {
			m_lodDist.y = atof(child->first_attribute()->value());
		}
		if (strcmp("LodDistLow", child->name()) == 0) {
			m_lodDist.z = atof(child->first_attribute()->value());
		}
		if (strcmp("LodDistVlow", child->name()) == 0) {
			m_lodDist.w = atof(child->first_attribute()->value());
		}
		if (strcmp("FlagsHigh", child->name()) == 0) {
			m_flags.x = atof(child->first_attribute()->value());
		}
		if (strcmp("FlagsMed", child->name()) == 0) {
			m_flags.y = atof(child->first_attribute()->value());
		}
		if (strcmp("FlagsLow", child->name()) == 0) {
			m_flags.z = atof(child->first_attribute()->value());
		}
		if (strcmp("FlagsVlow", child->name()) == 0) {
			m_flags.w = atof(child->first_attribute()->value());
		}
		if (strcmp("Unknown9A", child->name()) == 0) {
			m_unk = atof(child->first_attribute()->value());
		}
	}

	m_shaderGroup.Resolve(node->first_node("ShaderGroup"));
	m_models[0].Resolve(node->first_node("DrawableModelsHigh"));
	m_models[1].Resolve(node->first_node("DrawableModelsMedium"));
	m_models[2].Resolve(node->first_node("DrawableModelsLow"));
	m_models[3].Resolve(node->first_node("DrawableModelsVeryLow"));

}
