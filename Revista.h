//
// Created by bryan on 25/03/2025.
//

#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialFisico.h"

class Revista : public MaterialFisico {
private:
    int numRevista;
    int volumenRevista;
public:
    Revista(int, int, string, string,string,string,string, int, int);
    Revista(int numRevista = 0, int volumenRevista = 0);

    int get_num_revista() const;

    void set_num_revista(int);

    int get_volumen_revista() const;

    void set_volumen_revista(int);

    string getTipo() override;

    string toString() override;
    string toCSV() override;

    int diasPrestamo() override;
};



#endif //REVISTA_H
