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

enum struct D3DVertexElementType {
    D3DVERTEXELEMENT_FLOAT16,
    D3DVERTEXELEMENT_FLOAT16_2,
    D3DVERTEXELEMENT_FLOAT16_3,
    D3DVERTEXELEMENT_FLOAT16_4,
    D3DVERTEXELEMENT_FLOAT1,
    D3DVERTEXELEMENT_FLOAT2,
    D3DVERTEXELEMENT_FLOAT3,
    D3DVERTEXELEMENT_FLOAT4,
    D3DVERTEXELEMENT_UBYTE4,
    D3DVERTEXELEMENT_D3DCOLOR,
    D3DVERTEXELEMENT_DEC3N,
    D3DVERTEXELEMENT_NOTAVAILABLE = 0
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

    void GetComponentOffset(size_t &offset, int bit, unsigned long long type) {
        D3DVertexElementType elementType = (D3DVertexElementType)((type >> (4 * bit)) & 0xF);
        switch (elementType) {
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT4: offset += 4;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT3: offset += 4;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT2: offset += 4;
            case D3DVertexElementType::D3DVERTEXELEMENT_NOTAVAILABLE:
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT1:
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_3: offset += 4; //float unk?
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_DEC3N: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_D3DCOLOR:
            case D3DVertexElementType::D3DVERTEXELEMENT_UBYTE4: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_2: offset += 4;
                break;
        }
    };
    void GetComponentCountOffset(unsigned short &offset, int bit) {
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
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_3: offset += 3; //float unk?
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_DEC3N: offset += 3;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_D3DCOLOR: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_UBYTE4: offset += 4;
                break;
            case D3DVertexElementType::D3DVERTEXELEMENT_FLOAT16_2: offset += 4;
                break;
        }
    };

};
#endif
//case VertexComponentType.Nothing: return 0;
//case VertexComponentType.Half2: return 2;
//case VertexComponentType.Float: return 1;
//case VertexComponentType.Half4: return 4;
//case VertexComponentType.FloatUnk: return 0;
//case VertexComponentType.Float2: return 2;
//case VertexComponentType.Float3: return 3;
//case VertexComponentType.Float4: return 4;
//case VertexComponentType.UByte4: return 4;
//case VertexComponentType.Colour: return 4;
//case VertexComponentType.Dec3N: return 3;