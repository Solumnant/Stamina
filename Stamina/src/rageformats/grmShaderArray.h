#ifndef _GRM_SHADER_DICTIONARY_H
#define _GRM_SHADER_DICTIONARY_H
#include <vector>
#include <rageformats/grmShaderFx.h>
#include <Xml.h>
class grmShaderArray : IXml {
private:
	std::vector<grmShaderFx> m_shaders;
public:
	void Resolve(rapidxml::xml_node<> *root);
};
#endif