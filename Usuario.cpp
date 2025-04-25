#include "Usuario.h"

Usuario::Usuario() {
    this->nombreCompleto = "Sin definir";
    this->id = -1;
    this->estado = false;
}

Usuario::Usuario(int id, string nom, bool est) {
    this->nombreCompleto = nom;
    this->id = id;
    this->estado = est;
}

int Usuario::getId() const {
    return id;
}

void Usuario::set_id(int id) {
    this->id = id;
}

string Usuario::get_nombre_completo() const {
    return nombreCompleto;
}

void Usuario::set_nombre_completo(const string &nombre_completo) {
    nombreCompleto = nombre_completo;
}

bool Usuario::is_estado() const {
    return estado;
}

void Usuario::set_estado(bool estado) {
    this->estado = estado;
}
string Usuario::toString() {
    stringstream ss;
    ss << "Cedula: " << getId() << endl;
    ss << "Nombre: " << get_nombre_completo() << endl;
    ss << "Estado: " << (is_estado() ? "Activo" : "Inactivo") << endl;

    return ss.str();
}
