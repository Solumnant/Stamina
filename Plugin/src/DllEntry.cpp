#include <wtypes.h>
#include <iparamb2.h>
#include <Stamina.h>
#include <notify.h>
#include <StaminaMax.h>
extern ClassDesc2 *GetResourceImporterDesc();
extern ClassDesc2 *GetStaminaMenuDesc();
//__declspec(dllexport)
//int LibInitialize(void) {
//#pragma message(TODO("Check for failure when things can actually fail here."))
//	Stamina::Init();
//	StaminaMax::Init();
//	return TRUE;
//}
//__declspec(dllexport)
//int LibShutdown(void) {
//	Stamina::Shutdown();
//	StaminaMax::Shutdown();
//	return TRUE;
//}


HINSTANCE hInstance;
BOOL WINAPI
DllMain(HINSTANCE hinstDLL, ULONG fdwReason, LPVOID lpvReserved) {
	//	hInstance = hinstDLL;
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			hInstance = hinstDLL;
			
			if (!AllocConsole()) {
				MessageBox(NULL, L"Failed To Open Console", NULL, MB_OK);
				return -1;
			}
			FILE *file;
			freopen_s(&file, "CONOUT$", "w", stdout);
			freopen_s(&file, "CONIN$", "r", stdin);

			Stamina::Init();
			StaminaMax::Init();
			//RegisterNotification(onStartup, NULL, NOTIFY_SYSTEM_STARTUP);
			
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			StaminaMax::Shutdown();
			Stamina::Shutdown();
			FreeConsole();
			//UnRegisterNotification(onStartup, NULL, NOTIFY_SYSTEM_STARTUP);
			break;
	}
	return TRUE;
}

__declspec(dllexport) int
LibNumberClasses(void) {
	return 2;
}

__declspec(dllexport) const TCHAR *
LibDescription(void) {
	return _T("CodeWalker XML Importer/Exporter based on GTA V");
}

__declspec(dllexport) ClassDesc2 *
LibClassDesc(int i) {
	switch (i) {
		case 0:
			return GetResourceImporterDesc() /*desc()*/;
		case 1:
			return GetStaminaMenuDesc();
		default:
			return NULL;
	}
}

TCHAR *
GetString(int id) {
	static TCHAR buf[256];

	if (hInstance)
		return LoadString(hInstance, id, buf, _countof(buf)) ? buf : NULL;
	return NULL;
}


__declspec(dllexport) ULONG
LibVersion(void) { return VERSION_3DSMAX; }

__declspec(dllexport)
ULONG CanAutoDefer(void) { return 0; }
