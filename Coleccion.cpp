//
// Created by castr on 7/4/2025.
//

#include "Coleccion.h"

Coleccion::Coleccion() {
  this->inventario = new Biblioteca();
  this->usuarios = new ListaUsuarios();
  this->gestorPrestamos = new GestorPrestamos();
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
void Coleccion::modificarMaterial() {
  int tipo;
  cout << "Ingrese el tipo de material que desea modificar: " << endl;
  cout << "1. Fisico" << endl;
  cout << "2. Digital" << endl;
  cin >> tipo;
  switch (tipo) {
    case 1:
      int material;
      cout << "Ingrese el tipo de material que desea modificar: ";
      cout << "1. Libro" << endl;
      cout << "2. Revista" << endl;
      cout << "3. Articulo" << endl;
      cin >> material;
      switch (material) {
        case 1: {
          string tituloLib;
          inventario->mostrarMaterialesPorTipo("Libro");
          cout << endl;
          cout << "Ingrese el titulo del libro que desea modificar: ";
          cin.ignore();
          getline(cin, tituloLib);
          Materiales* material = inventario->buscarMaterialPorTitulo(tituloLib);
          Libro* libro = dynamic_cast<Libro*>(material);

          if (libro != nullptr) {
            int opcion;
            libro->toString();
            cout << "Que desea modificar del libro: " << endl;
            cout << "1. Numero de calificacion" << endl;
            cout << "2. Numero de catalogo" << endl;
            cout << "3. Titulo" << endl;
            cout << "4. Autor" << endl;
            cout << "5. Palabras clave" << endl;
            cout << "6. Estado" << endl;
            cout << "7. Direccion" << endl;
            cin >> opcion;

            switch (opcion) {
              case 1: {
                int numCalLib;
                cout << "Ingrese el nuevo numero de calificacion del libro: ";
                cin >> numCalLib;
                libro->set_num_calificacion(numCalLib);
                break;
              }
              case 2: {
                int numCatalogLib;
                cout << "Ingrese el nuevo numero de catalogo del libro: ";
                cin >> numCatalogLib;
                libro->set_num_catalogo(numCatalogLib);
                break;
              }
              case 3: {
                string tituloLib;
                cout << "Ingrese el nuevo titulo del libro: ";
                cin.ignore();
                getline(cin, tituloLib);
                libro->set_titulo(tituloLib);
                break;
              }
              case 4: {
                string autorLib;
                cout << "Ingrese el nuevo autor: ";
                cin.ignore();
                getline(cin, autorLib);
                libro->set_autor(autorLib);
                break;
              }
              case 5: {
                string palabrasLib;
                cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
                cin.ignore();
                getline(cin, palabrasLib);
                libro->set_palabras_claves(palabrasLib);
                break;
              }
              case 6: {
                string estadoLib;
                cout << "Ingrese el estado del libro (buen estado, regular, mal estado): ";
                cin.ignore();
                getline(cin, estadoLib);
                libro->set_estado(estadoLib);
                break;
              }
              case 7: {
                string direccionLib;
                cout << "Ingrese la nueva direccion del libro: ";
                cin.ignore();
                getline(cin, direccionLib);
                libro->set_direccion(direccionLib);
                break;
              }
            }
          } else {
            cout << "No se encontro el libro buscado" << endl;
          } break;
        }
        case 2: {
            string tituloRev;
            inventario->mostrarMaterialesPorTipo("Revista");
            cout << endl;
            cout << "Ingrese el titulo del libro que desea modificar: ";
            cin.ignore();
            getline(cin, tituloRev);
            Materiales* materialRev = inventario->buscarMaterialPorTitulo(tituloRev);
            Revista* revista = dynamic_cast<Revista*>(materialRev);

            if (revista != nullptr) {
              int opcion;
              revista->toString();
              cout << "Que desea modificar de la revista: " << endl;
              cout << "1. Numero de calificacion" << endl;
              cout << "2. Numero de catalogo" << endl;
              cout << "3. Titulo" << endl;
              cout << "4. Autor" << endl;
              cout << "5. Palabras clave" << endl;
              cout << "6. Estado" << endl;
              cout << "7. Direccion" << endl;
              cout << "8. Numero de revista" << endl;
              cout << "9. Volumen de la revista" << endl;
              cin >> opcion;

              switch (opcion) {
                case 1: {
                  int numCal;
                  cout << "Ingrese el nuevo numero de calificacion de la revista: ";
                  cin >> numCal;
                  revista->set_num_calificacion(numCal);
                  break;
                }
                case 2: {
                  int numCatalog;
                  cout << "Ingrese el nuevo numero de catalogo de la revista: ";
                  cin >> numCatalog;
                  revista->set_num_catalogo(numCatalog);
                  break;
                }
                case 3: {
                  string titulo;
                  cout << "Ingrese el nuevo titulo de la revista: ";
                  cin.ignore();
                  getline(cin, titulo);
                  revista->set_titulo(titulo);
                  break;
                }
                case 4: {
                  string autorRev;
                  cout << "Ingrese el nuevo autor: ";
                  cin.ignore();
                  getline(cin, autorRev);
                  revista->set_autor(autorRev);
                  break;
                }
                case 5: {
                  string palabras;
                  cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
                  cin.ignore();
                  getline(cin, palabras);
                  revista->set_palabras_claves(palabras);
                  break;
                }
                case 6: {
                  string estado;
                  cout << "Ingrese el estado de la revista (buen estado, regular, mal estado): ";
                  cin.ignore();
                  getline(cin, estado);
                  revista->set_estado(estado);
                  break;
                }
                case 7: {
                  string direccion;
                  cout << "Ingrese la nueva direccion de la revista: ";
                  cin.ignore();
                  getline(cin, direccion);
                  revista->set_direccion(direccion);
                  break;
                }
                case 8: {
                  int numRevista;
                  cout << "Ingrese el nuevo numero de revista: ";
                  cin >> numRevista;
                  revista->set_num_revista(numRevista);
                  break;
                }
                case 9: {
                  int volRev;
                  cout << "Ingrese el nuevo volumen de revista: ";
                  cin >> volRev;
                  revista->set_volumen_revista(volRev);
                  break;
                }
              }
            } else {
              cout << "No se encontro la revista buscada" << endl;
            } break;
          }
        case 3: {
          string tituloArt;
          inventario->mostrarMaterialesPorTipo("Articulo");
          cout << endl;
          cout << "Ingrese el titulo del articulo que desea modificar: ";
          cin.ignore();
          getline(cin, tituloArt);
          Materiales* materialArt = inventario->buscarMaterialPorTitulo(tituloArt);
          Articulo* articulo = dynamic_cast<Articulo*>(materialArt);

          if (articulo != nullptr) {
            int opcion;
            articulo->toString();
            cout << "Que desea modificar de la revista: " << endl;
            cout << "1. Numero de calificacion" << endl;
            cout << "2. Numero de catalogo" << endl;
            cout << "3. Titulo" << endl;
            cout << "4. Autor" << endl;
            cout << "5. Palabras clave" << endl;
            cout << "6. Estado" << endl;
            cout << "7. Direccion" << endl;
            cin >> opcion;

            switch (opcion) {
              case 1: {
                int numCal;
                cout << "Ingrese el nuevo numero de calificacion del articulo: ";
                cin >> numCal;
                articulo->set_num_calificacion(numCal);
                break;
              }
              case 2: {
                int numCatalog;
                cout << "Ingrese el nuevo numero de catalogo del articulo: ";
                cin >> numCatalog;
                articulo->set_num_catalogo(numCatalog);
                break;
              }
              case 3: {
                string titulo;
                cout << "Ingrese el nuevo titulo del articulo: ";
                cin.ignore();
                getline(cin, titulo);
                articulo->set_titulo(titulo);
                break;
              }
              case 4: {
                string autor;
                cout << "Ingrese el nuevo autor: ";
                cin.ignore();
                getline(cin, autor);
                articulo->set_autor(autor);
                break;
              }
              case 5: {
                string palabras;
                cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
                cin.ignore();
                getline(cin, palabras);
                articulo->set_palabras_claves(palabras);
                break;
              }
              case 6: {
                string estado;
                cout << "Ingrese el estado del articulo (buen estado, regular, mal estado): ";
                cin.ignore();
                getline(cin, estado);
                articulo->set_estado(estado);
                break;
              }
              case 7: {
                string direccion;
                cout << "Ingrese la nueva direccion del articulo: ";
                cin.ignore();
                getline(cin, direccion);
                articulo->set_direccion(direccion);
                break;
              }
            }
          } else {
            cout << "No se encontro el articulo buscado" << endl;
          } break;
        } break;
      }
    case 2:
      string tituloVid;
      inventario->mostrarMaterialesPorTipo("Video");
      cout << endl;
      cout << "Ingrese el titulo del video que desea modificar: ";
      cin.ignore();
      getline(cin, tituloVid);
      Materiales* materialVid = inventario->buscarMaterialPorTitulo(tituloVid);
      Video* video = dynamic_cast<Video*>(materialVid);

      if (video != nullptr) {
        int opcion;
        video->toString();
        cout << "Que desea modificar del video: " << endl;
        cout << "1. Numero de calificacion" << endl;
        cout << "2. Numero de catalogo" << endl;
        cout << "3. Titulo" << endl;
        cout << "4. Autor" << endl;
        cout << "5. Palabras clave" << endl;
        cout << "6. Estado (buen estado, regular, mal estado)" << endl;
        cout << "7. Tipo de material" << endl;
        cout << "8. Formato" << endl;
        cout << "9. Estado (Activo, Inactivo)" << endl;
        cin >> opcion;

        switch (opcion) {
          case 1: {
            int numCal;
            cout << "Ingrese el nuevo numero de calificacion del video: ";
            cin >> numCal;
            video->set_num_calificacion(numCal);
            break;
          }
          case 2: {
            int numCatalog;
            cout << "Ingrese el nuevo numero de catalogo del video: ";
            cin >> numCatalog;
            video->set_num_catalogo(numCatalog);
            break;
          }
          case 3: {
            string titulo;
            cout << "Ingrese el nuevo titulo del video: ";
            cin.ignore();
            getline(cin, titulo);
            video->set_titulo(titulo);
            break;
          }
          case 4: {
            string autor;
            cout << "Ingrese el nuevo autor: ";
            cin.ignore();
            getline(cin, autor);
            video->set_autor(autor);
            break;
          }
          case 5: {
            string palabras;
            cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
            cin.ignore();
            getline(cin, palabras);
            video->set_palabras_claves(palabras);
            break;
          }
          case 6: {
            string estado;
            cout << "Ingrese el estado del video (buen estado, regular, mal estado): ";
            cin.ignore();
            getline(cin, estado);
            video->set_estado(estado);
            break;
          }
          case 7: {
            string tipoMaterial;
            cout << "Ingrese el tipo de material del video: ";
            cin.ignore();
            getline(cin, tipoMaterial);
            video->set_tipo_material(tipoMaterial);
            break;
          }
          case 8: {
            string formato;
            cout << "Ingrese el formato del video (CD, DVD, BluRay): ";
            cin.ignore();
            getline(cin, formato);
            video->set_formato_material(formato);
            break;
          }
        }
      } else {
        cout << "No se encontro el video buscado" << endl;
      }
  }
}

void Coleccion::eliminarMaterial() {
  int tipo;
  cout << "Ingrese el tipo de material que desea eliminar: ";
  cout << "1. Fisico" << endl;
  cout << "2. Digital" << endl;
  cin >> tipo;

  switch (tipo) {
    case 1: {
      cout << "Materiales fisicos:" << endl;
      inventario->mostrarMaterialesPorTipo("Fisico");
      cout << endl;
      string titulo;
      cout << "Ingrese el titulo del material fisico que desea eliminar: ";
      cin.ignore();
      getline(cin, titulo);
      inventario->eliminarMaterialPorTitulo(titulo);
      break;
    }
    case 2: {
      cout << "Materiales digitales:" << endl;
      inventario->mostrarMaterialesPorTipo("Digital");
      cout << endl;
      string titulo;
      cout << "Ingrese el titulo del material digital que desea eliminar: ";
      cin.ignore();
      getline(cin, titulo);
      inventario->eliminarMaterialPorTitulo(titulo);
      break;
    }
  }
}


void Coleccion::agregarUsuario() {
  int id;
  string nom;
  cout << "Ingrese el id del usuario: ";
  cin >> id;
  cin.ignore();

  cout << "Ingrese el nombre completo del usuario: ";
  getline(cin, nom);
  usuarios->agregarUsuario(new Usuario(id, nom, true));
}
void Coleccion::modificarUsuario() {
  int id;
  cout << "Ingrese el id del usuario que desea modificar: ";
  cin >> id;
  Usuario* usuario = usuarios->buscarUsuarioPorId(id);

  if (usuario != nullptr) {
    int opcion;
    cout << "Usuario encontrado: " << endl;
    cout << usuario->toString() << endl;
    cout << "Que desea modificar del usuario?" << endl;
    cout << "\t1. ID\n" << endl;
    cout << "\t2. Nombre\n" << endl;
    cout << "\t3. Estado\n" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1: {
        int id;
        cout << "Ingrese el nuevo ID del usuario: ";
        cin >> id;
        usuario->set_id(id);
        break;
      }
      case 2: {
        string nom;
        cout << "Ingrese el nuevo nombre del usuario: ";
        cin.ignore();
        getline(cin, nom);
        usuario->set_nombre_completo(nom);
        break;
      }
      case 3: {
        int eleccion;
        bool estado;
        cout << "Ingrese el estado del usuario (1. Activo 2. Inactivo): ";
        cin >> eleccion;
        if (eleccion == 1) {
          estado = true;
        } else if (eleccion == 2) {
          estado = false;
        } else {
          cout << "Estado incorrecto" << endl;
        }
        usuario->set_estado(estado);
        break;
      }
    }
  } else {
    cout << "Usuario no encontrado" << endl;
  }
}

