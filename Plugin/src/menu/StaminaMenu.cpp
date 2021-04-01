#include <menu/StaminaMenu.h>
ClassDesc2 *GetStaminaMenuDesc() { return &staminaMenuDesc; }

StaminaMenu::StaminaMenu() {

}
StaminaMenu::~StaminaMenu() {

}

DWORD StaminaMenu::Start() {
	return 0;
}

DWORD_PTR StaminaMenu::Control(DWORD) {
	return 0;
}

void StaminaMenu::Stop() {
	return;
}
void StaminaMenu::DeleteThis() {
	return;
}
