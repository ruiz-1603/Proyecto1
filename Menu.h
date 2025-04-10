//
// Created by castr on 7/4/2025.
//

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
};



#endif //MENU_H
