#include "GestorArchivos.h"

template<class Tipo>
void GestorArchivos<Tipo>::guardarPrestamos(Lista<Prestamo> *prestamos, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    try{
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        Nodo<Prestamo>* actual = prestamos->obtenerPrimero();

        while (actual != nullptr) {
            Prestamo* p = actual->getDato();
            Materiales* material = p->getMaterial();

            string tipoMaterial = material->getTipo(); // retorna "Libro", "Revista" o "Video"
            string autor, estadoMat, palabrasClave, direccion;
            int numCal, numCat, idUsuario, idPrestamo;
            int numRevista, volumenRevista;
            string tipoDigital, formato;
            string estadoDigital;

            // Casteo según el tipo de material
            if (tipoMaterial == "Libro") {
                Libro* libro = dynamic_cast<Libro*>(material);
                if (libro) {
                    autor = libro->get_autor();
                    estadoMat = libro->get_estado();
                    palabrasClave = libro->get_palabras_claves();
                    direccion = libro->get_direccion();
                    numCal = libro->get_num_calificacion();
                    numCat = libro->get_num_catalogo();
                }
            } else if (tipoMaterial == "Revista") {
                Revista* revista = dynamic_cast<Revista*>(material);
                if (revista) {
                    autor = revista->get_autor();
                    estadoMat = revista->get_estado();
                    palabrasClave = revista->get_palabras_claves();
                    direccion = revista->get_direccion();
                    numCal = revista->get_num_calificacion();
                    numCat = revista->get_num_catalogo();
                    numRevista = revista->get_num_revista();
                    volumenRevista = revista->get_volumen_revista();
                }
            } else if (tipoMaterial == "Video") {
                Video* video = dynamic_cast<Video*>(material);
                if (video) {
                    autor = video->get_autor();
                    estadoMat = video->get_estado();
                    palabrasClave = video->get_palabras_claves();
                    tipoDigital = video->getTipo();
                    formato = video->get_formato_material();
                    estadoDigital = video->get_estado_acceso() ? "Disponible" : "No disponible";
                    numCal = video->get_num_calificacion();
                    numCat = video->get_num_catalogo();
                }
            }
            else if (tipoMaterial == "Articulo") {
                Articulo* articulo = dynamic_cast<Articulo*>(material);
                if (articulo) {
                    numCal = articulo->get_num_calificacion();
                    numCat = articulo->get_num_catalogo();
                    autor = articulo->get_autor();
                    estadoMat = articulo->get_estado();
                    palabrasClave = articulo->get_palabras_claves();
                    direccion = articulo->get_direccion();
                }
            }

            archivo << p->getId() << ","
                    << p->getUsuario()->getId() << ","
                    << p->getUsuario()->get_nombre_completo() << ","
                    << tipoMaterial << ","
                    << material->get_titulo() << ","
                    << p->getFechaPrestamo() << ","
                    << p->getFechaVencimiento() << ","
                    << (p->estaVencido() ? "Vencido" : "En plazo") << ","
                    << autor << ","
                    << estadoMat << ","
                    << palabrasClave << ","
                    << direccion << ","
                    << numCal << ","
                    << numCat << ","
                    << numRevista << ","
                    << volumenRevista << ","
                    << tipoDigital << ","
                    << formato << ","
                    << estadoDigital << "\n";

            actual = actual->getSiguiente();
        }

        cout << "Datos de los prestamos guardados correctamente en " << nombreArchivo << endl;
    }catch (const Exception &e) {
        cerr << "Error en guardar prestamos: "<< e.what() << endl;
    }
    archivo.close();
}

