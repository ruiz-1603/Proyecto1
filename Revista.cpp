//
// Created by bryan on 25/03/2025.
//

#include "Revista.h"
Revista::Revista(int numCal, int numCa, string ti, string au, string es, string pa,string dire,int numRevi, int numVolu): MaterialFisico(numCal,numCa,ti,au,es,pa,dire),numRevista(numRevi),volumenRevista(numVolu) {
}
Revista::Revista(int numRevista, int volumenRevista) : MaterialFisico(),numRevista(numRevista),volumenRevista(volumenRevista){
}

int Revista::get_num_revista() const {
    return numRevista;
}

void Revista::set_num_revista(int num_revista) {
    numRevista = num_revista;
}

int Revista::get_volumen_revista() const {
    return volumenRevista;
}

void Revista::set_volumen_revista(int volumen_revista) {
    volumenRevista = volumen_revista;
}
string Revista::getTipo() {
    return "Revista";
}

string Revista::toString() {
    stringstream ss;
    ss << MaterialFisico::toString();
    ss << "Numero de Revista: " << get_num_revista() << ",";
    ss << "Numero de Volumen" << get_volumen_revista() << ",";
    return ss.str();
}

int Revista::diasPrestamo() { return 2;}