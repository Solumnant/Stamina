#ifndef _GRM_MODEL_H
#define _GRM_MODEL_H

#include <Xml.h>
#include <rageformats/grmGeometryQBCollection.h>

class grmModel : IXml {
private:
	char m_renderMask;
	char m_flags;
	char m_hasSkin;
	char m_boneIndex;
	char m_unk1;
	grmGeometryQBCollection m_geometries;
public:
	void Resolve(rapidxml::xml_node<> *root);
};
#endif