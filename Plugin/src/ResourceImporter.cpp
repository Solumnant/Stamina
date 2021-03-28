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
		Stamina::Log(LEVEL_LOG, "Importing Resource File: %s", StaminaMax::AsciiString(file.c_str()));
		rapidxml::file<> xmlFile(StaminaMax::AsciiString(file.c_str()));
		rapidxml::xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		ResourceFile<gtaDrawable, GTADRAWABLE_FILE> ydr;
		ydr.Resolve(doc.first_node());
		Stamina::Log(LEVEL_LOG, "NAME: %s", ydr.GetResource().GetName());
	}
	
	return 1;
}