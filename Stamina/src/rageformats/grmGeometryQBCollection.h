//grmGeometryQB
#ifndef _GRM_GEOMETRY_QB_COLLECTION_H
#define _GRM_GEOMETRY_QB_COLLECTION_H
#include <rageformats/grmGeometryQB.h>
#include <Xml.h>
#include <vector>
class grmGeometryQBCollection : IXml {
private:
	std::vector<grmGeometryQB> m_geometries;
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif