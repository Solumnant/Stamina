#include <rageformats/grmShaderArray.h>
void grmShaderArray::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		grmShaderFx temp;
		temp.Resolve(child);
		m_shaders.push_back(temp);
	}
}

//void grcTextureDictionary::Resolve(rapidxml::xml_node<> *node) {
//	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
//		grcTexturePC temp;
//		temp.Resolve(child);
//		m_textures.push_back(temp);
//	}
//}