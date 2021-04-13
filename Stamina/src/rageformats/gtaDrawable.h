#ifndef _GTADRAWABLE_H
#define _GTADRAWABLE_H

/*
gtaDrawable (#dr) is based on Codewalker's (https://github.com/dexyfex/CodeWalker) implementation of Grand Theft Auto V's gtaDrawable in their xml format.
Most files in this directory (rageformats) are based on the implementation from the CitizenFX FiveM repo (https://github.com/citizenfx/fivem/tree/34069da52f788a6e21c7ae2e9fc6d84dda932abe/code/components/rage-formats-x).
*/

#include <xml/Xml.h>
#include <math/Vectors.h>
#include <rageformats/grmShaderGroup.h>
#include <rageformats/grmModel.h>
#include <rageformats/CLightAttr.h>

class gtaDrawable : IXml {
private:
	const char *m_name;
	Vector3 m_bsCenter;
	float m_bsRadius;
	Vector3 m_bbMin;
	Vector3 m_bbMax;
	Vector4 m_lodDist;
	Vector4 m_flags;
	unsigned short m_unk;
	grmShaderGroup m_shaderGroup;
	grmModel m_models[4];
	CCollection<CLightAttr> m_lightAttrs;

public: 
	void Resolve(rapidxml::xml_node<> *root);
	//void Write(rapidxml::xml_document<> *document, rapidxml::xml_node<> *parent);

	grmShaderGroup &GetShaderGroup(void) {
		return m_shaderGroup;
	}

	grmModel &GetModel(int index) {
		return m_models[index];
	}

	const char *GetName(void) {
		return m_name;
	}

	void SetName(const char *name) {
		m_name = name;
	}

	Vector3 GetBsCenter(void) {
		return m_bsCenter;
	}

	void SetBsCenter(float x, float y, float z) {
		m_bsCenter.x = x;
		m_bsCenter.y = y;
		m_bsCenter.z = z;
	}
};

#endif