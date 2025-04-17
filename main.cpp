#include "GestorArchivos.cpp"
#include "Menu.h"

int main() {
      Coleccion* coleccion = new Coleccion();
      coleccion->cargarDatos();
      coleccion->reporteMaterialesPrestados();


      delete coleccion;
      return 0;
}