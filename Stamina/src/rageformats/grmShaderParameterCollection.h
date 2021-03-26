#ifndef _GRM_SHADER_PARAMETER_COLLECTION_H
#define _GRM_SHADER_PARAMETER_COLLECTION_H
#include <rageformats/grmShaderParameter.h>
#include <Xml.h>
#include <vector>
class grmShaderParameterCollection : IXml {
private:
	std::vector<grmShaderParameter> m_parameters;
public:
	void Resolve(rapidxml::xml_node<> *root);
};
#endif