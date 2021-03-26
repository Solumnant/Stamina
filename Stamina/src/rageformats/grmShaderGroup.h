#ifndef _GRM_SHADERGROUP_H
#define _GRM_SHADERGROUP_H
#include <Xml.h>
#include <rageformats/grcTextureDictionary.h>

class grmShaderGroup : IXml {
private:
	unsigned int m_unk;
	grcTextureDictionary m_txd; /* pgDictionary<grcTexturePC> */
	//grmShaderFx m_shaders
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif