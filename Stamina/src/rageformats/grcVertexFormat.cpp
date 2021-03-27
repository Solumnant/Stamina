#include <rageformats/grcVertexFormat.h>
#include "grcVertexFormat.h"
#include <Stamina.h>
/*implement type (gtav1, gtav2, etc.) + size. */
void grcVertexFormat::Resolve(rapidxml::xml_node<> *node) {
	m_mask = 0;
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		int index = GetVertexElementFromName(child->name());
		m_mask = m_mask | (1u << index);
	}
}

inline int grcVertexFormat::GetVertexElementFromName(const char *name) {
	if (strcmp("Position", name) == 0) {
		return (int)VertexElementTypes::PositionType;
	}
	if (strcmp("BlendWeights", name) == 0) {
		return (int)VertexElementTypes::BlendWeightType;
	}
	if (strcmp("BlendIndices", name) == 0) {
		return (int)VertexElementTypes::BlendIndicesType;
	}
	if (strcmp("Normal", name) == 0) {
		return (int)VertexElementTypes::NormalType;
	}
	if (strcmp("Colour0", name) == 0) {
		return (int)VertexElementTypes::ColorType;
	}
	if (strcmp("Colour1", name) == 0) {
		return (int)VertexElementTypes::Color2Type;
	}
	if (strcmp("TexCoord0", name) == 0) {
		return (int)VertexElementTypes::TexCoord0Type;
	}
	if (strcmp("TexCoord1", name) == 0) {
		return (int)VertexElementTypes::TexCoord1Type;
	}
	if (strcmp("TexCoord2", name) == 0) {
		return (int)VertexElementTypes::TexCoord2Type;
	}
	if (strcmp("TexCoord3", name) == 0) {
		return (int)VertexElementTypes::TexCoord3Type;
	}
	if (strcmp("TexCoord4", name) == 0) {
		return (int)VertexElementTypes::TexCoord4Type;
	}
	if (strcmp("TexCoord5", name) == 0) {
		return (int)VertexElementTypes::TexCoord5Type;
	}
	if (strcmp("TexCoord6", name) == 0) {
		return (int)VertexElementTypes::TexCoord6Type;
	}
	if (strcmp("TexCoord7", name) == 0) {
		return (int)VertexElementTypes::TexCoord7Type;
	}
	if (strcmp("Tangent", name) == 0) {
		return (int)VertexElementTypes::TangentType;
	}
	if (strcmp("Binormal", name) == 0) {
		return (int)VertexElementTypes::BinormalType;
	}
}
