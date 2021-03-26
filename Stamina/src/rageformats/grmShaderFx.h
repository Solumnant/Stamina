#ifndef _GRM_SHADER_FX_H
#define _GRM_SHADER_FX_H

#include <Xml.h>
#include <rageformats/grmShaderParameterCollection.h>
class grmShaderFx : IXml {
private:
	unsigned int m_name;
	unsigned int m_fileName;
	char m_renderBucket;
	grmShaderParameterCollection m_parameters;
public:
	void Resolve(rapidxml::xml_node<> *root);
};
#endif