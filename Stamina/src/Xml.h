#ifndef _XML_H
#define _XML_H
#include <rapidxml/rapidxml.hpp>
#include <math/Vectors.h>
#include <string>
class IXml {
	virtual void Resolve(rapidxml::xml_node<> *root) = 0;
};

inline Vector3 ParseVec3(rapidxml::xml_node<> *child) {
	Vector3 temp;
	temp.x = atof(child->first_attribute("x")->value());
	temp.y = atof(child->first_attribute("y")->value());
	temp.z = atof(child->first_attribute("z")->value());
	return temp;
};
inline Vector4 ParseVec4(rapidxml::xml_node<> *child) {
	Vector4 temp;
	temp.x = atof(child->first_attribute("x")->value());
	temp.y = atof(child->first_attribute("y")->value());
	temp.z = atof(child->first_attribute("z")->value());
	temp.w = atof(child->first_attribute("w")->value());
	return temp;
};
#endif