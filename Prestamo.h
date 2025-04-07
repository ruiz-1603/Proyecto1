//
// Created by castr on 7/4/2025.
//

#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Usuario.h"
#include "Materiales.h"
#include <iomanip>
#include <ctime>

class Prestamo {
private:
  int id;
  Usuario* usuario;
  Materiales* material;
  string fechaPrestamo;
  string fechaVencimiento;

public:
  Prestamo(int, Usuario*, Materiales*, string, string);
  Prestamo();
  ~Prestamo();

  bool estaVencido();

  int getId();
  Usuario* getUsuario();
  Materiales* getMaterial();
  string getFechaPrestamo();
  string getFechaVencimiento();

  void setId(int);
  void setUsuario(Usuario*);
  void setMaterial(Materiales*);
  void setFechaPrestamo(string);
  void setFechaVencimiento(string);

  string toString();
};

#endif //PRESTAMO_H
