#include "Video.h"

Video::Video() : MaterialDigital() {}
// numCal, numCat, titulo, autor, PalabrasClave, estado, tipoMaterial, formatoMaterial, estado
Video::Video(int numCal, int numCat, string titulo, string autor, string palClaves, string estado, string tipoMaterial, string formatoMaterial, bool _estado)
: MaterialDigital(numCal, numCat, titulo, autor, estado, palClaves, tipoMaterial, formatoMaterial, _estado) {}
Video::~Video() {}

string Video::getTipo() {
    return "Video";
}

string Video::toString() {
    stringstream ss;
    ss << MaterialDigital::toString();
    return ss.str();
}
string Video::toCSV() {
    stringstream ss;
    ss << MaterialDigital::toCSV();
    return ss.str();
}

int Video::diasPrestamo() { return 5; }