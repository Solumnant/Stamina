#ifndef _XML_H
#define _XML_H
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <math/Vectors.h>
#include <string>

class IXml {
	virtual void Resolve(rapidxml::xml_node<> *root) = 0;
};


inline Vector3 ParseVec3(rapidxml::xml_node<> *node) {
	Vector3 temp;
	temp.x = atof(node->first_attribute("x")->value());
	temp.y = atof(node->first_attribute("y")->value());
	temp.z = atof(node->first_attribute("z")->value());
	return temp;
};
inline Vector4 ParseVec4(rapidxml::xml_node<> *node) {
	Vector4 temp;
	temp.x = atof(node->first_attribute("x")->value());
	temp.y = atof(node->first_attribute("y")->value());
	temp.z = atof(node->first_attribute("z")->value());
	temp.w = atof(node->first_attribute("w")->value());
	return temp;
};

//inline void WriteVec3(rapidxml::xml_document<> *document, rapidxml::xml_node<> *node, Vector3 vec3) {
//	
//	rapidxml::xml_attribute<> *attribute_x = document->allocate_attribute("x", "1");
//	rapidxml::xml_attribute<> *attribute_y = document->allocate_attribute("y", "2");
//	rapidxml::xml_attribute<> *attribute_z = document->allocate_attribute("z", "3");
//	node->append_attribute(attribute_x);
//	node->append_attribute(attribute_y);
//	node->append_attribute(attribute_z);
//}
#endif