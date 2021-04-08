#ifndef _FILEDIALOG_H
#define _FILEDIALOG_H

#include <vector>
#include <shobjidl.h>
#include <xstring>

#define COM_STARTUP_FLAGS ::COINIT_APARTMENTTHREADED | ::COINIT_DISABLE_OLE1DDE

class StaminaFileDialog {
private:
	::IFileOpenDialog *m_pFileOpenDialog;
	IShellItemArray *m_pShellItems;
	std::vector<std::wstring> m_filePaths;

public:
	StaminaFileDialog() {
		m_pFileOpenDialog = NULL;
		m_pShellItems = NULL;
	}

	void OpenFileDialog(void);
	void GetLastSelected(void);
	std::vector<std::wstring> &GetFilePaths(void);
};

#endif