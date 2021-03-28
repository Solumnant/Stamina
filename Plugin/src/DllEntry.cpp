#include <wtypes.h>
#include <iparamb2.h>
#include <Stamina.h>

extern ClassDesc2 *GetResourceImporterDesc();

HINSTANCE hInstance;
BOOL WINAPI
DllMain(HINSTANCE hinstDLL, ULONG fdwReason, LPVOID lpvReserved) {
	//	hInstance = hinstDLL;
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			hInstance = hinstDLL;
			Stamina::Init();
			//RegisterNotification(onStartup, NULL, NOTIFY_SYSTEM_STARTUP);
			
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			Stamina::Shutdown();
			break;
	}
	return TRUE;
}

__declspec(dllexport) int
LibNumberClasses(void) {
	return 1;
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

		default:
			return NULL;
	}
}

__declspec(dllexport) ULONG
LibVersion(void) { return VERSION_3DSMAX; }

__declspec(dllexport)
ULONG CanAutoDefer(void) { return 0; }