template<class Tipo>
Lista<Prestamo>* GestorArchivos<Tipo>::cargarPrestamos(
    Lista<Usuario>* usuarios,
    Lista<Materiales>* materiales,
    const string& nombreArchivo
) {
    Lista<Prestamo>* lista = new Lista<Prestamo>();
    ifstream archivo(nombreArchivo);
    try{
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        string linea;
        getline(archivo, linea);  // saltar encabezado

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string idPrestamo, idUsuario, nombreUsuario, tipoMaterial;
            string titulo, fechaPrestamo, fechaVencimiento, estadoPrestamo;
            string autor, estadoMaterial, palabrasClave, direccion;
            string numCal, numCat, numRevista, volumenRevista;
            string tipoDigital, formato, estadoDigital;

            getline(ss, idPrestamo, ',');
            getline(ss, idUsuario, ',');
            getline(ss, nombreUsuario, ',');
            getline(ss, tipoMaterial, ',');
            getline(ss, titulo, ',');
            getline(ss, fechaPrestamo, ',');
            getline(ss, fechaVencimiento, ',');
            getline(ss, estadoPrestamo, ',');
            getline(ss, autor, ',');
            getline(ss, estadoMaterial, ',');
            getline(ss, palabrasClave, ',');
            getline(ss, direccion, ',');
            getline(ss, numCal, ',');
            getline(ss, numCat, ',');
            getline(ss, numRevista, ',');
            getline(ss, volumenRevista, ',');
            getline(ss, tipoDigital, ',');
            getline(ss, formato, ',');
            getline(ss, estadoDigital);

            if (idPrestamo.empty() || idUsuario.empty() || numCal.empty() || numCat.empty())
                continue;
            int prestamoID, usuarioID, numCalificacion, numCatalogo;
            try {
                prestamoID      = stoi(idPrestamo);
                usuarioID       = stoi(idUsuario);
                numCalificacion = stoi(numCal);
                numCatalogo     = stoi(numCat);
            } catch (const Exception &e) {
                cerr << "Error: dato invalido en el archivo de prestamos (stoi): " << e.what() << endl;
                continue;  // salta esta línea y sigue con la siguiente
            }
            // evitar usuarios duplicados
            Usuario* usuario = usuarios->buscarEnListaUsua(usuarioID);
            if (!usuario) {
                usuario = new Usuario(
                    usuarioID,
                    nombreUsuario,
                    (estadoPrestamo == "En plazo")
                );
                usuarios->agregarALista(usuario);
            }

            // evita duplicados por título
            Materiales* material = materiales->buscarEnLista(titulo);
            if (!material) {
                if (tipoMaterial == "Libro") {
                    material = new Libro(
                        numCalificacion,
                        numCatalogo,
                        titulo,
                        autor,
                        estadoMaterial,
                        palabrasClave,
                        direccion
                    );
                }
                else if (tipoMaterial == "Revista" && !numRevista.empty() && !volumenRevista.empty()) {
                    try {
                        int nRev   = stoi(numRevista);
                        int volRev = stoi(volumenRevista);
                        material = new Revista(
                            numCalificacion,
                            numCatalogo,
                            titulo,
                            autor,
                            estadoMaterial,
                            palabrasClave,
                            direccion,
                            nRev,
                            volRev
                        );
                    } catch (const Exception &e) {
                        cerr << "Error: revista con número o volumen inválido: " << e.what() << endl;
                        continue;
                    }
                }
                else if (tipoMaterial == "Video") {
                    bool disponible = (estadoDigital == "Disponible");
                    material = new Video(
                        numCalificacion,
                        numCatalogo,
                        titulo,
                        autor,
                        palabrasClave,
                        estadoMaterial,
                        tipoDigital,
                        formato,
                        disponible
                    );
                }
                else if (tipoMaterial == "Articulo") {
                    material = new Articulo(
                        numCalificacion,
                        numCatalogo,
                        titulo,
                        autor,
                        estadoMaterial,
                        palabrasClave,
                        direccion
                    );
                }
                if (material) {
                    materiales->agregarALista(material);
                }
            }

            // crea y agregar el préstamo
            if (usuario && material) {
                Prestamo* nuevo = new Prestamo(
                    prestamoID,
                    usuario,
                    material,
                    fechaPrestamo,
                    fechaVencimiento
                );
                lista->agregarALista(nuevo);
            }
        }
    }catch (const Exception &e) {
        cerr << "Error en cargar prestamos: "<< e.what() << endl;
    }
    archivo.close();
    return lista;
}

