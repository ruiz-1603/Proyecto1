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
  ListaUsuarios* usuarios;
  GestorPrestamos* gestorPrestamos;

public:
  Coleccion();
  ~Coleccion();

  void agregarInventario();
  void modificarMaterial();

  void agregarUsuario();
  void modificarUsuario();

  bool registrarPrestamo();
//  bool registrarDevolucion();

  void reporteInventario();
  void reporteUsuarios();
  void reporteMaterialesPrestados();
  void reportePrestamoPorUsuario();
};

#endif //COLECCION_H
