#include <rageformats/CLightAttr.h>



void CLightAttr::Resolve(rapidxml::xml_node<> *node) {
	if (node == nullptr) {
		return;
	}
	for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
		if (strcmp("Position", child->name()) == 0) {
			m_position = ParseVec3(child);
		}
		if (strcmp("Colour", child->name()) == 0) {
			m_color[0] = (unsigned char)atoi(child->first_attribute("r")->value());
			m_color[1] = (unsigned char)atoi(child->first_attribute("g")->value());
			m_color[2] = (unsigned char)atoi(child->first_attribute("b")->value());
		}
		if (strcmp("Flashiness", child->name()) == 0) {
			m_flashiness = (unsigned char)atoi(child->first_attribute()->value());
		}
		if (strcmp("Intensity", child->name()) == 0) {
			m_intensity = atof(child->first_attribute()->value());
		}
		if (strcmp("Flags", child->name()) == 0) {
			m_flags = atoi(child->first_attribute()->value());
		}
		if (strcmp("BoneId", child->name()) == 0) {
			m_boneID = (unsigned char)atoi(child->first_attribute()->value());
		}
		if (strcmp("Type", child->name()) == 0) {
			if (strcmp("Point", child->value()) == 0) {
				m_lightType = Point;
			} else if (strcmp("Spot", child->value()) == 0) {
				m_lightType = Spot;
			} else if (strcmp("Capsule", child->value()) == 0) {
				m_lightType = Capsule;
			}
		}
		if (strcmp("GroupId", child->name()) == 0) {
			m_groupID = (unsigned char)atoi(child->first_attribute()->value());
		}
		if (strcmp("TimeFlags", child->name()) == 0) {
			m_timeFlags = (unsigned int)atoi(child->first_attribute()->value());
		}
		if (strcmp("Falloff", child->name()) == 0) {
			m_falloff = atof(child->first_attribute()->value());
		}
		if (strcmp("FalloffExponent", child->name()) == 0) {
			m_falloffExponent = atof(child->first_attribute()->value());
		}
		if (strcmp("CullingPlaneNormal", child->name()) == 0) {
			m_cullingPlane.x = atof(child->first_attribute()->value());
			m_cullingPlane.y = atof(child->first_attribute()->value());
			m_cullingPlane.z = atof(child->first_attribute()->value());
		}
		if (strcmp("CullingPlaneOffset", child->name()) == 0) {
			m_cullingPlane.z = atof(child->first_attribute()->value());
		}
		if (strcmp("Unknown45", child->name()) == 0) {
			m_unk45 = (unsigned char)atoi(child->first_attribute()->value());
		}
		if (strcmp("Unknown46", child->name()) == 0) {
			m_unk46 = (unsigned short)atoi(child->first_attribute()->value());
		}
		if (strcmp("VolumeIntensity", child->name()) == 0) {
			m_volumeIntensity = atof(child->first_attribute()->value());
		}
		if (strcmp("VolumeSizeScale", child->name()) == 0) {
			m_volumeSizeScale = atof(child->first_attribute()->value());
		}
		if (strcmp("VolumeOuterColour", child->name()) == 0) {
			m_volumeOuterColor[0] = (unsigned char)atoi(child->first_attribute("r")->value());
			m_volumeOuterColor[1] = (unsigned char)atoi(child->first_attribute("g")->value());
			m_volumeOuterColor[2] = (unsigned char)atoi(child->first_attribute("b")->value());
		}
		if (strcmp("LightHash", child->name()) == 0) {
			m_lightHash = (unsigned char)atoi(child->first_attribute()->value());;
		}
		if (strcmp("VolumeOuterIntensity", child->name()) == 0) {
			m_volumeIntensity = atof(child->first_attribute()->value());;
		}
	}
}