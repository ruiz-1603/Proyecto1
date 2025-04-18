#ifndef MENU_H
#define MENU_H

#include "Coleccion.h"

class Menu {
private:
  Coleccion* interfaz;
public:
	Menu();
    ~Menu();

    void menuPrincipal();

    void subMenuInventario();
    void subMenuUsuarios();
    void subMenuPrestamos();
    void subMenuArchivos();
};



#endif //MENU_H
