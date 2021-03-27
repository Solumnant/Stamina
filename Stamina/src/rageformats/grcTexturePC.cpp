#include <rageformats/grcTexturePC.h>
#include <Stamina.h>
void grcTexturePC::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Name", child->name()) == 0) {
			m_name = child->value();
		}
		if (strcmp("Unk32", child->name()) == 0) {
			m_unk32 = atof(child->first_attribute()->value());
		}
		if (strcmp("Usage", child->name()) == 0) {
			m_usage = child->value();
		}
		if (strcmp("UsageFlags", child->name()) == 0) {
			m_usageFlags = child->value();
		}
		if (strcmp("ExtraFlags", child->name()) == 0) {
			m_extraFlags = atof(child->first_attribute()->value());
		}
		if (strcmp("Width", child->name()) == 0) {
			m_width = atof(child->first_attribute()->value());
		}
		if (strcmp("Height", child->name()) == 0) {
			m_height = atof(child->first_attribute()->value());
		}
		if (strcmp("MipLevels", child->name()) == 0) {
			/* TODO: Check this. */
			m_levels = (char)atof(child->first_attribute()->value());
		}
		if (strcmp("Format", child->name()) == 0) {
			m_format = child->value();
		}
		if (strcmp("FileName", child->name()) == 0) {
			m_fileName = child->value();
		}
	}
}