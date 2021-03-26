#ifndef _GTADRAWABLE_H
#define _GTADRAWABLE_H

/*
gtaDrawable (#dr) is based on Codewalker's (https://github.com/dexyfex/CodeWalker) implementation of Grand Theft Auto V's gtaDrawable in their xml format.
*/

#include <Xml.h>
#include <math/Vectors.h>
#include <rageformats/grmShaderGroup.h>
#include <rageformats/grmModel.h>

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

public: 
	void Resolve(rapidxml::xml_node<> *root);

	grmShaderGroup GetShaderGroup(void) {
		return m_shaderGroup;
	}
};

#endif