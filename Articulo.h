#ifndef ARTICULO_H
#define ARTICULO_H

#include "MaterialFisico.h"


class Articulo : public MaterialFisico{
public:
    Articulo();
    Articulo(int, int, string, string,string, string,string);

    string getTipo() override;

    string toString() override;

    int diasPrestamo() override;
};



#endif //ARTICULO_H
