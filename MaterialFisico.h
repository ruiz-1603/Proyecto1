#ifndef MATERIALFISICO_H
#define MATERIALFISICO_H

#include "Materiales.h"
//Revista, libro, articulo
class MaterialFisico : public Materiales{
private:
    string direccion;
    public:
    MaterialFisico(string direccion ="");
    MaterialFisico(int, int, string, string, string,string,string);

    string get_direccion() const;

    void set_direccion(const string &direccion);

    string toString() override;

    int get_dia_prestamo();

    string getTipo() override = 0;
};



#endif //MATERIALFISICO_H
