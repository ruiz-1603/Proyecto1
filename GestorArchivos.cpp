//
// Created by RuizM on 4/7/2025.
//

#include "GestorArchivos.h"

template<class Tipo>
void GestorArchivos<Tipo>::guardarPrestamos(Lista<Prestamo> *prestamos, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out | ios::app);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl; //meter excepcion
        return;
    }
    // idPrestamo,NombreUsuario,tituloMaterial,fechaPrestamo,fechaVencimiento
    archivo << "IdPrestamo,NombreUsuario,TituloMaterial,FechaPrestamo,FechaVencimiento,Estado\n";

    Nodo<Prestamo>* actual = prestamos->obtenerPrimero();

    while (actual != nullptr) {
        Prestamo* p = actual->getDato();

        archivo << p->getId() << ","
                << p->getUsuario()->get_nombre_completo() << ","
                << p->getMaterial()->get_titulo() << ","
                << p->getFechaPrestamo() << ","
                << p->getFechaVencimiento() << ","
                << (p->estaVencido() ? "Vencido" : "En plazo") << "\n";

        actual = actual->getSiguiente();
    }

    archivo.close();
    cout << "Archivo CSV generado correctamente como " << nombreArchivo << endl;
}

template<class Tipo>
void GestorArchivos<Tipo>::cargarPrestamos(Lista<Prestamo> *catalogo, const string &nombreArchi) {
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
void GestorArchivos<Tipo>::cargarUsuarios(Lista<Usuario> *usuarios, const string &nombreArchi) {
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
