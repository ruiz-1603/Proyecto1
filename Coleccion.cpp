//
// Created by castr on 7/4/2025.
//

#include "Coleccion.h"

Coleccion::Coleccion() {
  this->inventario = new Biblioteca();
  this->usuarios = new Lista<ListaUsuarios>();
  this->gestorPrestamos = new Lista<GestorPrestamos>();
}
Coleccion::~Coleccion() {
  delete this->inventario;
  delete this->usuarios;
  delete this->gestorPrestamos;
}

void Coleccion::agregarInventario() {
  // preguntar tipo fisico o digital
  string tipo;
  cout << "Ingrese el tipo de material a ingresar (Fisico, Digital): ";
  cin >> tipo;
  for (char& c : tipo) {
    c = tolower(c);
  }

  if (tipo == "fisico") { // si es fisico
    string material;
    cout << "Ingrese el tipo de material a fisico (Libro, Revista, Articulo): ";
    cin >> material;
    for (char& c : material) {
      c = tolower(c);
    }

    if (material == "libro") { // si es libro
      int numCal, numCatalog;
      string titulo, autor, palabrCl, estado, direccion;

      // pedir la info del libro al usuario
      cout << "Ingrese la calificacion del libro: ";
      cin >> numCal;

      cout << "Ingrese el numero del catalogo del libro: ";
      cin >> numCatalog;
      cin.ignore();

      cout << "Ingrese el titulo del libro: ";
      getline(cin, titulo);

      cout << "Ingrese el autor: ";
      getline(cin, autor);

      cout << "Ingrese las palabras clave (separadas por espacios): ";
      getline(cin, palabrCl);

      cout << "Ingrese el estado del libro (buen estado, regular, mal estado): ";
      getline(cin, estado);
      for (char& c : estado) {
        c = tolower(c);
      }
      if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
        cout << "Estado incorrecto" << endl; // exception
      }

      cout << "Ingrese la direccion del libro: ";
      getline(cin, direccion);

      // agregar libro al inventario
      inventario->agregarMaterial(new Libro(numCal, numCatalog, titulo, autor, palabrCl, estado, direccion));

    } else if (material == "revista") { // si es revista
      int numCal, numCatalog, numRev, volRev;
      string titulo, autor, palabrCl, estado, direccion;

      // pedir la info de la revista al usuario
      cout << "Ingrese la calificacion de la revista: ";
      cin >> numCal;

      cout << "Ingrese el numero del catalogo de la revista: ";
      cin >> numCatalog;
      cin.ignore();

      cout << "Ingrese el titulo de la revista: ";
      getline(cin, titulo);

      cout << "Ingrese el autor: ";
      getline(cin, autor);

      cout << "Ingrese las palabras clave (separadas por espacios): ";
      getline(cin, palabrCl);

      cout << "Ingrese el estado de la revista (buen estado, regular, mal estado): ";
      getline(cin, estado);
      for (char& c : estado) {
        c = tolower(c);
      }
      if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
        cout << "Estado incorrecto" << endl; // exception
      }

      cout << "Ingrese la direccion de la revista: ";
      getline(cin, direccion);

      cout << "Ingrese el numero de revista: ";
      cin >> numRev;

      cout << "Ingrese el volumen de la revista: ";
      cin >> numRev;

      // agregar la revista al inventario
      inventario->agregarMaterial(new Revista(numCal, numCatalog, titulo, autor, palabrCl, estado, direccion, numRev, volRev));

    } else if (material == "articulo") { // si es un articulo
      int numCal, numCatalog;
      string titulo, autor, palabrCl, estado, direccion;

      // pedir la info del articulo al usuario
      cout << "Ingrese la calificacion del articulo: ";
      cin >> numCal;

      cout << "Ingrese el numero del catalogo del articulo: ";
      cin >> numCatalog;
      cin.ignore();

      cout << "Ingrese el titulo del articulo: ";
      getline(cin, titulo);

      cout << "Ingrese el autor: ";
      getline(cin, autor);

      cout << "Ingrese las palabras clave (separadas por espacios): ";
      getline(cin, palabrCl);

      cout << "Ingrese el estado del articulo (buen estado, regular, mal estado): ";
      getline(cin, estado);
      for (char& c : estado) {
        c = tolower(c);
      }
      if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
        cout << "Estado incorrecto" << endl; // exception
      }

      cout << "Ingrese la direccion del articulo: ";
      getline(cin, direccion);

      // agregar articulo al inventario
      inventario->agregarMaterial(new Articulo(numCal, numCatalog, titulo, autor, palabrCl, estado, direccion));

    } else {
        cout << "Material desconocido" << endl; // exception
    }

  } else if (tipo == "digital") { // si es digital
    int numCal, numCatalog;
    string titulo, autor, palabrCl, estado, formatoMaterial, estadoStr;
    bool estadoActIn;

    // pedir la info del video al usuario
    cout << "Ingrese la calificacion del video: ";
    cin >> numCal;

    cout << "Ingrese el numero del catalogo del video: ";
    cin >> numCatalog;
    cin.ignore();

    cout << "Ingrese el titulo del video: ";
    getline(cin, titulo);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese las palabras clave (separadas por espacios): ";
    getline(cin, palabrCl);

    cout << "Ingrese el estado del video (buen estado, regular, mal estado): ";
    getline(cin, estado);
    for (char& c : estado) {
      c = tolower(c);
    }
    if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
      cout << "Estado incorrecto" << endl; // exception
    }

    cout << "Ingrese el formato del video (CD, DVD, BluRay, en linea): ";
    getline(cin, formatoMaterial);
    for (char& c : formatoMaterial) {
      c = tolower(c);
    }
    if (formatoMaterial != "en linea") {
      estadoActIn = false;
    } else {
      cout << "Ingrese el estado del acceso al video (Activo, Inactivo): ";
      cin >> estadoStr;
      for (char& c : estadoStr) {
        c = tolower(c);
      }
      if (estadoStr == "activo") {
        estadoActIn = true;
      } else if (estadoStr == "inactivo") {
        estadoActIn = false;
      } else {
        cout << "Estado incorrecto" << endl; // exception?
      }
    }

    inventario->agregarMaterial(new Video(numCal, numCatalog, titulo, autor, palabrCl, estado, "Video", formatoMaterial, estadoActIn));

  } else {
    cout << "Tipo de material desconocido" << endl; // exception?
  }
}








//void Coleccion::modificarMaterial() {
//  // buscar logica
//}
//
//void Coleccion::agregarUsuario() {
//
//}
//void Coleccion::modificarUsuario(Usuario*) {
//  // buscar por id? y preguntar que modificar o que
//}
//
//bool Coleccion::registrarPrestamo() {
//
//}
//bool Coleccion::registrarDevolucion() {}
//
//string Coleccion::reporteInventario() {}
//string Coleccion::reporteUsuarios() {}
//string Coleccion::reporteMaterialesPrestados() {}
//string Coleccion::reportePrestamoPorUsuario() {}