#ifndef _GRC_VERTEXFORMAT_H
#define _GRC_VERTEXFORMAT_H
#include <Xml.h>

enum struct VertexElementTypes : int {
    PositionType = 0, // D3DVERTEXELEMENT_FLOAT3
    BlendWeightType = 1, // D3DVERTEXELEMENT_D3DCOLOR
    BlendIndicesType = 2, // D3DVERTEXELEMENT_D3DCOLOR
    NormalType = 3, // D3DVERTEXELEMENT_FLOAT3
    ColorType = 4, // D3DVERTEXELEMENT_D3DCOLOR
    Color2Type = 5, // D3DVERTEXELEMENT_D3DCOLOR
    TexCoord0Type = 6, // D3DVERTEXELEMENT_FLOAT2
    TexCoord1Type = 7, // D3DVERTEXELEMENT_FLOAT2
    TexCoord2Type = 8, // D3DVERTEXELEMENT_FLOAT2
    TexCoord3Type = 9, // D3DVERTEXELEMENT_FLOAT2
    TexCoord4Type = 10, // D3DVERTEXELEMENT_FLOAT2
    TexCoord5Type = 11, // D3DVERTEXELEMENT_FLOAT2
    TexCoord6Type = 12, // D3DVERTEXELEMENT_FLOAT2
    TexCoord7Type = 13, // D3DVERTEXELEMENT_FLOAT2 
    TangentType = 14, // D3DVERTEXELEMENT_FLOAT4
    BinormalType = 15, // D3DVERTEXELEMENT_FLOAT4
};


class grcVertexFormat : IXml {
private:
	unsigned short m_mask;
	unsigned char m_vertexSize;
	unsigned long long m_vertexFields;
public:
	void Resolve(rapidxml::xml_node<> *node);
    inline int GetVertexElementFromName(const char *name);

    unsigned long long GetMask() {
        return m_mask;
    }
    unsigned long long GetFVF() {
        return m_vertexFields;
    }
};
#endif