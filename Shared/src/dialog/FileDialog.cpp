#include <dialog/FileDialog.h>

COMDLG_FILTERSPEC rscFileFilter[] = {
	{ L"ALL CW XML", L"*.xml" },
	{ L"YDR CW XML", L"*.ydr.xml" },
	{ L"YDD CW XML", L"*.ydd.xml" },
	{ L"YBN CW XML", L"*.ybn.xml" },
	//{ L"ALL", L"*.*" },
};

void StaminaFileDialog::OpenFileDialog() {
	HRESULT hResult;
	hResult = ::CoInitializeEx(NULL, COM_STARTUP_FLAGS);
	if (SUCCEEDED(hResult)) {
		hResult = ::CoCreateInstance(::CLSID_FileOpenDialog, NULL, CLSCTX_ALL, ::IID_IFileOpenDialog, (void **)(&m_pFileOpenDialog));
		if (SUCCEEDED(hResult)) {
			hResult = m_pFileOpenDialog->SetTitle(L"Stamina File Selection Dialog");
			if (SUCCEEDED(hResult)) {
				hResult = m_pFileOpenDialog->SetOptions(FOS_ALLOWMULTISELECT);
				if (SUCCEEDED(hResult)) {
					hResult = m_pFileOpenDialog->SetFileTypes(ARRAYSIZE(rscFileFilter), rscFileFilter);
					if (SUCCEEDED(hResult)) {
						hResult = m_pFileOpenDialog->Show(NULL);

						if (SUCCEEDED(hResult)) {
							hResult = m_pFileOpenDialog->GetResults(&m_pShellItems);
						}
					}
				}
			}

		}
	}
	m_pFileOpenDialog->Release();
}

void StaminaFileDialog::GetLastSelected(void) {
	if (m_pShellItems == NULL) {
		return;
	}

	DWORD itemCount;
	HRESULT hResult;
	hResult = m_pShellItems->GetCount(&itemCount);

	m_filePaths.clear();
	m_filePaths.reserve(itemCount);
	for (DWORD i = 0; SUCCEEDED(hResult) && (i < itemCount); i++) {

		IShellItem *shellItem;
		hResult = m_pShellItems->GetItemAt(i, &shellItem);

		if (SUCCEEDED(hResult)) {
			PWSTR pszPath;
			hResult = shellItem->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &pszPath);
			if (SUCCEEDED(hResult)) {
				m_filePaths.push_back(std::wstring(pszPath));
				CoTaskMemFree(pszPath);
			}
		}
	}
}

std::vector<std::wstring> &StaminaFileDialog::GetFilePaths(void) {
	GetLastSelected();
	return m_filePaths;
}