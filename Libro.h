//
// Created by bryan on 25/03/2025.
//

#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialFisico.h"

class Libro : public MaterialFisico {

public:
    Libro(int, int, string, string,string, string,string);
    Libro();

    string getTipo() override;

    string toString() override;

    int diasPrestamo() override;
};



#endif //LIBRO_H
