//
// Created by bryan on 05/04/2025.
//

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Lista.h"

class Biblioteca {
    private:
    Lista<Materiales>* lista;
    public: // agregar destructor?
    Biblioteca();
    void agregarMaterial(Materiales* material);
    void mostrarMateriales();
    void eliminarMaterialPorTitulo(const std::string& titulo);
    Materiales* buscarMaterialPorTitulo(const std::string& titulo);
    Materiales* buscarMaterialPorNumero(int num);
    Lista<Materiales>* getBiblioteca(){return lista;}
};



#endif //BIBLIOTECA_H