template<class Tipo>
void GestorArchivos<Tipo>::guardarUsuarios(Lista<Usuario> *usuarios, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    try {
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        Nodo<Usuario>* actual = usuarios->obtenerPrimero();
        while (actual != nullptr) {
            archivo << actual->getDato()->getId() << ","           // ID del usuario
                    << actual->getDato()->get_nombre_completo() << "," // Nombre completo del usuario
                    << (actual->getDato()->is_estado() ? "Activo" : "Inactivo") << endl; // Estado del usuario
            actual = actual->getSiguiente();
        }
        cout<<"Datos de los usuarios guardados correctamente en "<< nombreArchivo <<endl;

    }catch (const Exception &e) {
        cerr << "Error en guardando usuarios: "<< e.what() << endl;
    }
    archivo.close();
}
template<class Tipo>
Lista<Usuario>*  GestorArchivos<Tipo>::cargarUsuarios(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    Lista<Usuario>* lista = new Lista<Usuario>();
    try{
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        string linea;
        getline(archivo, linea); // Saltar encabezado

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre,stringId,stringEstado;

            getline(ss, stringId,',');
            getline(ss, nombre,',');
            getline(ss, stringEstado,',');

            int id = stoi(stringId);
            bool estado = (stringEstado == "Activo");

            Usuario* usuario = new Usuario(id,nombre,estado);
            lista->agregarALista(usuario);
        }
    }catch (const Exception &e) {
        cerr << "Error en cargando usuarios: "<< e.what() << endl;
    }
    archivo.close();
    return lista;
}

template<class Tipo>
void GestorArchivos<Tipo>::guardarMateriales(Lista<Materiales> *materiales, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    try{
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        Nodo<Materiales>* actual = materiales->obtenerPrimero();

        while (actual != nullptr) {
            Materiales* material = actual->getDato();
            if (material->getTipo() == "Libro") {
                Libro* libro = dynamic_cast<Libro*>(material);
                if (libro) {
                    archivo << "Libro,"
                            << libro->get_num_calificacion() << ","
                            << libro->get_num_catalogo() << ","
                            << libro->get_titulo() << ","
                            << libro->get_autor() << ","
                            << libro->get_estado() << ","
                            << libro->get_palabras_claves() << ","
                            << libro->get_direccion() << ","
                            << "-,-,-,-,-,"
                            << libro->diasPrestamo()
                            << "\n";
                }
            } else if (material->getTipo() == "Revista") {
                Revista* revista = dynamic_cast<Revista*>(material);
                if (revista) {
                    archivo << "Revista,"
                            << revista->get_num_calificacion() << ","
                            << revista->get_num_catalogo() << ","
                            << revista->get_titulo() << ","
                            << revista->get_autor() << ","
                            << revista->get_estado() << ","
                            << revista->get_palabras_claves() << ","
                            << revista->get_direccion() << ","
                            << "-,-,-,"
                            << revista->get_num_revista() << ","
                            << revista->get_volumen_revista() << ","
                            << revista->diasPrestamo()
                            << "\n";
                }
            } else if (material->getTipo() == "Video") {
                Video* video = dynamic_cast<Video*>(material);
                if (video) {
                    archivo << "Video,"
                            << video->get_num_calificacion() << ","
                            << video->get_num_catalogo() << ","
                            << video->get_titulo() << ","
                            << video->get_autor() << ","
                            << video->get_estado() << ","
                            << video->get_palabras_claves() << ","
                            << "-,"
                            << video->get_tipo_material() << ","
                            << video->get_formato_material() << ","
                            << (video->get_estado_acceso() ? "Activo" : "Inactivo") << ","
                            << "-,-,"
                            << video->diasPrestamo()
                            << "\n";
                }
            }
            else if (material->getTipo() == "Articulo") {
                Articulo* articulo = dynamic_cast<Articulo*>(material);
                if (articulo) {
                    archivo << "Articulo,"
                            << articulo->get_num_calificacion() << ","
                            << articulo->get_num_catalogo() << ","
                            << articulo->get_titulo() << ","
                            << articulo->get_autor() << ","
                            << articulo->get_estado() << ","
                            << articulo->get_palabras_claves() << ","
                            <<articulo->get_direccion() << ","
                            <<"-,-,-,-,-,"
                            <<articulo->get_dia_prestamo()
                            << "\n";
                }
            }
            actual = actual->getSiguiente();
        }
        cout<<"Datos guardados correctamente en "<< nombreArchivo<<endl;
    }catch (const Exception &e) {
        cerr << "Error en guardar materiales: "<< e.what() << endl;
    }
    archivo.close();
}

