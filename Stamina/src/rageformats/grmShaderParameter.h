#ifndef _GRM_SHADER_PARAMETER_H
#define _GRM_SHADER_PARAMETER_H
#include <Xml.h>

enum eParameterType : char {
	Texture = 0,
	Vector = 1
};

class grmShaderParameter : IXml {
private:
	const char *m_name;
	char m_type;
	Vector4 m_values;
	const char *m_samplerTxd;
public:
	void Resolve(rapidxml::xml_node<> *root);

};
#endif