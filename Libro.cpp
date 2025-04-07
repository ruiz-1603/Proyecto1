//
// Created by bryan on 25/03/2025.
//

#include "Libro.h"
Libro::Libro() : MaterialFisico(){
}

Libro::Libro(int numCal, int numCa,string ti, string au, string es, string pa,string dire) : MaterialFisico(numCal,numCa,ti,au,es,pa,dire) {
}

string Libro::getTipo() {
    return "Libro";
}
string Libro::toString() {
    stringstream ss;
    ss << MaterialFisico::toString();
    return ss.str();
}

int Libro::diasPrestamo() { return 7;}

