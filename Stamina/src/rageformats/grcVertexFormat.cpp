#include <rageformats/grcVertexFormat.h>

/*implement type (gtav1, gtav2, etc.) + size. */

void grcVertexFormat::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}
	if (strcmp("GTAV1", node->first_attribute()->value()) == 0) {
		m_vertexFields = 0x7755555555996996;
	}
	m_mask = 0;
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		int index = GetVertexElementFromName(child->name());
		m_mask = m_mask | (1u << index);
	}
}

inline int grcVertexFormat::GetVertexElementFromName(const char *name) {
	if (strcmp("Position", name) == 0) {
		return (int)VertexElementTypes::d3dPositionType;
	}
	if (strcmp("BlendWeights", name) == 0) {
		return (int)VertexElementTypes::d3dBlendWeightType;
	}
	if (strcmp("BlendIndices", name) == 0) {
		return (int)VertexElementTypes::d3dBlendIndicesType;
	}
	if (strcmp("Normal", name) == 0) {
		return (int)VertexElementTypes::d3dNormalType;
	}
	if (strcmp("Colour0", name) == 0) {
		return (int)VertexElementTypes::d3dColorType;
	}
	if (strcmp("Colour1", name) == 0) {
		return (int)VertexElementTypes::d3dColor2Type;
	}
	if (strcmp("TexCoord0", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord0Type;
	}
	if (strcmp("TexCoord1", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord1Type;
	}
	if (strcmp("TexCoord2", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord2Type;
	}
	if (strcmp("TexCoord3", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord3Type;
	}
	if (strcmp("TexCoord4", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord4Type;
	}
	if (strcmp("TexCoord5", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord5Type;
	}
	if (strcmp("TexCoord6", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord6Type;
	}
	if (strcmp("TexCoord7", name) == 0) {
		return (int)VertexElementTypes::d3dTexCoord7Type;
	}
	if (strcmp("Tangent", name) == 0) {
		return (int)VertexElementTypes::d3dTangentType;
	}
	if (strcmp("Binormal", name) == 0) {
		return (int)VertexElementTypes::d3dBinormalType;
	}
}
