//
// Created by castr on 7/4/2025.
//

#ifndef COLECCION_H
#define COLECCION_H

#include "Biblioteca.h"
#include "ListaUsuarios.h"
#include "GestorPrestamos.h"
#include "Libro.h"
#include "Articulo.h"
#include "Revista.h"
#include "Video.h"

class Coleccion {
private:
  Biblioteca* inventario;
  Lista<ListaUsuarios>* usuarios;
  Lista<GestorPrestamos>* gestorPrestamos;

public:
  Coleccion();
  ~Coleccion();

  void agregarInventario();
//  void modificarMaterial(); // buscar logica
//
//  void agregarUsuario();
//  void modificarUsuario(); // buscar por id? y preguntar que modificar o que
//
//  bool registrarPrestamo();
//  bool registrarDevolucion();
//
//  string reporteInventario();
//  string reporteUsuarios();
//  string reporteMaterialesPrestados();
//  string reportePrestamoPorUsuario();
};

#endif //COLECCION_H
