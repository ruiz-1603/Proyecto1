//
// Created by bryan on 25/03/2025.
//

#ifndef ARTICULO_H
#define ARTICULO_H

#include "MaterialFisico.h"


class Articulo : public MaterialFisico{
public:
    Articulo();
    Articulo(int, int, string, string,string, string,string);

    string getTipo() override;

    string toString() override;
    string toCSV() override;

    int diasPrestamo() override;
};



#endif //ARTICULO_H
