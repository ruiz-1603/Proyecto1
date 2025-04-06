//
// Created by bryan on 25/03/2025.
//

#include "Materiales.h"
Materiales::Materiales() : numCalificacion(0),numCatalogo(0),titulo(""),autor(""),estado(""), palabrasClaves(""){
}
Materiales::Materiales(int numCal, int numCa, string ti, string au, string estado,string pa): numCalificacion(numCal),numCatalogo(numCal),titulo(ti),autor(au),estado(estado),palabrasClaves(pa){
}

Materiales::~Materiales() {
}

int Materiales::get_num_calificacion() const {
    return numCalificacion;
}

void Materiales::set_num_calificacion(int num_calificacion) {
    numCalificacion = num_calificacion;
}

int Materiales::get_num_catalogo() const {
    return numCatalogo;
}

void Materiales::set_num_catalogo(int num_catalogo) {
    numCatalogo = num_catalogo;
}

string Materiales::get_titulo() const {
    return titulo;
}

void Materiales::set_titulo(const string &titulo) {
    this->titulo = titulo;
}

string Materiales::get_autor() const {
    return autor;
}

void Materiales::set_autor(const string &autor) {
    this->autor = autor;
}

string Materiales::get_palabras_claves() const {
    return palabrasClaves;
}

void Materiales::set_palabras_claves(string pala) {
    palabrasClaves = pala;
}

string Materiales::get_estado() const {
    return estado;
}

void Materiales::set_estado(string estado) {
    this->estado = estado;
}
string Materiales::toString() {
    stringstream ss;
    ss << "Tipo: " << getTipo() << "\n"
       << "Titulo: " << get_titulo() << "\n"
       << "Autor: " << get_autor() << "\n"
       << "Estado: " << get_estado() << "\n"
       << "Numero de Calificacion: " << get_num_calificacion() << "\n"
       << "Numero de Catalogo: " << get_num_catalogo() << "\n"
       << "Palabras Claves: " << get_palabras_claves() << "\n";

    return ss.str();
}
