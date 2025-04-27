#include "Menu.h"
#include "Limpieza.h"

Menu::Menu() { this->interfaz = new Coleccion(); }
Menu::~Menu() { delete interfaz; }

void Menu::menuPrincipal() {
  int opcion = -1;
  while (opcion != 0) {
    try{
      cout << "\tMenu Principal" << endl;
      cout << "1. Submenu Inventario" << endl;
      cout << "2. Submenu Usuarios" << endl;
      cout << "3. Submenu Prestamos" << endl;
      cout << "4. Submenu Archivos" << endl;
      cout << "0. Salir" << endl << endl;
      cout << "Seleccione una opcion: ";
      if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. Por favor ingrese un numero.");
      }

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
        case 0: break;
        default: throw Exception("Opcion no valida. Intente de nuevo.");
      }

    } catch (Exception &e) {
      cerr << "Error: " << e.what() << std::endl;
      Limpieza::pausar();
    }
  }
}

void Menu::subMenuInventario() {
  int opcion = -1;
  while (opcion != 0) {
    try{
      cout << "\tMenu Inventario" << endl;
      cout << "1. Agregar material" << endl;
      cout << "2. Modificar material" << endl;
      cout << "3. Eliminar material" << endl;
      cout << "4. Reporte de inventario" << endl;
      cout << "0. Regresar" << endl << endl;
      cout << "Seleccione una opcion: ";
      if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. Por favor ingrese un numero.");
      }

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

        case 0: break;

        default: throw Exception("Opcion no valida. Intente de nuevo.");
            Limpieza::pausar();
            Limpieza::limpiarPantalla();
      }
    }catch (Exception &e) {
      cerr << "Error: " << e.what() << std::endl;
      Limpieza::pausar();
    }
  }
}

void Menu::subMenuUsuarios() {
  try {
    int opcion = -1;
    while (opcion != 0) {
      cout << "\tMenu Usuarios" << endl;
      cout << "1. Agregar usuario" << endl;
      cout << "2. Modificar usuario" << endl;
      cout << "3. Eliminar usuario" << endl;
      cout << "4. Reporte de usuarios" << endl;
      cout << "0. Regresar" << endl << endl;
      cout << "Seleccione una opcion: ";
      if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. Por favor ingrese un numero.");
      }

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

        case 0: break;

        default: throw Exception("Opcion no valida. Intente de nuevo.");
      }
    }
  }catch (Exception &e) {
    cerr << "Error: " << e.what() << std::endl;
    Limpieza::pausar();
  }
}

void Menu::subMenuPrestamos() {
  try{
    int opcion = -1;
    while (opcion != 0) {
      cout << "\tMenu Prestamos" << endl;
      cout << "1. Registrar prestamo" << endl;
      cout << "2. Registrar devolucion" << endl;
      cout << "3. Reporte de prestamos (general)" << endl;
      cout << "4. Reporte de prestamos por material" << endl;
      cout << "5. Reporte de prestamos por usuario" << endl;
      cout << "0. Regresar" << endl << endl;
      cout << "Seleccione una opcion: ";
      if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. Por favor ingrese un numero.");
      }

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
        case 0: break;
        default: throw Exception("Opcion no valida. Intente de nuevo.");
      }
    }
  }catch (Exception &e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Menu::subMenuArchivos() {
  try{
    int opcion = -1;
    while (opcion != 0) {
     cout << "\tMenu Archivos" << endl;
      cout << "1. Guardar datos" << endl;
      cout << "2. Cargar datos" << endl;
      cout << "0. Regresar" << endl << endl;
      cout << "Seleccione una opcion: ";
      if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. Por favor ingrese un numero.");
      }

      switch (opcion) {
        case 1:
          interfaz->guardarMateriales();
        interfaz->guardarPrestamos();
        interfaz->guardarUsuarios();
        break;
        case 2:
          interfaz->cargarDatos();
        break;
        case 0:
          break;
        default:
          throw Exception("Opcion no valida.");
      }
    }
  }catch (Exception &e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}