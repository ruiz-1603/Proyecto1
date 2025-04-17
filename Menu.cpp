#include "Menu.h"

Menu::Menu() { this->interfaz = new Coleccion();}
Menu::~Menu() { delete interfaz; }

void Menu::menuPrincipal() {
  int opcion = -1;
  while (opcion != 0) {
    cout << "\tMenu Principal" << endl;
    cout << "1. Submenu Inventario" << endl;
    cout << "2. Submenu Usuarios" << endl;
    cout << "3. Submenu Prestamos" << endl;
    cout << "4. Submenu Archivos" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        subMenuInventario();
        break;
      case 2:
        system("cls");
        subMenuUsuarios();
        break;
      case 3:
        system("cls");
        subMenuPrestamos();
        break;
      case 4:
        system("cls");
        subMenuArchivos();
        break;
    }
    system("cls");
  }
}

void Menu::subMenuInventario() {
  int opcion = -1;
  while (opcion != 0) {
    cout << "\tMenu Inventario" << endl;
    cout << "1. Agregar material" << endl;
    cout << "2. Modificar material" << endl;
    cout << "3. Eliminar material" << endl;
    cout << "4. Reporte de inventario" << endl;
    cout << "0. Regresar" << endl << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->agregarInventario();
        break;
      case 2:
        system("cls");
        interfaz->modificarMaterial();
        break;
      case 3:
        system("cls");
        interfaz->eliminarMaterial();
        break;
      case 4:
        system("cls");
        interfaz->reporteInventario();
        cin.ignore();
        cin.get();
        break;
    }
    system("cls");
  }
  system("cls");
}

void Menu::subMenuUsuarios() {
  int opcion = -1;
  while (opcion != 0) {
    cout << "\tMenu Usuarios" << endl;
    cout << "1. Agregar usuario" << endl;
    cout << "2. Modificar usuario" << endl;
    cout << "3. Eliminar usuario" << endl;
    cout << "4. Reporte de usuarios" << endl;
    cout << "0. Regresar" << endl << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->agregarUsuario();
        break;
      case 2:
        system("cls");
        interfaz->modificarUsuario();
        break;
      case 3:
        system("cls");
        interfaz->eliminarUsuario();
        break;
      case 4:
        system("cls");
        interfaz->reporteUsuarios();
        cin.ignore();
        cin.get();
        break;
    }
    system("cls");
  }
  system("cls");
}

void Menu::subMenuPrestamos() {
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
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->registrarPrestamo();
        break;
      case 2:
        system("cls");
        interfaz->registrarDevolucion();
        break;
      case 3:
        system("cls");
        interfaz->reporteMaterialesPrestados();
        cin.ignore();
        cin.get();
        break;
      case 4:
        system("cls");
        interfaz->reporteMaterialesPorTipo();
        cin.ignore();
        cin.get();
        break;
      case 5:
        system("cls");
        interfaz->reportePrestamosPorUsuario();
        cin.ignore();
        cin.get();
        break;
    }
    system("cls");
  }
  system("cls");
}

void Menu::subMenuArchivos() {
  int opcion = -1;
  while (opcion != 0) {
    cout << "\tMenu Archivos" << endl;
    cout << "1. Guardar datos" << endl;
    cout << "2. Cargar datos" << endl;
    cout << "0. Regresar" << endl << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
      case 1:
        system("cls");
        interfaz->guardarMateriales();
        interfaz->guardarPrestamos();
        interfaz->guardarUsuarios();
        break;
      case 2:
        system("cls");
        interfaz->cargarDatos();
        break;
      default:
        system("cls");
        cout << "Error en guardar o cargar archivos" << endl;
    }
    system("cls");
  }
  system("cls");
}