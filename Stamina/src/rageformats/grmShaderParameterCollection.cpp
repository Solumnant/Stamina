#include <rageformats/grmShaderParameterCollection.h>
#include <Stamina.h>
void grmShaderParameterCollection::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		grmShaderParameter temp;
		temp.Resolve(child);
		m_parameters.push_back(temp);
	}
}