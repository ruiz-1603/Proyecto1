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
string Libro::toCSV() {
    stringstream ss;
    ss << MaterialFisico::toCSV();
    return ss.str();
}

int Libro::diasPrestamo() { return 7;}

