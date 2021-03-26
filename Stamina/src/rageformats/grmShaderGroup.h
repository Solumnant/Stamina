#ifndef _GRM_SHADERGROUP_H
#define _GRM_SHADERGROUP_H
#include <Xml.h>
#include <rageformats/grcTextureDictionary.h>
#include <rageformats/grmShaderFx.h>
#include <rageformats/grmShaderArray.h>

class grmShaderGroup : IXml {
private:
	unsigned int m_unk;
	grcTextureDictionary m_txd; /* pgDictionary<grcTexturePC> */
	grmShaderArray m_shaderArr /* pgObjectArray<grmShaderFx> */;
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif