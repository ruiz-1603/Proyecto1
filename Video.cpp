//
// Created by bryan on 25/03/2025.
//

#include "Video.h"

Video::Video() : MaterialDigital() {}
// numCal, numCat, titulo, autor, PalabrasClave, estado, tipoMaterial, formatoMaterial, estado
Video::Video(int numCal, int numCat, string titulo, string autor, string palClaves, string estado, string tipoMaterial, string formatoMaterial, bool _estado)
: MaterialDigital(numCal, numCat, titulo, autor, palClaves, estado, tipoMaterial, formatoMaterial, _estado) {}
Video::~Video() {}

string Video::getTipo() {
    return "Video";
}

string Video::toString() {
    stringstream ss;
    ss << MaterialDigital::toString();
    return ss.str();
}

int Video::diasPrestamo() { return 5; }