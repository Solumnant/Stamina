#ifndef _STAMINA_MENU_H
#define _STAMINA_MENU_H
#include <gup.h>
#include <iparamb2.h>
#define StaminaMenu_CLASS_ID Class_ID(0x38f73ba2, 0x6a695c6a)

class StaminaMenu : public GUP {
private:

public:
	StaminaMenu();
	~StaminaMenu();
	DWORD Start();
	DWORD_PTR Control(DWORD parameter);
	void Stop();
	void DeleteThis();
};

class StaminaMenuDesc : public ClassDesc2 {
public:
	int IsPublic(void) { return 1; }
	void *Create(BOOL loading = FALSE) { return new StaminaMenu(); }
	const TCHAR *ClassName(void) { return _T("Stamina Menu"); }
	SClass_ID SuperClassID(void) { return GUP_CLASS_ID; }
	Class_ID ClassID(void) { return StaminaMenu_CLASS_ID; }
	const TCHAR *Category(void) { return _T("Global Utility"); }

} staminaMenuDesc;


#endif