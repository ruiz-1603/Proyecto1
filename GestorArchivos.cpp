//
// Created by RuizM on 4/7/2025.
//

#include "GestorArchivos.h"

template<class Tipo>
void GestorArchivos<Tipo>::guardarPrestamos(Lista<Prestamo> *prestamos, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "IdPrestamo,NombreUsuario,TipoMaterial,TituloMaterial,FechaPrestamo,FechaVencimiento,Estado,"
               "Autor,EstadoMaterial,PalabrasClave,Direccion,NumCalificacion,NumCatalogo,"
               "NumRevista,VolumenRevista,TipoMaterialDigital,FormatoMaterial,EstadoDigital\n";

    Nodo<Prestamo>* actual = prestamos->obtenerPrimero();

    while (actual != nullptr) {
        Prestamo* p = actual->getDato();
        Materiales* material = p->getMaterial();

        string tipoMaterial = material->getTipo(); // asumimos que retorna "Libro", "Revista" o "Video"
        string autor = "", estadoMat = "", palabrasClave = "", direccion = "";
        int numCal = 0, numCat = 0;
        int numRevista = -1, volumenRevista = -1;
        string tipoDigital = "", formato = "";
        string estadoDigital = "";

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

        archivo << p->getId() << ","
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

    archivo.close();
    cout << "Archivo CSV generado correctamente como " << nombreArchivo << endl;
}


template<class Tipo>
Lista<Prestamo>* GestorArchivos<Tipo>::cargarPrestamos(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    Lista<Prestamo>* lista = new Lista<Prestamo>();

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo :(\n";
        return nullptr;
    }

    string linea;
    getline(archivo, linea); // Saltar encabezado

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string idPrestamo, nombreUsuario, tipoMaterial, titulo, fechaPrestamo, fechaVencimiento, estadoPrestamo;
        string autor, estadoMaterial, palabrasClave, direccion, numCal, numCat;
        string numRevista, volumenRevista, tipoDigital, formato, estadoDigital;

        getline(ss, idPrestamo, ',');
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

        // Validación básica
        if (idPrestamo.empty() || numCal.empty() || numCat.empty()) {
            //línea con datos faltantes y se omite
            continue;
        }

        int prestamoID = stoi(idPrestamo);
        int numCalificacion = stoi(numCal);
        int numCatalogo = stoi(numCat);

        Usuario* usuario = new Usuario(prestamoID, nombreUsuario, estadoPrestamo == "En plazo");

        Materiales* material = nullptr;

        if (tipoMaterial == "Libro") {
            material = new Libro(numCalificacion, numCatalogo, titulo, autor, estadoMaterial, palabrasClave, direccion);
        }
        else if (tipoMaterial == "Revista") {
            if (numRevista.empty() || volumenRevista.empty()) {
                cout << "Revista con datos incompletos. Se omite.\n";
                continue;
            }
            int nRev = stoi(numRevista);
            int volRev = stoi(volumenRevista);
            material = new Revista(numCalificacion, numCatalogo, titulo, autor, estadoMaterial, palabrasClave, direccion, nRev, volRev);
        }
        else if (tipoMaterial == "Video") {
            bool disponible = (estadoDigital == "Disponible");
            material = new Video(numCalificacion, numCatalogo, titulo, autor, palabrasClave, estadoMaterial, tipoDigital, formato, disponible);
        }

        if (material != nullptr) {
            Prestamo* nuevo = new Prestamo(prestamoID, usuario, material, fechaPrestamo, fechaVencimiento);
            lista->agregarALista(nuevo);
        }
    }

    return lista;
}



template<class Tipo>
void GestorArchivos<Tipo>::guardarUsuarios(Lista<Usuario> *usuarios, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl; //meter excepcion
        return;
    }

    Nodo<Usuario>* actual = usuarios->obtenerPrimero();
    while (actual != nullptr) {
        archivo << actual->getDato()->getId() << ";"           // ID del usuario
                << actual->getDato()->get_nombre_completo() << ";" // Nombre completo del usuario
                << (actual->getDato()->is_estado() ? "Activo" : "Inactivo") << endl; // Estado del usuario
        actual = actual->getSiguiente();
    }

    archivo.close();
}

template<class Tipo>
Lista<Usuario>*  GestorArchivos<Tipo>::cargarUsuarios(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    Lista<Usuario>* lista = new Lista<Usuario>();

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo :(\n";
        return nullptr;
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
    return lista;
}

template<class Tipo>
void GestorArchivos<Tipo>::guardarMateriales(Lista<Materiales> *materiales, const string &nombreArchivo) {
 ofstream archivo(nombreArchivo, ios::out );

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para guardar materiales." << endl;
        return;
    }
    archivo<<"Material,NumClasif,NumCatalogo,Titulo,Autores,Estado,PalabrasClave,Direccion/Estado,NumRevista/DiasPrestamo,NumVolumen,DiasPrestamo\n";
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
                        << libro->diasPrestamo() << "\n";
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
                        << revista->get_num_revista() << ","
                        << revista->get_volumen_revista() << ","
                        << revista->diasPrestamo() << "\n";
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
                        << video->diasPrestamo() << "\n";
            }
        }
        actual = actual->getSiguiente();
    }
    archivo.close();
}

template<class Tipo>
void GestorArchivos<Tipo>::cargarMateriales(Lista<Materiales> *catalogo, const string &nombreArchi) {
}
