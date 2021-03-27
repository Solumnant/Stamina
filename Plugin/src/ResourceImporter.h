#ifndef _RESOURCEIMPORTER_H
#define _RESOURCEIMPORTER_H
#include <impexp.h>
#include <iparamb2.h>
#include <StaminaMax.h>

#define ResourceImporter_CLASS_ID Class_ID(0x48b92248, 0xfc54f3f)
class ResourceImporter : public SceneImport {
private:
	ImpInterface *gi;
	Interface *i;
public:
	ResourceImporter();
	~ResourceImporter();

	int	ExtCount() {
		return 1;
	}
	const TCHAR *Ext(int n) {
		switch (n) {
			case 0:
				return _T("xml");
		}

		return _T("");
	}
	const TCHAR *LongDesc() {
		return _T("RAGE Resource Importer (GTA V) based upon CodeWalker's XML implementation of RAGE resource files.");
	}
	const TCHAR *ShortDesc() {
		return _T("CodeWalker XML Resource");
	}
	const TCHAR *AuthorName() {
		return _T("DPS");
	}
	const TCHAR *CopyrightMessage() {
		return _T("TODO");
	}
	const TCHAR *OtherMessage1() {
		return _T("");
	}			// Other message #1
	const TCHAR *OtherMessage2() {
		return _T("");
	}
	unsigned int Version() {
		return STAMINAMAX_VERSION;
	}
	void ShowAbout(HWND hWnd) {
	}
	int	DoImport(const TCHAR *name, ImpInterface *i, Interface *gi, BOOL suppressPrompts = FALSE);	// Import file

};

class ResourceImporterDesc : public ClassDesc2 {
public:
	int IsPublic(void) { return 1; }
	void *Create(BOOL loading = FALSE) { return new ResourceImporter(); }
	const TCHAR *ClassName(void) { return _T("RAGE Resource Import"); }
	SClass_ID SuperClassID(void) { return SCENE_IMPORT_CLASS_ID; }
	Class_ID ClassID(void) { return ResourceImporter_CLASS_ID; }
	const TCHAR *Category(void) { return _T("Scene Import"); }

} resourceImporterDesc;

//ClassDesc2 *ResourceImporterDesc();

#endif