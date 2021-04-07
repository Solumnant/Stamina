#ifndef _GRM_SHADERGROUP_H
#define _GRM_SHADERGROUP_H
#include <Xml.h>

#include <rageformats/grmShaderFx.h>
#include <rageformats/grcTexturePC.h>
#include <rageformats/CCollection.h>

class grmShaderGroup : IXml {
private:
	unsigned int m_unk;
	CCollection<grcTexturePC> m_txd;
	CCollection<grmShaderFx> m_shaderArr;
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif