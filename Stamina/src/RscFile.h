#ifndef _RSCFILE_H
#define _RSCFILE_H
#include <rapidxml/rapidxml_utils.hpp>

enum ResourceFileType {
	GTADRAWABLE_FILE = 0,
	PGDICTIONARY_GTADRAWABLE_FILE,
	PGDICTIONARY_PHBOUND_FILE
};

static constexpr struct ResourceMap {
	char *key;
	ResourceFileType rsc;
} RESOURCE_TABLE[] = {
   {"Drawable", GTADRAWABLE_FILE},
   {"DrawableDictionary", PGDICTIONARY_GTADRAWABLE_FILE},
   {"BoundsFile", PGDICTIONARY_PHBOUND_FILE}
};


template<typename T, ResourceFileType rscType>
class ResourceFile {
	T m_resource;
public:
	void Resolve(rapidxml::xml_node<> *root) {
		ResourceMap rscMap = RESOURCE_TABLE[rscType];
		if (strcmp(rscMap.key, root->name()) == 0) {
			m_resource.Resolve(root);
		} else {
			Stamina::Log(LEVEL_WARNING, "Unable to resolve %s, file expected %s.", rscMap.key, root->name());
		}
	}
};

#endif