template<class Tipo>
Lista<Materiales>* GestorArchivos<Tipo>::cargarMateriales(const string &nombreArchivo) {
    Lista<Materiales>* lista = new Lista<Materiales>();

    ifstream archivo(nombreArchivo);
    try{
        if (!archivo.is_open()) {
            throw Exception("No se pudo abrir el archivo para escritura: " + nombreArchivo);
        }
        string linea;
        getline(archivo, linea); // Saltar encabezado

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string tipo;
            getline(ss, tipo, ',');

            if (tipo == "Libro") {
                int numCal, numCat;
                string titulo, autor, estado, palClave, direccion;
                string skip;
                int dias;

                if (!(ss >> numCal)) throw Exception("Error al leer numero calificacion de Libro.");
                ss.ignore();
                if (!(ss >> numCat)) throw Exception("Error al leer numero catalogo de Libro.");
                ss.ignore();
                getline(ss, titulo, ',');
                getline(ss, autor, ',');
                getline(ss, palClave, ',');////////
                getline(ss, estado, ',');
                getline(ss, direccion, ',');
                for (int i = 0; i < 5; i++) getline(ss, skip, ','); // Saltar campos no usados
                if (!(ss >> dias)) throw Exception("Error al leer dias de Libro.");

                Libro* libro = new Libro(numCal, numCat, titulo, autor, estado, palClave, direccion);
                lista->agregarALista(libro);

            } else if (tipo == "Revista") {
                int numCal, numCat, numRev, volumen;
                string titulo, autor, estado, palClave, direccion;
                string skip;
                int dias;

                if (!(ss >> numCal)) throw Exception("Error al leer numCal de Revista.");
                ss.ignore();
                if (!(ss >> numCat)) throw Exception("Error al leer numCat de Revista.");
                ss.ignore();
                getline(ss, titulo, ',');
                getline(ss, autor, ',');
                getline(ss, estado, ',');
                getline(ss, palClave, ',');
                getline(ss, direccion, ',');
                for (int i = 0; i < 3; i++) getline(ss, skip, ','); // Saltar campos no usados
                if (!(ss >> numRev)) throw Exception("Error al leer numero revista de Revista.");
                ss.ignore();
                if (!(ss >> volumen)) throw Exception("Error al leer volumen de Revista.");
                ss.ignore();
                if (!(ss >> dias)) throw Exception("Error al leer dias de Revista.");
                Revista* revista = new Revista(numCal, numCat, titulo, autor, estado, palClave, direccion, numRev, volumen);
                lista->agregarALista(revista);

            } else if (tipo == "Video") {
                int numCal, numCat;
                string titulo, autor, estado, palClave, tipoMaterial, formato, acceso;
                string skip;
                int dias;

                if (!(ss >> numCal)) throw Exception("Error al leer numCal de Video.");
                ss.ignore();
                if (!(ss >> numCat)) throw Exception("Error al leer numCat de Video.");
                ss.ignore();
                getline(ss, titulo, ',');
                getline(ss, autor, ',');
                getline(ss, estado, ',');
                getline(ss, palClave, ',');
                getline(ss, skip, ',');
                getline(ss, tipoMaterial, ',');
                getline(ss, formato, ',');
                getline(ss, acceso, ',');
                getline(ss, skip, ',');
                getline(ss, skip, ',');
                if (!(ss >> dias)) throw Exception("Error al leer dias de Video.");

                bool estadoAcceso = (acceso == "Activo");
                Video* video = new Video(numCal, numCat, titulo, autor, palClave, estado, tipoMaterial, formato, estadoAcceso);
                lista->agregarALista(video);

            }else if (tipo == "Articulo") {
                int numCal, numCat;
                string titulo, autor, estado, palClave, direccion;
                string skip;
                int dias;

                if (!(ss >> numCal)) throw Exception("Error al leer numero calificacion de Articulo.");
                ss.ignore();
                if (!(ss >> numCat)) throw Exception("Error al leer numero catalogo de Articulo.");
                ss.ignore();
                getline(ss, titulo, ',');
                getline(ss, autor, ',');
                getline(ss, estado, ',');
                getline(ss, palClave, ',');
                getline(ss, direccion, ',');
                for (int i = 0; i < 3; i++) getline(ss, skip, ','); // Saltar campos no usados

                Articulo* articulo = new Articulo(numCal, numCat, titulo, autor, estado, palClave, direccion);
                lista->agregarALista(articulo);

            }else {
                throw Exception("Tipo de material no reconocido: " + tipo);
            }
        }
    }catch (const Exception &e) {
        cerr << "Error en cargar materiales: "<< e.what() << endl;
    }
    archivo.close();
    return lista;
}


