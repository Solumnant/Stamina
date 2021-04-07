#include <dialog/FileDialog.h>

COMDLG_FILTERSPEC rscFileFilter[] = {
	{ L"ALL CW XML", L"*.xml" },
	{ L"YDR CW XML", L"*.ydr.xml" },
	{ L"YDD CW XML", L"*.ydd.xml" },
	{ L"YBN CW XML", L"*.ybn.xml" },
	//{ L"ALL", L"*.*" },
};

void StaminaFileDialog::OpenFileDialog() {
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