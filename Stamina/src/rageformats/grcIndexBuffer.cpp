#include <rageformats/grcIndexBuffer.h>

void grcIndexBuffer::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}

	if ((strcmp("Data", node->first_node()->name()) == 0) ||
		(strcmp("Data1", node->first_node()->name()) == 0) ||
		(strcmp("Data2", node->first_node()->name()) == 0)) {
		void *pData = node->first_node()->value();
		char *value = strtok((char *)pData, " \r\n");
		while (value) {
			m_data.push_back((unsigned short)atof(value));
			value = strtok(NULL, " \r\n");
		}
	}

	m_indexCount = m_data.size();
}