void Coleccion::eliminarUsuario() {
  int id;
  cout << "Usuarios: " << endl;
  usuarios->mostrarUsuarios();
  cout << "Ingrese el id del usuario que desea eliminar: ";
  cin >> id;
  usuarios->eliminarUsuarioPorId(id);
}


void Coleccion::mostrarDisponiblesPorTipo(string tipoBuscado) {
  Nodo<Materiales>* nodo = inventario->getBiblioteca()->obtenerPrimero();

  while (nodo != nullptr) {
    Materiales* material = nodo->getDato();

    // Verificar si el material no está prestado y si su tipo coincide con el buscado
    bool estaPrestado = false;
    Nodo<Prestamo>* prestamoNodo = gestorPrestamos->getPrestamos()->obtenerPrimero();
    while (prestamoNodo != nullptr) {
      Prestamo* prestamo = prestamoNodo->getDato();
      if (prestamo->getMaterial() == material) {
        estaPrestado = true;
        break;
      }
      prestamoNodo = prestamoNodo->getSiguiente();
    }

    if (!estaPrestado && material->getTipo() == tipoBuscado) {
      cout << material->toString() << endl;
    }

    nodo = nodo->getSiguiente();
  }
}

void Coleccion::registrarPrestamo() {
  int idUsuario;
  string formatoMaterial;
  cout << "Ingrese el id del usuario que solicita el prestamo: ";
  cin >> idUsuario;
  Usuario* usuario = usuarios->buscarUsuarioPorId(idUsuario);

  cout << "Ingrese el formato del material que desea (Fisico, Digital): ";
  cin >> formatoMaterial;
  for (char& c : formatoMaterial) {
    c = tolower(c);
  }
  if (formatoMaterial == "fisico") {
    int opcion;
    cout << "Ingrese el tipo de material: ";
    cout << "1. Libro" << endl;
    cout << "2. Revista" << endl;
    cout << "3. Articulo" << endl;
    cin >> opcion;
    switch (opcion) {
      case 1: {
        string nom;
        int idPrestamo;

        cout << "Libros disponibles: " << endl;
        mostrarDisponiblesPorTipo("Libro");
        cout << endl;
        cout << "Ingrese el titulo del libro que desea solicitar: ";
        cin.ignore();
        getline(cin, nom);
        Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);

        cout << "Ingrese un id para el prestamo: ";
        cin >> idPrestamo;

        // obtener fecha del prestamo
        time_t fecha_hoy = time(nullptr);
        tm* fechaFormato = localtime(&fecha_hoy);
        stringstream ssfechaPrestamo;
        ssfechaPrestamo << put_time(fechaFormato, "%d/%m/%Y");
        string fPrestamo = ssfechaPrestamo.str();

        // obtener fecha de vencimiento
        time_t fecha_hoy2 = time(nullptr);
        int diasPrestamos = matSolicitado->diasPrestamo() * 86400;
        fecha_hoy2 += diasPrestamos;
        tm* fechaFormato2 = localtime(&fecha_hoy2);
        stringstream ssfVencimiento;
        ssfVencimiento << put_time(fechaFormato2, "%d/%m/%Y");
        string fVencimiento = ssfVencimiento.str();

        gestorPrestamos->agregarPrestamo(new Prestamo(idPrestamo, usuario, matSolicitado, fPrestamo, fVencimiento));
        cout << "Su prestamo ha sido registrado!\nSu prestamo vence el " << fVencimiento << endl;
      }
      case 2: {
        string nom;
        int idPrestamo;

        cout << "Revistas disponibles: " << endl;
        mostrarDisponiblesPorTipo("Revista");
        cout << endl;
        cout << "Ingrese el titulo de la revista que desea solicitar: ";
        cin.ignore();
        getline(cin, nom);
        Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);

        cout << "Ingrese un id para el prestamo: ";
        cin >> idPrestamo;

        // obtener fecha del prestamo
        time_t fecha_hoy = time(nullptr);
        tm* fechaFormato = localtime(&fecha_hoy);
        stringstream ssfechaPrestamo;
        ssfechaPrestamo << put_time(fechaFormato, "%d/%m/%Y");
        string fPrestamo = ssfechaPrestamo.str();

        // obtener fecha de vencimiento
        time_t fecha_hoy2 = time(nullptr);
        int diasPrestamos = matSolicitado->diasPrestamo() * 86400;
        fecha_hoy2 += diasPrestamos;
        tm* fechaFormato2 = localtime(&fecha_hoy2);
        stringstream ssfVencimiento;
        ssfVencimiento << put_time(fechaFormato2, "%d/%m/%Y");
        string fVencimiento = ssfVencimiento.str();

        gestorPrestamos->agregarPrestamo(new Prestamo(idPrestamo, usuario, matSolicitado, fPrestamo, fVencimiento));
        cout << "Su prestamo ha sido registrado!\nSu prestamo vence el " << fVencimiento << endl;
      }
      case 3: {
        string nom;
        int idPrestamo;

        cout << "Articulos disponibles: " << endl;
        mostrarDisponiblesPorTipo("Articulo");
        cout << endl;
        cout << "Ingrese el titulo del articulo que desea solicitar: ";
        cin.ignore();
        getline(cin, nom);
        Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);

        cout << "Ingrese un id para el prestamo: ";
        cin >> idPrestamo;

        // obtener fecha del prestamo
        time_t fecha_hoy = time(nullptr);
        tm* fechaFormato = localtime(&fecha_hoy);
        stringstream ssfechaPrestamo;
        ssfechaPrestamo << put_time(fechaFormato, "%d/%m/%Y");
        string fPrestamo = ssfechaPrestamo.str();

        // obtener fecha de vencimiento
        time_t fecha_hoy2 = time(nullptr);
        int diasPrestamos = matSolicitado->diasPrestamo() * 86400;
        fecha_hoy2 += diasPrestamos;
        tm* fechaFormato2 = localtime(&fecha_hoy2);
        stringstream ssfVencimiento;
        ssfVencimiento << put_time(fechaFormato2, "%d/%m/%Y");
        string fVencimiento = ssfVencimiento.str();

        gestorPrestamos->agregarPrestamo(new Prestamo(idPrestamo, usuario, matSolicitado, fPrestamo, fVencimiento));
        cout << "Su prestamo ha sido registrado!\nSu prestamo vence el " << fVencimiento << endl;
      }
    }
  } else if (formatoMaterial == "digital") {
    string nom;
    int idPrestamo;

    cout << "Libros disponibles: " << endl;
    mostrarDisponiblesPorTipo("Video");
    cout << endl;
    cout << "Ingrese el titulo del video que desea solicitar: ";
    cin.ignore();
    getline(cin, nom);
    Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);

    cout << "Ingrese un id para el prestamo: ";
    cin >> idPrestamo;

    // obtener fecha del prestamo
    time_t fecha_hoy = time(nullptr);
    tm* fechaFormato = localtime(&fecha_hoy);
    stringstream ssfechaPrestamo;
    ssfechaPrestamo << put_time(fechaFormato, "%d/%m/%Y");
    string fPrestamo = ssfechaPrestamo.str();

    // obtener fecha de vencimiento
    time_t fecha_hoy2 = time(nullptr);
    int diasPrestamos = matSolicitado->diasPrestamo() * 86400;
    fecha_hoy2 += diasPrestamos;
    tm* fechaFormato2 = localtime(&fecha_hoy2);
    stringstream ssfVencimiento;
    ssfVencimiento << put_time(fechaFormato2, "%d/%m/%Y");
    string fVencimiento = ssfVencimiento.str();

    gestorPrestamos->agregarPrestamo(new Prestamo(idPrestamo, usuario, matSolicitado, fPrestamo, fVencimiento));
    cout << "Su prestamo ha sido registrado!\nSu prestamo vence el " << fVencimiento << endl;

  } else {
    cout << "Tipo de material incorrecto" << endl; // exception
  }
}
void Coleccion::registrarDevolucion() {
  int id;
  gestorPrestamos->mostrarPrestamosGeneral();
  cout << endl;
  cout << "Ingrese el ID del prestamo que desea regresar: ";
  cin >> id;
  gestorPrestamos->eliminarPrestamo(id);
}

