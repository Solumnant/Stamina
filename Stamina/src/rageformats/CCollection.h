#ifndef _CCOLLECTION_H
#define _CCOLLECTION_H

#include <vector>
#include <Xml.h>

template<typename T>
class CCollection : IXml {
	std::vector<T> m_collection;
public:
	void Resolve(rapidxml::xml_node<> *node) {
		if (node == nullptr) {
			return;
		}
		for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
			T temp;
			temp.Resolve(child);
			m_collection.push_back(temp);
		}
	}

	std::vector<T> &GetCollection(void) {
		return m_collection;
	}
};

#endif