//
// Created by castr on 7/4/2025.
//

#ifndef GESTORPRESTAMOS_H
#define GESTORPRESTAMOS_H

#include "Prestamo.h"
#include "Lista.h"

class GestorPrestamos {
private:
    Lista<Prestamo>* prestamos;

public:
  GestorPrestamos();
  ~GestorPrestamos();

  void agregarPrestamo(Prestamo* prestamo);
  void mostrarPrestamosGeneral();
  void mostrarPrestamosPorMaterial(string&);
  void mostrarPrestamosPorUsuario(Usuario*);
  void mostrarPrestamosVencidos();
  bool eliminarPrestamo(int);
  Lista<Prestamo>* getPrestamos();
};

#endif //GESTORPRESTAMOS_H
