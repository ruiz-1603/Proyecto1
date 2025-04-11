//
// Created by bryan on 26/03/2025.
//

#include "MaterialFisico.h"
MaterialFisico::MaterialFisico(string direccion) : Materiales(), direccion(direccion){
}
MaterialFisico::MaterialFisico(int nu, int num, string t, string a, string es, string pa, string dire) : Materiales(nu, num, t, a, es, pa), direccion(dire){

}

string MaterialFisico::get_direccion() const {
    return direccion;
}

void MaterialFisico::set_direccion(const string &direccion) {
    this->direccion = direccion;
}
string MaterialFisico::toString() {
    stringstream ss;
    ss << Materiales::toString();
    ss << "Ubicacion" << get_direccion() << "\n";
    return ss.str();
}
string MaterialFisico::toCSV() {
    stringstream ss;
    ss << Materiales::toCSV() << "Direccion: " << get_direccion() << ",";
    return ss.str();
}
int MaterialFisico::get_dia_prestamo() {
    int dia = 0;
    if (getTipo()=="Libro") {
        dia = 7;
    }else if (getTipo()=="Revista") {
        dia = 2;
    }else if (getTipo()=="Articulo") {
        dia = 2;
    }
    return dia;
}