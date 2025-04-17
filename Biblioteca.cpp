//
// Created by bryan on 05/04/2025.
//

#include "Biblioteca.h"

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
    cout << "Inventario de " << material << "s:" << endl; // revisar como queda en consola

    while (aux != nullptr) {
        Materiales* bib = aux->getDato();
        if (bib->getTipo() == material) {
            cout << ++cont << ". " << bib->toString() << endl;
        }
        aux = aux->getSiguiente();
    }

    if (cont == 0) {
        cout << "\tNo hay materiales de tipo " << material << "." << endl;
    }
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
