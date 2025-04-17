//
// Created by castr on 7/4/2025.
//

#include "Prestamo.h"

Prestamo::Prestamo(int id, Usuario* usuario, Materiales* material, string fPrestamo, string fVencimiento) {
  this->id = id;
  this->usuario = usuario;
  this->material = material;
  this->fechaPrestamo = fPrestamo;
  this->fechaVencimiento = fVencimiento;
}
Prestamo::Prestamo() {
  this->id = -1;
  this->usuario = nullptr;
  this->material = nullptr;
  this->fechaPrestamo = "00-00-0000";
  this->fechaVencimiento = "00-00-0000";
}
Prestamo::~Prestamo() {}

bool Prestamo::estaVencido() {
  tm fecha_tm = {};
  istringstream ss(getFechaVencimiento());
  ss >> std::get_time(&fecha_tm, "%d-%m-%Y");

  if (ss.fail()) {
    return false; // tal vez enviar exception en lugar de false para no confundir
  }

  time_t fecha_vencimiento = mktime(&fecha_tm);
  time_t fecha_hoy = time(nullptr);

  return fecha_vencimiento < fecha_hoy;
}

int Prestamo::getId() { return id; }
Usuario* Prestamo::getUsuario() { return usuario; }
Materiales* Prestamo::getMaterial() { return material; }
string Prestamo::getFechaPrestamo() { return fechaPrestamo; }
string Prestamo::getFechaVencimiento() { return fechaVencimiento; }

void Prestamo::setId(int id) { this->id = id;}
void Prestamo::setUsuario(Usuario* usuario) { this->usuario = usuario; }
void Prestamo::setMaterial(Materiales* material) { this->material = material; };
void Prestamo::setFechaPrestamo(string fPrestamo) { this->fechaPrestamo = fPrestamo; }
void Prestamo::setFechaVencimiento(string fVencimiento) { this->fechaVencimiento = fVencimiento; }

string Prestamo::toString() {
  stringstream ss; // revisar como se ve en consola
  ss << "Usuario" << endl;
  ss << getUsuario()->toString() << endl << endl;
  ss << "Material prestado" << endl;
  ss << getMaterial()->toString();
  ss << "Estado del prestamo: " << (estaVencido() ? "Vencido" : "En plazo") << endl;
  ss << "-------------------------------------------------------";
  return ss.str();
}