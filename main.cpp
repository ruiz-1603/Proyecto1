#include "GestorArchivos.cpp"
#include "Menu.h"

int main() {
      /*Coleccion* coleccion = new Coleccion();
      coleccion->cargarDatos();
      coleccion->reporteMaterialesPrestados();*/

      //delete coleccion;
        
     Menu* interfaz = new Menu();
     interfaz->menuPrincipal();
     delete interfaz;


    return 0;
}