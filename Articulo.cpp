//
// Created by bryan on 25/03/2025.
//

#include "Articulo.h"
Articulo::Articulo() : MaterialFisico(){
}
Articulo::Articulo(int numCal, int numCa,string ti, string au, string es, string pa,string dire) : MaterialFisico(numCal,numCa,ti,au,es,pa,dire) {
}
string Articulo::getTipo() {
    return "Articulo";
}
string Articulo::toString() {
    stringstream ss;
    ss << MaterialFisico::toString();
    return ss.str();
}

int Articulo::diasPrestamo() { return 7;}
