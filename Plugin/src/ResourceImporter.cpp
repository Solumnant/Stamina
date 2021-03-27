#include <ResourceImporter.h>
#include <iparamb2.h>
#include <Stamina.h>

ClassDesc2 *GetResourceImporterDesc() { return &resourceImporterDesc; }

ResourceImporter::ResourceImporter() {
}
ResourceImporter::~ResourceImporter() {
}

int ResourceImporter::DoImport(const TCHAR *file, ImpInterface *gi, Interface *i, BOOL suppressPrompts) {
	this->i = i;
	this->gi = gi;


	Stamina::Log(LEVEL_LOG, "Importing Resource File: %s", StaminaMax::AsciiString(file));
	
	return 1;
}