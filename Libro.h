#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialFisico.h"

class Libro : public MaterialFisico {

public:
    Libro(int, int, string, string,string, string,string);
    Libro();

    string getTipo() override;

    string toString() override;
    string toCSV() override;

    int diasPrestamo() override;
};



#endif //LIBRO_H
