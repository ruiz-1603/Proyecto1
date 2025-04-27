#include "Coleccion.h"
#include "Limpieza.h"

#include "GestorArchivos.cpp"

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
try{
  int tipo;
  cout << "Ingrese el tipo de material a ingresar: " << endl;
  cout << "1. Libro" << endl;
  cout << "2. Revista" << endl;
  cout << "3. Articulo" << endl;
  cout << "4. Video" << endl;
  cin >> tipo;
  if (cin.fail()) {
    Limpieza::limpiarBuffer();
    throw Exception("Entrada invalida de tipo de material.");
  }

  switch (tipo) {
    case 1:
      agregarLibro();
    break;
    case 2:
      agregarRevista();
    break;
    case 3:
      agregarArticulo();
    break;
    case 4:
      agregarVideo();
    break;
    default:
      cout << "Tipo de material desconocido" << endl;
  }
}catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::agregarLibro() {
  int numCal, numCatalog;
  string titulo, autor, palabrCl, estado,direccion;

  try {
    cout << "Ingrese la calificacion del libro: ";
    cin >> numCal;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para calificacion.");
      Limpieza::pausar();
    }

    cout << "Ingrese el numero del catalogo del libro: ";
    cin >> numCatalog;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invualida para nmero de catalogo.");
      Limpieza::pausar();
    }

    Limpieza::limpiarBuffer(); // Limpiar antes de getline

    cout << "Ingrese el titulo del libro: ";
    getline(cin, titulo);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese las palabras clave (separadas por espacios): ";
    getline(cin, palabrCl);

    cout << "Ingrese el estado del libro (Buen estado, regular, mal estado): ";
    getline(cin, estado);

    // Convertir a minúsculas
    for (char& c : estado) {
      c = tolower(c);
    }

    if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
      throw Exception("Estado invalido. Debe ser: buen estado, regular o mal estado.");
      Limpieza::pausar();
    }

    cout << "Ingrese la direccion del libro: ";
    getline(cin, direccion);

    // agregar libro al inventario
    inventario->agregarMaterial(new Libro(numCal, numCatalog, titulo, autor, estado, palabrCl, direccion));

    cout << "Libro agregado exitosamente.\n";
    Limpieza::pausar();

  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }

}
void Coleccion::agregarRevista() {
  int numCal, numCatalog, numRev, volRev;
  string titulo, autor, palabrCl, estado, direccion;

  try {
    cout << "Ingrese la calificacion de la revista: ";
    cin >> numCal;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para calificacion.");
      Limpieza::pausar();
    }

    cout << "Ingrese el numero del catalogo de la revista: ";
    cin >> numCatalog;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para numero de catalogo.");
      Limpieza::pausar();
    }

    Limpieza::limpiarBuffer();

    cout << "Ingrese el titulo de la revista: ";
    getline(cin, titulo);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese las palabras clave (separadas por espacios): ";
    getline(cin, palabrCl);

    cout << "Ingrese el estado de la revista (buen estado, regular, mal estado): ";
    getline(cin, estado);
    for (char& c : estado) c = tolower(c);

    if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
      throw Exception("Estado invalido. Debe ser: buen estado, regular o mal estado.");
      Limpieza::pausar();
    }

    cout << "Ingrese la direccion de la revista: ";
    getline(cin, direccion);

    cout << "Ingrese el numero de revista: ";
    cin >> numRev;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Numero de revista invalido.");
      Limpieza::pausar();
    }

    cout << "Ingrese el volumen de la revista: ";
    cin >> volRev;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Volumen de revista invalido.");
      Limpieza::pausar();
    }

    inventario->agregarMaterial(new Revista(numCal, numCatalog, titulo, autor, estado,palabrCl, direccion, numRev, volRev));
    cout << "Revista agregada exitosamente.\n";
    Limpieza::pausar();

  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::agregarArticulo() {
  int numCal, numCatalog;
  string titulo, autor, palabrCl, estado, direccion;

  try {
    cout << "Ingrese la calificacion del articulo: ";
    cin >> numCal;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para calificacion.");
      Limpieza::pausar();
    }

    cout << "Ingrese el numero del catalogo del articulo: ";
    cin >> numCatalog;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para número de catalogo.");
      Limpieza::pausar();
    }

    Limpieza::limpiarBuffer();

    cout << "Ingrese el titulo del articulo: ";
    getline(cin, titulo);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese las palabras clave (separadas por espacios): ";
    getline(cin, palabrCl);

    cout << "Ingrese el estado del articulo (buen estado, regular, mal estado): ";
    getline(cin, estado);
    for (char& c : estado) c = tolower(c);

    if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
      throw Exception("Estado invalido. Debe ser: buen estado, regular o mal estado.");
      Limpieza::pausar();
    }

    cout << "Ingrese la direccion del articulo: ";
    getline(cin, direccion);

    inventario->agregarMaterial(new Articulo(numCal, numCatalog, titulo, autor, estado,palabrCl, direccion));
    cout << "Articulo agregado exitosamente.\n";
    Limpieza::pausar();

  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::agregarVideo() {
  int numCal, numCatalog;
  string titulo, autor, palabrCl, estado, formatoMaterial, estadoStr;
  bool estadoActIn = false;

  try {
    cout << "Ingrese la calificacion del video: ";
    cin >> numCal;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para calificacion.");
      Limpieza::pausar();
    }

    cout << "Ingrese el numero del catalogo del video: ";
    cin >> numCatalog;
    if (cin.fail()) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para numero de catalogo.");
      Limpieza::pausar();
    }

    Limpieza::limpiarBuffer();

    cout << "Ingrese el titulo del video: ";
    getline(cin, titulo);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese las palabras clave (separadas por espacios): ";
    getline(cin, palabrCl);

    cout << "Ingrese el estado del video (Buen estado, regular, mal estado): ";
    getline(cin, estado);
    for (char& c : estado) c = tolower(c);

    if (estado != "buen estado" && estado != "mal estado" && estado != "regular") {
      throw Exception("Estado invalido. Debe ser: Buen estado, regular o mal estado.");
      Limpieza::pausar();
    }

    cout << "Ingrese el formato del video (CD, DVD, BluRay, En linea): ";
    getline(cin, formatoMaterial);
    for (char& c : formatoMaterial) c = tolower(c);

    if (formatoMaterial == "en linea") {
      cout << "Ingrese el estado del acceso al video (ctivo, inactivo): ";
      cin >> estadoStr;
      for (char& c : estadoStr) c = tolower(c);
      if (estadoStr == "activo") {
        estadoActIn = true;
      } else if (estadoStr == "inactivo") {
        estadoActIn = false;
      } else {
        Limpieza::limpiarBuffer();
        throw Exception("Estado de acceso invalido.");
        Limpieza::pausar();
      }
    }

    inventario->agregarMaterial(new Video(numCal, numCatalog, titulo, autor,palabrCl,estado, "Video", formatoMaterial, estadoActIn));
    cout << "Video agregado exitosamente.\n";
    Limpieza::pausar();

  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::modificarMaterial() {
try{
  int material;
  cout << "Ingrese el tipo de material que desea modificar: " << endl;
  cout << "1. Libro" << endl;
  cout << "2. Revista" << endl;
  cout << "3. Articulo" << endl;
  cout << "4. Video" << endl;
  cin >> material;
  if (cin.fail()) {
    Limpieza::limpiarBuffer();
    throw Exception("Entrada invalida para el tipo material.");
  }
  switch (material) {
    case 1:
      modificarLibro();
      break;
    case 2:
      modificarRevista();
      break;
    case 3:
      modificarArticulo();
      break;
    case 4:
      modificarVideo();
      break;
  }
}catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::modificarLibro() {
  try{
  string tituloLib;
  inventario->mostrarMaterialesPorTipo("Libro");
  cout << endl;
  cout << "Ingrese el titulo del libro que desea modificar: ";
    Limpieza::limpiarBuffer();
  getline(cin, tituloLib);
  Materiales* material = inventario->buscarMaterialPorTitulo(tituloLib);
  Libro* libro = dynamic_cast<Libro*>(material);

  if (!libro) {
      throw Exception("No se encontro el libro buscado.");
      Limpieza::pausar();
  }
    int opcion;
    cout << libro->toString();
    cout << "Que desea modificar del libro: " << endl;
    cout << "1. Numero de calificacion" << endl;
    cout << "2. Numero de catalogo" << endl;
    cout << "3. Titulo" << endl;
    cout << "4. Autor" << endl;
    cout << "5. Palabras clave" << endl;
    cout << "6. Estado" << endl;
    cout << "7. Direccion" << endl;
    cout << "Ingrese una opcion: ";
    if (!(cin >> opcion)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida, se esperaba un numero.");
        Limpieza::pausar();
    }
  
    Limpieza::limpiarBuffer();


    switch (opcion) {
      case 1: {
        int numCalLib;
        cout << "Ingrese el nuevo numero de calificacion del libro: ";
        if (!(cin >> numCalLib)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida.");
            Limpieza::pausar();
        }
        
        libro->set_num_calificacion(numCalLib);
        break;
      }
      case 2: {
        int numCatalogLib;
        cout << "Ingrese el nuevo numero de catalogo del libro: ";
        if (!(cin >> numCatalogLib)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida.");
            Limpieza::pausar();
        }
        libro->set_num_catalogo(numCatalogLib);
        break;
      }
      case 3: {
        string tituloLib;
        cout << "Ingrese el nuevo titulo del libro: ";
        getline(cin, tituloLib);
        libro->set_titulo(tituloLib);
        break;
      }
      case 4: {
        string autorLib;
        cout << "Ingrese el nuevo autor: ";
        getline(cin, autorLib);
        libro->set_autor(autorLib);
        break;
      }
      case 5: {
        string palabrasLib;
        cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
        getline(cin, palabrasLib);
        libro->set_palabras_claves(palabrasLib);
        break;
      }
      case 6: {
        string estadoLib;
        cout << "Ingrese el estado del libro (Buen estado, regular, mal estado): ";
        getline(cin, estadoLib);
        libro->set_estado(estadoLib);
        break;
      }
      case 7: {
        string direccionLib;
        cout << "Ingrese la nueva direccion del libro: ";
        getline(cin, direccionLib);
        libro->set_direccion(direccionLib);
        break;
      }
      default:
        throw Exception("Opcion no valida.");
        Limpieza::pausar();
    }
    cout << "Libro modificado correctamente." << endl;

  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::modificarRevista() {
  try {
    string tituloRev;
    inventario->mostrarMaterialesPorTipo("Revista");
    cout << endl;
    cout << "Ingrese el titulo de la revista que desea modificar: ";
    Limpieza::limpiarBuffer();
    getline(cin, tituloRev);
    Materiales* material = inventario->buscarMaterialPorTitulo(tituloRev);
    Revista* revista = dynamic_cast<Revista*>(material);

    if (!revista) {
        throw Exception("No se encontro la revista buscada.");
        Limpieza::pausar();
    }
        int opcion;
        cout << revista->toString();
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
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida, se esperaba un numero.");
            Limpieza::pausar();
        }
      Limpieza::limpiarBuffer();
      switch (opcion) {
        case 1: {
            int numCal;
            cout << "Ingrese el nuevo numero de calificacion de la revista: ";
            if (!(cin >> numCal)) {
              Limpieza::limpiarBuffer();
                throw Exception("Entrada invalida para numero de calificacion."); 
                Limpieza::pausar();
            }
            revista->set_num_calificacion(numCal);
            break;
        }
        case 2: {
            int numCatalog;
            cout << "Ingrese el nuevo numero de catalogo de la revista: ";
            if (!(cin >> numCatalog)) {
              Limpieza::limpiarBuffer();
                throw Exception("Entrada invalida para numero de catalogo."); 
                Limpieza::pausar();
            }
            revista->set_num_catalogo(numCatalog);
            break;
        }
        case 3: {
            string titulo;
            cout << "Ingrese el nuevo titulo de la revista: ";
            getline(cin, titulo);
            revista->set_titulo(titulo);
            break;
        }
        case 4: {
            string autorRev;
            cout << "Ingrese el nuevo autor: ";
            getline(cin, autorRev);
            revista->set_autor(autorRev);
            break;
        }
        case 5: {
            string palabras;
            cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
            getline(cin, palabras);
            revista->set_palabras_claves(palabras);
            break;
        }
        case 6: {
            string estado;
            cout << "Ingrese el estado de la revista (Buen estado, regular, mal estado): ";
            getline(cin, estado);

          if (estado != "buen estado" && estado != "regular" && estado != "mal estado") {
            throw Exception("Estado invalido. Debe ser: Buen estado, regular o mal estado.");
            Limpieza::pausar();
          }
          revista->set_estado(estado);
          break;
        }
        case 7: {
            string direccion;
            cout << "Ingrese la nueva direccion de la revista: ";
            getline(cin, direccion);
            revista->set_direccion(direccion);
            break;
        }
        case 8: {
            int numRevista;
            cout << "Ingrese el nuevo numero de revista: ";
            if (!(cin >> numRevista)) {
              Limpieza::limpiarBuffer();
                throw Exception("Entrada invalida para numero de revista.");
                Limpieza::pausar();
            }
            revista->set_num_revista(numRevista);
            break;
        }
        case 9: {
            int volRev;
            cout << "Ingrese el nuevo volumen de revista: ";
            if (!(cin >> volRev)) {
              Limpieza::limpiarBuffer();
                throw Exception("Entrada invalida para numero de revista.");
                Limpieza::pausar();
            }
            revista->set_volumen_revista(volRev);
            break;
        }
        default:
          throw Exception("Opcion no valida.");
          Limpieza::pausar();
      }
    cout << "Revista modificada correctamente." << endl;
} catch (const Exception& e) {
  cerr << "Error: " << e.what() << endl;
  Limpieza::pausar();
  }
}

void Coleccion::modificarArticulo() {
  try{
  string tituloArt;
  inventario->mostrarMaterialesPorTipo("Articulo");
  cout << endl;
  cout << "Ingrese el titulo del articulo que desea modificar: ";
    Limpieza::limpiarBuffer();
  getline(cin, tituloArt);
  Materiales *materialArt = inventario->buscarMaterialPorTitulo(tituloArt);
  Articulo *articulo = dynamic_cast<Articulo *>(materialArt);

  if (!articulo) {
      throw Exception("No se encontro el artículo buscado.");
      Limpieza::pausar();
  }
    int opcion;
    cout << articulo->toString();
    cout << "Que desea modificar del articulo: " << endl;
    cout << "1. Numero de calificacion" << endl;
    cout << "2. Numero de catalogo" << endl;
    cout << "3. Titulo" << endl;
    cout << "4. Autor" << endl;
    cout << "5. Palabras clave" << endl;
    cout << "6. Estado" << endl;
    cout << "7. Direccion" << endl;
    cout << "Ingrese una opcion: ";
    if (!(cin >> opcion)) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida, se esperaba un numero.");
    }

    switch (opcion) {
      case 1: {
        int numCal;
        cout << "Ingrese el nuevo numero de calificacion del articulo: ";
        if (!(cin >> numCal)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida.");
            Limpieza::pausar();
        }
        articulo->set_num_calificacion(numCal);
        break;
      }
      case 2: {
        int numCatalog;
        cout << "Ingrese el nuevo numero de catalogo del articulo: ";
        if (!(cin >> numCatalog)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida.");
            Limpieza::pausar();
        }
        articulo->set_num_catalogo(numCatalog);
        break;
      }
      case 3: {
        string titulo;
        cout << "Ingrese el nuevo titulo del articulo: ";
        getline(cin, titulo);
        articulo->set_titulo(titulo);
        break;
      }
      case 4: {
        string autor;
        cout << "Ingrese el nuevo autor: ";
        getline(cin, autor);
        articulo->set_autor(autor);
        break;
      }
      case 5: {
        string palabras;
        cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
        getline(cin, palabras);
        articulo->set_palabras_claves(palabras);
        break;
      }
      case 6: {
        string estado;
        cout << "Ingrese el estado del articulo (buen estado, regular, mal estado): ";
        getline(cin, estado);
        if (estado != "buen estado" && estado != "regular" && estado != "mal estado") {
          throw Exception("Estado invalido. Debe ser: buen estado, regular o mal estado.");
          Limpieza::pausar();
        }
        articulo->set_estado(estado);
        break;
      }
      case 7: {
        string direccion;
        cout << "Ingrese la nueva direccion del articulo: ";
        getline(cin, direccion);
        articulo->set_direccion(direccion);
        break;
      }
      default:
        throw Exception("Opcion no valida.");
        Limpieza::pausar();
    }
    cout << "Articulo modificado correctamente." << endl;
  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::modificarVideo() {
  try{
    string tituloVid;
    inventario->mostrarMaterialesPorTipo("Video");
    cout << endl;
    cout << "Ingrese el titulo del video que desea modificar: ";
    Limpieza::limpiarBuffer();
    getline(cin, tituloVid);
    Materiales *materialVid = inventario->buscarMaterialPorTitulo(tituloVid);
    Video *video = dynamic_cast<Video *>(materialVid);

    if (!video) {
        throw Exception("No se encontro el video buscado.\n");
        Limpieza::pausar();
    }

        int opcion;
        cout << video->toString();
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
        cout << "Ingrese una opcion: ";
        if (!(cin >> opcion)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida.");
            Limpieza::pausar();
        }
        Limpieza::limpiarBuffer();

        switch (opcion) {
            case 1: {
                int numCal;
                cout << "Ingrese el nuevo numero de calificacion del video: ";
                if (!(cin >> numCal)) {
                  Limpieza::limpiarBuffer();
                    throw Exception("Entrada invalida.");
                    Limpieza::pausar();
                }
                video->set_num_calificacion(numCal);
                break;
            }
            case 2: {
                int numCatalog;
                cout << "Ingrese el nuevo numero de catalogo del video: ";
                if (!(cin >> numCatalog)) {
                  Limpieza::limpiarBuffer();
                    throw Exception("Entrada invalida.");
                    Limpieza::pausar();
                }
                video->set_num_catalogo(numCatalog);
                break;
            }
            case 3: {
                string titulo;
                cout << "Ingrese el nuevo titulo del video: ";
                getline(cin, titulo);
                video->set_titulo(titulo);
                break;
            }
            case 4: {
                string autor;
                cout << "Ingrese el nuevo autor: ";
                getline(cin, autor);
                video->set_autor(autor);
                break;
            }
            case 5: {
                string palabras;
                cout << "Ingrese las nuevas palabras clave separadas por un espacio: ";
                getline(cin, palabras);
                video->set_palabras_claves(palabras);
                break;
            }
            case 6: {
                string estado;
                cout << "Ingrese el estado del video (Buen estado, regular, mal estado): ";
                getline(cin, estado);
                video->set_estado(estado);
            break;
            }
            case 7: {
                string tipoMaterial;
                cout << "Ingrese el tipo de material del video: ";
                getline(cin, tipoMaterial);
                video->set_tipo_material(tipoMaterial);
                break;
            }
            case 8: {
                string formato;
                cout << "Ingrese el formato del video (CD, DVD, BluRay): ";
                getline(cin, formato);
                video->set_formato_material(formato);
                break;
            }
          default:
            throw Exception("Opcion no valida.");
            Limpieza::pausar();
        }
    cout << "Video modificado correctamente." << endl;
  } catch (const Exception& e) {
  cerr << "Error: " << e.what() << endl;
  Limpieza::pausar();
  }
}

void Coleccion::eliminarMaterial() {
  try{
  int tipo;
  cout << "Ingrese el tipo de material que desea eliminar: " << endl;
  cout << "1. Fisico" << endl;
  cout << "2. Digital" << endl;
  if (!(cin >> tipo)) {
    Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida. se esperaba un numero.");
      Limpieza::pausar();
  }

  switch (tipo) {
    case 1: {
      cout << "Materiales fisicos:" << endl;
      inventario->mostrarMaterialesPorTipo("Fisico");
      cout << endl;
      string titulo;
      cout << "Ingrese el titulo del material fisico que desea eliminar: ";
      Limpieza::limpiarBuffer();
      getline(cin, titulo);
      inventario->eliminarMaterialPorTitulo(titulo);
      cout<<"Material borrado exitosamente!\n";
      break;
    }
    case 2: {
      cout << "Materiales digitales:" << endl;
      inventario->mostrarMaterialesPorTipo("Digital");
      cout << endl;
      string titulo;
      cout << "Ingrese el titulo del material digital que desea eliminar: ";
      Limpieza::limpiarBuffer();
      getline(cin, titulo);
      inventario->eliminarMaterialPorTitulo(titulo);
      cout<<"Material borrado exitosamente!\n";
      break;
    }
    default:
      throw Exception("Tipo de material no valido.");
      Limpieza::pausar();
  }
} catch (const Exception& e) {
  cerr << "Error: " << e.what() << endl;
  Limpieza::pausar();
  }
}

void Coleccion::agregarUsuario() {
  try{
  int id;
  string nom;
  cout << "Ingrese el id del usuario: ";
  if (!(cin >> id)) {
    Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para id.");
      Limpieza::pausar();
  }
  Limpieza::limpiarBuffer();
    if (usuarios->buscarUsuarioPorId(id) != nullptr) {
      throw Exception("Ya existe un usuario con este ID");
    }

  cout << "Ingrese el nombre completo del usuario: ";
  getline(cin, nom);
  usuarios->agregarUsuario(new Usuario(id, nom, true));
  cout << "Usuario agregado correctamente!\n";

  Limpieza::pausar();
  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::modificarUsuario() {
  try{
  int id;
  cout << "Ingrese el id del usuario que desea modificar: ";
  if (!(cin >> id)) {
      Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para id.");
      Limpieza::pausar();
  }
  Usuario* usuario = usuarios->buscarUsuarioPorId(id);
  if (!usuario) {
      throw Exception("Usuario no encontrado.");
      Limpieza::pausar();
  }

    int opcion;
    cout << "Usuario encontrado: " << endl;
    cout << usuario->toString() << endl;
    cout << "Que desea modificar del usuario?" << endl;
    cout << "1. ID\n" << endl;
    cout << "2. Nombre\n" << endl;
    cout << "3. Estado\n" << endl;
    cout << "Ingrese una opcion: ";
    if (!(cin >> opcion)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida. se esperaba un numero.");
        Limpieza::pausar();
    }

    switch (opcion) {
      case 1: {
        int id;
        cout << "Ingrese el nuevo ID del usuario: ";
        if (!(cin >> id)) {
            Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida para id.");
            Limpieza::pausar();
        }
        usuario->set_id(id);
        cout << "Id cambiado correctamente!\n";
        break;
        Limpieza::pausar();
        
      }
      case 2: {
        string nom;
        cout << "Ingrese el nuevo nombre del usuario: ";
        Limpieza::limpiarBuffer();
        getline(cin, nom);
        usuario->set_nombre_completo(nom);
        cout << "Nombre cambiado correctamente!\n";
        Limpieza::pausar();
        break;
      }
      case 3: {
        int eleccion;
        bool estado;
        cout << "Ingrese el estado del usuario (1. Activo 2. Inactivo): ";
        if (!(cin >> eleccion)) {
          Limpieza::limpiarBuffer();
            throw Exception("Entrada invalida para estado.");
            Limpieza::pausar();
        }
        if (eleccion == 1) {
          estado = true;
        } else if (eleccion == 2) {
          estado = false;
        } else {
          throw Exception("Estado no valido. use 1 para activo o 2 para inactivo.");
          Limpieza::pausar();
        }
        usuario->set_estado(estado);
        cout << "Estado del usuario cambiado correctamente!\n";
        break;
        Limpieza::pausar();
      }
      default:
        throw Exception("opcion no valida.");
        Limpieza::pausar();
    }
} catch (const Exception& e) {
  cerr << "Error: " << e.what() << endl;
  Limpieza::pausar();
  }
}

void Coleccion::eliminarUsuario() {
  try {
    int id;
    cout << "Usuarios: " << endl;
    usuarios->mostrarUsuarios();
    cout << "Ingrese el id del usuario que desea eliminar: ";
    if (!(cin >> id)) {
        Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id.");
        Limpieza::pausar();
    }
    Limpieza::limpiarBuffer();
    usuarios->eliminarUsuarioPorId(id);
    cout << "Usuario eliminado correctamente!\n";
    Limpieza::pausar();
  } catch (Exception& e) {
    cerr << "Error al eliminar usuario: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::mostrarDisponiblesPorTipo(string tipoBuscado) {
  try{
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
  }catch (exception& e) {
    cerr << "Error al mostrar materiales disponibles: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::registrarPrestamo() {
  try{
  int idUsuario;
  cout << "Ingrese el id del usuario que solicita el prestamo: ";
  if (!(cin >> idUsuario)) {
    Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para id.");
      Limpieza::pausar();
  }
  Limpieza::limpiarBuffer();

  Usuario* usuario = usuarios->buscarUsuarioPorId(idUsuario);
  if (!usuario) {
      throw Exception("Usuario no encontrado");
      Limpieza::pausar();
  }

  int tipo;
  cout << "Ingrese el tipo de material que desea: " << endl;
  cout << "1. Libro" << endl;
  cout << "2. Revista" << endl;
  cout << "3. Articulo" << endl;
  cout << "4. Video" << endl;
    cout << "Ingrese una opcion: ";
  if (!(cin >> tipo)) {
    Limpieza::limpiarBuffer();
      throw Exception("Entrada invalida para tipo de material.");
      Limpieza::pausar();
  }

  Limpieza::limpiarBuffer();

  switch (tipo) {
    case 1:
      registrarPrestamoLibro(usuario);
      break;
    case 2:
      registrarPrestamoRevista(usuario);
      break;
    case 3:
      registrarPrestamoArticulo(usuario);
      break;
    case 4:
      registrarPrestamoVideo(usuario);
      break;
    default:
      throw Exception("tipo de material incorrecto");
      Limpieza::pausar();
    }
  } catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::registrarPrestamoLibro(Usuario* usuario) {
  try{
    string nom;
    int idPrestamo;

    cout << "Libros disponibles: " << endl;
    mostrarDisponiblesPorTipo("Libro");
    cout << endl;
    cout << "Ingrese el titulo del libro que desea solicitar: ";
    getline(cin, nom);
    Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);
    if (!matSolicitado) {
        throw Exception("Material no encontrado");
        Limpieza::pausar();
    }
    cout << "Ingrese un id para el prestamo: ";
    if (!(cin >> idPrestamo)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id Prestamo.");
        Limpieza::pausar();
    }

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
    Limpieza::pausar();
  }catch (const Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}

void Coleccion::registrarPrestamoRevista(Usuario* usuario) {
  try{
    string nom;
    int idPrestamo;

    cout << "Revistas disponibles: " << endl;
    mostrarDisponiblesPorTipo("Revista");
    cout << endl;
    cout << "Ingrese el titulo de la revista que desea solicitar: ";
    getline(cin, nom);
    Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);
    if (!matSolicitado) {
        throw Exception("Revista no encontrada.");
    }

    cout << "Ingrese un id para el prestamo: ";
    if (!(cin >> idPrestamo)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id Prestamo.");
    }

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
    Limpieza::pausar();
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
  }
}
void Coleccion::registrarPrestamoArticulo(Usuario* usuario) {
  try{
    string nom;
    int idPrestamo;

    cout << "Articulos disponibles: " << endl;
    mostrarDisponiblesPorTipo("Articulo");
    cout << endl;
    cout << "Ingrese el titulo del articulo que desea solicitar: ";
    getline(cin, nom);
    Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);
    if (!matSolicitado) {
        throw Exception("Articulo no encontrado.");
    }

    cout << "Ingrese un id para el prestamo: ";
    if (!(cin >> idPrestamo)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id Prestamo.");
        Limpieza::pausar();
    }


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
    Limpieza::pausar();
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::registrarPrestamoVideo(Usuario* usuario) {
  try{
    string nom;
    int idPrestamo;

    cout << "Libros disponibles: " << endl;
    mostrarDisponiblesPorTipo("Video");
    cout << endl;
    cout << "Ingrese el titulo del video que desea solicitar: ";

    getline(cin, nom);
    Materiales* matSolicitado = inventario->buscarMaterialPorTitulo(nom);
    if (!matSolicitado) {
        throw Exception("Video no encontrado.");

    }

    cout << "Ingrese un id para el prestamo: ";
    if (!(cin >> idPrestamo)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id Prestamo.");
        Limpieza::pausar();
    }


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
    Limpieza::pausar();
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::registrarDevolucion() {
  try{
    int id;
    gestorPrestamos->mostrarPrestamosGeneral();
    cout << endl;
    cout << "Ingrese el ID del prestamo que desea regresar: ";
    if (!(cin >> id)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para id Prestamo.");
        Limpieza::pausar();
    }
    Limpieza::limpiarBuffer();
    if (gestorPrestamos->eliminarPrestamo(id)) {
      cout << "Prestamo devuelto exitosamente." << endl;
    }
    throw Exception("No se encontro un prestamo con este ID");
    Limpieza::pausar();
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
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
  try{
    int tipo;
    cout << "\tIngrese el tipo de material:" << endl;
    cout << "1. Libros" << endl;
    cout << "2. Revistas" << endl;
    cout << "3. Articulos" << endl;
    cout << "4. Videos" << endl;
    cout << "Ingrese una opcion: ";
    if (!(cin >> tipo)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida para elegir tipo.");
    }

    switch (tipo) {
      case 1:
        inventario->mostrarMaterialesPorTipo("Libro");
      break;
      case 2:
        inventario->mostrarMaterialesPorTipo("Revista");
      break;
      case 3:
        inventario->mostrarMaterialesPorTipo("Articulo");
      break;
      case 4:
        inventario->mostrarMaterialesPorTipo("Video");
      break;
      default:
        throw Exception("Tipo de material incorrecto");
    }
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::reportePrestamosPorUsuario() {
  try{
    int id;
    cout << "Ingrese el ID del usuario: ";
    if (!(cin >> id)) {
      Limpieza::limpiarBuffer();
        throw Exception("Entrada invalida del id de usuario.");
        Limpieza::pausar();
    }
    Limpieza::limpiarBuffer();
    Usuario* usuario = usuarios->buscarUsuarioPorId(id);
    cout << endl;
    gestorPrestamos->mostrarPrestamosPorUsuario(usuario);
  }catch (Exception& e) {
    cerr << "Error: " << e.what() << endl;
    Limpieza::pausar();
  }
}
void Coleccion::guardarUsuarios() {
  GestorArchivos<Usuario>::guardarUsuarios(usuarios->getCatalogoUsuarios(),"Usuarios.csv");
}

void Coleccion::guardarMateriales() {
  GestorArchivos<Materiales>::guardarMateriales(inventario->getBiblioteca(),"Materiales.csv");
}

void Coleccion::guardarPrestamos() {
  GestorArchivos<Prestamo>::guardarPrestamos(gestorPrestamos->getPrestamos(),"Prestamos.csv");
}

void Coleccion::cargarDatos() {
  try{
    usuarios->setUsuarios(GestorArchivos<Usuario>::cargarUsuarios("Usuarios.csv"));
    inventario->setMateriales(GestorArchivos<Materiales>::cargarMateriales("Materiales.csv"));
    // cargar cuando las listas estan llenas de algo
    gestorPrestamos->setListaPrestamos(GestorArchivos<Prestamo>::cargarPrestamos(usuarios->getCatalogoUsuarios(),inventario->getBiblioteca(),"Prestamos.csv"));
    if (usuarios->getCatalogoUsuarios()->estaVacia() ||inventario->getBiblioteca()->estaVacia() ||gestorPrestamos->getPrestamos()->estaVacia()) {
      throw Exception("No se pudieron cargar correctamente todos los datos."); Limpieza::pausar();
    }

    // mostrar contenido
    cout << "Usuarios cargados:\n";
    cout << "-----------------------------------------------------\n";
    cout << usuarios->getCatalogoUsuarios()->mostrar();

    cout << "\nMateriales cargados:\n";
    cout << "-----------------------------------------------------\n";
    cout << inventario->getBiblioteca()->mostrar();

    cout << "\nPrestamos cargados:\n";
    cout << "------------------------------------------------------\n";
    cout << gestorPrestamos->getPrestamos()->mostrar();

    cout << "\nDatos cargados correctamente\n";
    
  }catch (Exception& e) {
    cerr << "Error al cargar datos: " << e.what() << endl;
    Limpieza::pausar();
  }
  Limpieza::pausar();
}

