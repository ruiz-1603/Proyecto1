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
void Biblioteca::eliminarMaterialPorTitulo(const std::string& titulo) {
    lista->eliminarEnLista(titulo);
}

Materiales* Biblioteca::buscarMaterialPorTitulo(const std::string& titulo) {
    return lista->buscarEnLista(titulo);
}
