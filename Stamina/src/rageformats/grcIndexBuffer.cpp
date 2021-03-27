#include <rageformats/grcIndexBuffer.h>

void grcIndexBuffer::Resolve(rapidxml::xml_node<> *node) {
	if ((strcmp("Data", node->first_node()->name()) == 0) || 
		(strcmp("Data1", node->first_node()->name()) == 0)|| 
		(strcmp("Data2", node->first_node()->name()) == 0))  {
		m_data = node->first_node()->value();
	}
}
