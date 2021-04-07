#ifndef _GRM_GEOMETRY_QB_H
#define _GRM_GEOMETRY_QB_H

#include <Xml.h>
#include <rageformats/grcIndexBuffer.h>
#include <rageformats/grcVertexBuffer.h>

class grmGeometryQB : IXml {
private:
	unsigned short m_shaderidx;
	Vector4 m_bbMin;
	Vector4 m_bbMax;
	grcVertexBuffer m_vertexBuffer;
	grcIndexBuffer m_indexBuffer;
public:
	void Resolve(rapidxml::xml_node<> *node);

	grcVertexBuffer &GetVertexBuffer(void) {
		return m_vertexBuffer;
	}
	grcIndexBuffer &GetIndexBuffer(void) {
		return m_indexBuffer;
	}
};

#endif