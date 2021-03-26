#ifndef _GRC_TEXTURE_DICTIONARY_H
#define _GRC_TEXTURE_DICTIONARY_H
#include <vector>
#include <rageformats/grcTexturePC.h>
#include <Xml.h>
class grcTextureDictionary : IXml {
private:
	std::vector<grcTexturePC> m_textures;
public:
	void Resolve(rapidxml::xml_node<> *root);
};
#endif