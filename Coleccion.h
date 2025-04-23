#ifndef COLECCION_H
#define COLECCION_H

#include "Biblioteca.h"
#include "ListaUsuarios.h"
#include "GestorPrestamos.h"
#include"GestorArchivos.h"
#include "Libro.h"
#include "Articulo.h"
#include "Revista.h"
#include "Video.h"
#include "Limpieza.h"

class Coleccion {
private:
  Biblioteca* inventario;
  ListaUsuarios* usuarios;
  GestorPrestamos* gestorPrestamos;

public:
  Coleccion();
  ~Coleccion();

  void agregarInventario();
  void agregarLibro();
  void agregarRevista();
  void agregarArticulo();
  void agregarVideo();

  void modificarMaterial();
  void modificarLibro();
  void modificarRevista();
  void modificarArticulo();
  void modificarVideo();

  void eliminarMaterial();

  void agregarUsuario();
  void modificarUsuario();
  void eliminarUsuario();

  void mostrarDisponiblesPorTipo(string);

  void registrarPrestamo();
  void registrarPrestamoLibro(Usuario*);
  void registrarPrestamoRevista(Usuario*);
  void registrarPrestamoArticulo(Usuario*);
  void registrarPrestamoVideo(Usuario*);

  void registrarDevolucion();

  void reporteInventario();
  void reporteUsuarios();
  void reporteMaterialesPrestados();
  void reporteMaterialesPorTipo();
  void reportePrestamosPorUsuario();

  void guardarUsuarios();
  void guardarMateriales();
  void guardarPrestamos();

  void cargarDatos();

};

#endif //COLECCION_H
