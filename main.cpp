#include "Menu.h"

int main() {
    Menu* menu = new Menu();
    menu->menuPrincipal();
    delete menu;
    return 0;
}