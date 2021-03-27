#include <rageformats/grcTextureDictionary.h>
#include <Stamina.h>
#include <Xml.h>
void grcTextureDictionary::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		grcTexturePC temp;
		temp.Resolve(child);
		m_textures.push_back(temp);
	}
}