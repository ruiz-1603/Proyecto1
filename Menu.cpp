#include "Menu.h"
#include "Limpieza.h"

Menu::Menu() { this->interfaz = new Coleccion(); }
Menu::~Menu() { delete interfaz; }

void Menu::menuPrincipal() {
  int opcion = -1;
  while (opcion != 0) {
    std::cout << "\tMenu Principal" << std::endl;
    std::cout << "1. Submenu Inventario" << std::endl;
    std::cout << "2. Submenu Usuarios" << std::endl;
    std::cout << "3. Submenu Prestamos" << std::endl;
    std::cout << "4. Submenu Archivos" << std::endl;
    std::cout << "0. Salir" << std::endl << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:

        subMenuInventario();
        break;
      case 2:

        subMenuUsuarios();
        break;
      case 3:

        subMenuPrestamos();
        break;
      case 4:

        subMenuArchivos();
        break;
    }
    Limpieza::limpiarPantalla();
  }
}

void Menu::subMenuInventario() {
  int opcion = -1;
  while (opcion != 0) {
    std::cout << "\tMenu Inventario" << std::endl;
    std::cout << "1. Agregar material" << std::endl;
    std::cout << "2. Modificar material" << std::endl;
    std::cout << "3. Eliminar material" << std::endl;
    std::cout << "4. Reporte de inventario" << std::endl;
    std::cout << "0. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:

        interfaz->agregarInventario();
        break;
      case 2:

        interfaz->modificarMaterial();
        break;
      case 3:

        interfaz->eliminarMaterial();
        break;
      case 4:

        interfaz->reporteInventario();
        Limpieza::pausar();
        break;
    }

  }
  Limpieza::limpiarPantalla();
}

void Menu::subMenuUsuarios() {
  int opcion = -1;
  while (opcion != 0) {
    std::cout << "\tMenu Usuarios" << std::endl;
    std::cout << "1. Agregar usuario" << std::endl;
    std::cout << "2. Modificar usuario" << std::endl;
    std::cout << "3. Eliminar usuario" << std::endl;
    std::cout << "4. Reporte de usuarios" << std::endl;
    std::cout << "0. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:

        interfaz->agregarUsuario();
        break;
      case 2:

        interfaz->modificarUsuario();
        break;
      case 3:

        interfaz->eliminarUsuario();
        break;
      case 4:

        interfaz->reporteUsuarios();
        Limpieza::pausar();
        break;
    }
  }
  Limpieza::limpiarPantalla();
}

void Menu::subMenuPrestamos() {
  int opcion = -1;
  while (opcion != 0) {
    std::cout << "\tMenu Prestamos" << std::endl;
    std::cout << "1. Registrar prestamo" << std::endl;
    std::cout << "2. Registrar devolucion" << std::endl;
    std::cout << "3. Reporte de prestamos (general)" << std::endl;
    std::cout << "4. Reporte de prestamos por material" << std::endl;
    std::cout << "5. Reporte de prestamos por usuario" << std::endl;
    std::cout << "0. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:

        interfaz->registrarPrestamo();
        break;
      case 2:

        interfaz->registrarDevolucion();
        break;
      case 3:

        interfaz->reporteMaterialesPrestados();
        Limpieza::pausar();
        break;
      case 4:
        interfaz->reporteMaterialesPorTipo();
        Limpieza::pausar();
        break;
      case 5:
        interfaz->reportePrestamosPorUsuario();
        Limpieza::pausar();
        break;
    }
  }
  Limpieza::limpiarPantalla();
}

void Menu::subMenuArchivos() {
  int opcion = -1;
  while (opcion != 0) {
    std::cout << "\tMenu Archivos" << std::endl;
    std::cout << "1. Guardar datos" << std::endl;
    std::cout << "2. Cargar datos" << std::endl;
    std::cout << "0. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
      case 1:
        interfaz->guardarMateriales();
        interfaz->guardarPrestamos();
        interfaz->guardarUsuarios();
        break;
      case 2:
        interfaz->cargarDatos();
        break;
      default:
        std::cout << "Error en guardar o cargar archivos" << std::endl;
        Limpieza::pausar();
        break;
    }
  }
}
