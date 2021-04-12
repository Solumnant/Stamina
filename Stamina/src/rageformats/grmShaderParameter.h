#ifndef _GRM_SHADER_PARAMETER_H
#define _GRM_SHADER_PARAMETER_H

#include <xml/Xml.h>

enum eParameterType : char {
	Texture = 0,
	Vector = 1
};

class grmShaderParameter : IXml {
private:
	/*every parameter*/
	const char *m_name;
	char m_type;
	/*texture parameter*/
	Vector4 m_values;
	const char *m_samplerTxd;
	/*array parameter*/
	std::vector<Vector4> m_array;

public:
	void Resolve(rapidxml::xml_node<> *root);

};

#endif