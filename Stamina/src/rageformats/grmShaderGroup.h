#ifndef _GRM_SHADERGROUP_H
#define _GRM_SHADERGROUP_H
#include <Xml.h>

class grmShaderGroup : IXml {
private:
	unsigned int m_unk;
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif