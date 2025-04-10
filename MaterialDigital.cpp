//
// Created by bryan on 25/03/2025.
//

#include "MaterialDigital.h"
MaterialDigital::MaterialDigital(string tipoMaterial, string formatoMaterial, bool ac)
    : Materiales(), tipoMaterial(tipoMaterial), formatoMaterial(formatoMaterial), estado(ac) {
}

MaterialDigital::MaterialDigital(int numCal, int numCa, string ti, string au, string estado, string pa, string tipoMat, string formatoMat, bool es)
    : Materiales(numCal, numCa, ti, au, estado, pa), tipoMaterial(tipoMat), formatoMaterial(formatoMat),estado(es)  {
}


string MaterialDigital::get_tipo_material() const {
    return tipoMaterial;
}

void MaterialDigital::set_tipo_material(const string &tipo_material) {
    tipoMaterial = tipo_material;
}

string MaterialDigital::get_formato_material() const {
    return formatoMaterial;
}

void MaterialDigital::set_formato_material(const string &formato_material) {
    formatoMaterial = formato_material;
}
bool MaterialDigital::get_estado_acceso() const {
    return estado;
}
void MaterialDigital::set_estado_acceso(bool es) {
    estado = es;
}

int MaterialDigital::get_dia_prestamo() const {
    return 5;
}

string MaterialDigital::toString() {
    stringstream ss;
    ss << Materiales::toString();
       ss << "Tipo de Material: " << get_tipo_material() << ","
       << "Formato: " << get_formato_material() << ","
      // << "Dias de Prestamo: " << get_dia_prestamo() << ","
       << "Estado: " << (get_estado_acceso() ? "Activo" : "Inactivo")  << ",";
    return ss.str();
}

