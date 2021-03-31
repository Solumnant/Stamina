#ifndef _GRC_VERTEXFORMAT_H
#define _GRC_VERTEXFORMAT_H
#include <Xml.h>

enum VertexElementTypes : int {
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

enum D3DVertexElementType {
    D3DVERTEXELEMENT_NOTAVAILABLE = 0,
    D3DVERTEXELEMENT_FLOAT16_2 = 1,
    D3DVERTEXELEMENT_FLOAT1 = 2,
    D3DVERTEXELEMENT_FLOAT16_4 = 3,
    D3DVERTEXELEMENT_FLOAT16_3 = 4, //float unk?
    D3DVERTEXELEMENT_FLOAT2 = 5,
    D3DVERTEXELEMENT_FLOAT3 = 6,
    D3DVERTEXELEMENT_FLOAT4 = 7,
    D3DVERTEXELEMENT_UBYTE4 = 8,
    D3DVERTEXELEMENT_D3DCOLOR = 9,
    D3DVERTEXELEMENT_DEC3N = 10,
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
    void GetComponentCountOffset(int &offset, int bit) {
        D3DVertexElementType elementType = (D3DVertexElementType)((m_vertexFields >> (4 * bit)) & 0xF);
        switch (elementType) {
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT4: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT3: offset += 3;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT2: offset += 2;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_NOTAVAILABLE:
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT1: offset += 1;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_3: offset += 0; //float unk?
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_DEC3N: offset += 3;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_D3DCOLOR: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_UBYTE4: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_2: offset += 2;
                break;
        }
    };

};
#endif
