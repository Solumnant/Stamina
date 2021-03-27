#include "grmGeometryQBCollection.h"
#include <rageformats/grmGeometryQBCollection.h>

void grmGeometryQBCollection::Resolve(rapidxml::xml_node<> *node) {
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		grmGeometryQB temp;
		temp.Resolve(child);
		m_geometries.push_back(temp);
	}
}
