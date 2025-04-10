//
// Created by castr on 7/4/2025.
//

#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos() {}
GestorPrestamos::~GestorPrestamos() {}

void GestorPrestamos::agregarPrestamo(Prestamo* prestamo) {
  prestamos->agregarALista(prestamo);
}

void GestorPrestamos::mostrarPrestamosGeneral() {
  cout << prestamos->mostrar();
}

void GestorPrestamos::mostrarPrestamosPorMaterial(string& material) {
  Nodo<Prestamo>* aux = prestamos->obtenerPrimero();
  int cont = 0;
  cout << "Prestamos de " << material << ":" << endl; // revisar como queda en consola

  while (aux != nullptr) {
    Prestamo* prestamo = aux->getDato();
    if (prestamo->getMaterial()->getTipo() == material) {
      cout << ++cont << ". " << prestamo->toString() << endl;
    }
    aux = aux->getSiguiente();
  }

  if (cont == 0) {
    cout << "\tNo hay prestamos registrados de " << material << "." << endl;
  }
}

void GestorPrestamos::mostrarPrestamosPorUsuario(Usuario* usuario) {
  Nodo<Prestamo>* aux = prestamos->obtenerPrimero();
  int cont = 0;
  cout << "Prestamos de " << usuario->get_nombre_completo() << ":" << endl;

  while (aux != nullptr) {
    Prestamo* prestamo = aux->getDato();
    if (prestamo->getUsuario()->get_id() == usuario->get_id()) {
      cout << ++cont << ". " << prestamo->toString() << endl;
    }
    aux = aux->getSiguiente();
  }

  if (cont == 0) {
    cout << "\tNo hay prestamos registrados de " << usuario->get_nombre_completo() << "." << endl;
  }
}

void GestorPrestamos::mostrarPrestamosVencidos() {
  Nodo<Prestamo>* aux = prestamos->obtenerPrimero();
  int cont = 0;
  cout << "Prestamos de vencidos:" << endl;

  while (aux != nullptr) {
    Prestamo* prestamo = aux->getDato();
    if (prestamo->estaVencido()) {
      cout << ++cont << ". " << prestamo->toString() << endl;
    }
    aux = aux->getSiguiente();
  }

  if (cont == 0) {
    cout << "No hay prestamos vencidos." << endl;
  }
}

bool GestorPrestamos::eliminarPrestamo(int idPrestamo) {
  return prestamos->eliminar(idPrestamo);
}

Lista<Prestamo>* GestorPrestamos::getPrestamos() { return prestamos; }