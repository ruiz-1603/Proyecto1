#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Lista.h"

class Biblioteca {
private:
    Lista<Materiales>* lista;
public:
    Biblioteca();
    void agregarMaterial(Materiales* material);
    void mostrarMateriales();
    void mostrarMaterialesPorTipo(string);
    bool existenMaterialesPorTipo(const string&);
    bool eliminarMaterialPorTitulo(const std::string& titulo);
    void setMateriales(Lista<Materiales>*);
    Materiales* buscarMaterialPorTitulo(const std::string& titulo);
    Materiales* buscarMaterialPorNumero(int num);
    Lista<Materiales>* getBiblioteca(){return lista;}
};

#endif //BIBLIOTECA_H
