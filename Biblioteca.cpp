#include "Biblioteca.h"

#include "Exception.h"

Biblioteca::Biblioteca() {
    lista = new Lista<Materiales>();
}
void Biblioteca::agregarMaterial(Materiales* material) {
    lista->agregarALista(material);
}

void Biblioteca::mostrarMateriales() {
     cout << lista->mostrar() << endl;
}

void Biblioteca::mostrarMaterialesPorTipo(string material) {
    Nodo<Materiales>* aux = lista->obtenerPrimero();
    int cont = 0;
    cout << "Inventario de " << material << "s:" << endl;

    if (material == "Articulo" || material == "Libro" || material == "Revista" ||material == "Video" ) {
        while (aux != nullptr) {
            Materiales* bib = aux->getDato();
            if (bib->getTipo() == material) {
                cout << ++cont << ". " << bib->toString() << endl;
            }
            aux = aux->getSiguiente();
        }
    }
    while (aux != nullptr) {
        Materiales* bib = aux->getDato();
        if (bib->getFisicoDigital() == material) {
            cout << ++cont << ". " << bib->toString() << endl;
        }
        aux = aux->getSiguiente();
    }

    if (cont == 0) {
        cout << "\tNo hay materiales de tipo " << material << "." << endl;
       throw Exception("No hay elementos");
    }
}

bool Biblioteca::existenMaterialesPorTipo(const string& material) {
    Nodo<Materiales>* aux = lista->obtenerPrimero();
    bool encontrado = false;

    if (material == "Articulo" || material == "Libro" || material == "Revista" || material == "Video") {
        while (aux != nullptr) {
            Materiales* bib = aux->getDato();
            if (bib->getTipo() == material) {
                encontrado = true;
                break;
            }
            aux = aux->getSiguiente();
        }
    }

    if (!encontrado) {
        aux = lista->obtenerPrimero();
        while (aux != nullptr) {
            Materiales* bib = aux->getDato();
            if (bib->getFisicoDigital() == material) {
                encontrado = true;
                break;
            }
            aux = aux->getSiguiente();
        }
    }

    return encontrado;
}

void Biblioteca::eliminarMaterialPorTitulo(const std::string& titulo) {
    lista->eliminarEnLista(titulo);
}

void Biblioteca::setMateriales(Lista<Materiales> * listaNueva) {
    delete lista;
    lista = listaNueva;
}

Materiales* Biblioteca::buscarMaterialPorTitulo(const std::string& titulo) {
    return lista->buscarEnLista(titulo);
}
