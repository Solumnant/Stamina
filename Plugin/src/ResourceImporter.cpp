#include <ResourceImporter.h>
#include <iparamb2.h>
#include <Stamina.h>
#include <StaminaFileDialog.h>
#include <vector>
//temp
#include <RscFile.h>
#include <rapidxml/rapidxml.hpp>
#include <rageformats/gtaDrawable.h>

ClassDesc2 *GetResourceImporterDesc() { return &resourceImporterDesc; }

ResourceImporter::ResourceImporter() {
}
ResourceImporter::~ResourceImporter() {
}

int ResourceImporter::DoImport(const TCHAR *file, ImpInterface *gi, Interface *i, BOOL suppressPrompts) {
	this->i = i;
	this->gi = gi;
	/* temp dump */
	StaminaFileDialog staminaFileDialog;
	staminaFileDialog.OpenFileDialog();
	std::vector<std::wstring> files = staminaFileDialog.GetFilePaths();
	for (const auto &file: files) {
		//Stamina::Log(LEVEL_LOG, "Importing Resource File: %s", StaminaMax::AsciiString(file.c_str()));
		rapidxml::file<> xmlFile(StaminaMax::AsciiString(file.c_str()));
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		rapidxml::xml_node<> *root = doc.first_node();

		if (strcmp("Drawable", root->name()) == 0) {
			ResourceFile<gtaDrawable, GTADRAWABLE_FILE> ydr;
			ydr.Resolve(root);
			Stamina::Log(LEVEL_LOG, "RESOLVED: DRAWABLE");
		} else if(strcmp("DrawableDictionary", root->name()) == 0) {
			ResourceFile<CCollection<gtaDrawable>, PGDICTIONARY_GTADRAWABLE_FILE> ydd;
			ydd.Resolve(root);
			Stamina::Log(LEVEL_LOG, "RESOLVED: DRAWABLEDICTIONARY");
		}




	}
	
	return 1;
}