#ifndef _STAMINAFILEDIALOG_H
#define _STAMINAFILEDIALOG_H
#include <shobjidl.h>

#define COM_STARTUP_FLAGS ::COINIT_APARTMENTTHREADED | ::COINIT_DISABLE_OLE1DDE

COMDLG_FILTERSPEC rscFileFilter[] = {
	{ L"ALL CW XML", L"*.xml" },
	{ L"YDR CW XML", L"*.ydr.xml" },
	{ L"YDD CW XML", L"*.ydd.xml" },
	{ L"YBN CW XML", L"*.ybn.xml" },
	//{ L"ALL", L"*.*" },
};

#define MAX_SIZE 4096;
class StaminaFileDialog {
private:
	HRESULT m_hResult;
	::IFileOpenDialog *m_pFileOpenDialog;
	IShellItemArray *m_pShellItems;
	std::vector<std::wstring> m_filePaths;

public:
	void OpenFileDialog(void) {
		m_hResult = ::CoInitializeEx(NULL, COM_STARTUP_FLAGS);
		if (SUCCEEDED(m_hResult)) {
			m_hResult = ::CoCreateInstance(::CLSID_FileOpenDialog, NULL, CLSCTX_ALL, ::IID_IFileOpenDialog, (void **)(&m_pFileOpenDialog));
			if (SUCCEEDED(m_hResult)) {
				m_hResult = m_pFileOpenDialog->SetTitle(L"Stamina File Selection Dialog");
				if (SUCCEEDED(m_hResult)) {
					m_hResult = m_pFileOpenDialog->SetOptions(FOS_ALLOWMULTISELECT);
					if (SUCCEEDED(m_hResult)) {
						m_hResult = m_pFileOpenDialog->SetFileTypes(ARRAYSIZE(rscFileFilter), rscFileFilter);
						if (SUCCEEDED(m_hResult)) {
							m_hResult = m_pFileOpenDialog->Show(NULL);

							if (SUCCEEDED(m_hResult)) {
								m_hResult = m_pFileOpenDialog->GetResults(&m_pShellItems);
							}
						}
					}
				}

			}
		}
		m_pFileOpenDialog->Release();
	}
	
	
	void GetLastSelected(void) {
		DWORD itemCount;
		m_hResult = m_pShellItems->GetCount(&itemCount);
		m_filePaths.clear();
		m_filePaths.reserve(itemCount);
		for (DWORD i = 0; SUCCEEDED(m_hResult) && (i < itemCount); i++) {
			IShellItem *shellItem;
			m_hResult = m_pShellItems->GetItemAt(i, &shellItem);

			if (SUCCEEDED(m_hResult)) {
				PWSTR pszPath;
				m_hResult = shellItem->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &pszPath);
				if (SUCCEEDED(m_hResult)) {
					m_filePaths.push_back(std::wstring(pszPath));
					CoTaskMemFree(pszPath);
				}
			}
		}
	}
	std::vector<std::wstring> &GetFilePaths(void) {
		GetLastSelected();
		return m_filePaths;
	}
};

#endif