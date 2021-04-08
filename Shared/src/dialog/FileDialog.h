#ifndef _FILEDIALOG_H
#define _FILEDIALOG_H

#include <vector>
#include <shobjidl.h>
#include <xstring>

#define COM_STARTUP_FLAGS ::COINIT_APARTMENTTHREADED | ::COINIT_DISABLE_OLE1DDE



class StaminaFileDialog {
private:
	HRESULT m_hResult;
	::IFileOpenDialog *m_pFileOpenDialog;
	IShellItemArray *m_pShellItems;
	std::vector<std::wstring> m_filePaths;

public:
	StaminaFileDialog() {
		m_pFileOpenDialog = NULL;
		m_pShellItems = NULL;
	}
	void OpenFileDialog(void);


	void GetLastSelected(void) {
		if (m_pShellItems == NULL) {
			return;
		}

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