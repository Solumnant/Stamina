#ifndef _CLIGHTATTR_H
#define _CLIGHTATTR_H

#include <xml/Xml.h>

enum gtaLightType : unsigned char {
	Point = 1,
	Spot = 2,
	Capsule = 4,
};

class CLightAttr : IXml {
private:
	Vector3 m_position;
	unsigned char m_color[3];
	unsigned char m_flashiness;
	float m_intensity;
	unsigned int m_flags;
	unsigned short m_boneID;
	unsigned char m_lightType;
	unsigned char m_groupID;
	unsigned int m_timeFlags;
	float m_falloff;
	float m_falloffExponent;
	Vector4 m_cullingPlane;
	unsigned char m_unk45;
	unsigned short m_unk46;
	float m_volumeIntensity;
	float m_volumeSizeScale;
	unsigned char m_volumeOuterColor[3];
	unsigned char m_lightHash;
	float volumeOuterIntensity;
	float coronaSize;
	float volumeOuterExponent;
	unsigned char lightFadeDistance;
	unsigned char shadowFadeDistance;
	unsigned char specularFadeDistance;
	unsigned char volumetricFadeDistance;
	float shadowNearClip;
	float coronaIntensity;
	float coronaZBias;
	float direction[3];
	float tangent[3];
	float coneInnerAngle;
	float coneOuterAngle;
	float extents[3];
	unsigned int projectedTextureHash;
public:
	void Resolve(rapidxml::xml_node<> *root);
};

#endif