void Coleccion::reporteInventario() {
  cout << "Inventario: " << endl << endl;
  inventario->mostrarMateriales();
}
void Coleccion::reporteUsuarios() { usuarios->mostrarUsuarios(); }

void Coleccion::reporteMaterialesPrestados() {
  cout << "Materiales prestados: " << endl;
  gestorPrestamos->mostrarPrestamosGeneral();
  cout << endl;
}

void Coleccion::reporteMaterialesPorTipo() {
  int tipo;
  cout << "\tIngrese el tipo de material:" << endl;
  cout << "1. Libros" << endl;
  cout << "2. Revistas" << endl;
  cout << "3. Articulos" << endl;
  cout << "4. Videos" << endl;
  cin >> tipo;

  switch (tipo) {
    case 1:
      system("cls");
      inventario->mostrarMaterialesPorTipo("Libro");
      break;
    case 2:
      system("cls");
      inventario->mostrarMaterialesPorTipo("Revista");
      break;
    case 3:
      system("cls");
      inventario->mostrarMaterialesPorTipo("Articulo");
      break;
    case 4:
      system("cls");
      inventario->mostrarMaterialesPorTipo("Video");
      break;
  }
}

void Coleccion::reportePrestamosPorUsuario() {
  int id;
  cout << "Ingrese el ID del usuario: ";
  cin >> id;
  Usuario* usuario = usuarios->buscarUsuarioPorId(id);
  cout << endl;
  gestorPrestamos->mostrarPrestamosPorUsuario(usuario);
}