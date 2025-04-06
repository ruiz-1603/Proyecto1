//
// Created by bryan on 25/03/2025.
//

#ifndef MATERIALDIGITAL_H
#define MATERIALDIGITAL_H

#include "Materiales.h"
//Aqui va Video
class MaterialDigital : public Materiales {
private:
    string tipoMaterial;
    string formatoMaterial;
    bool estado;
    public:
    MaterialDigital(string tipoMaterial = "", string formatoMaterial = "", bool estado = false);
    MaterialDigital(int, int, string, string,string,string,string,string,bool);

    string get_tipo_material() const;

    void set_tipo_material(const string &tipo_material);

    string get_formato_material() const;

    void set_formato_material(const string &formato_material);

    bool get_estado_acceso() const;

    void set_estado_acceso(bool);

    int get_dia_prestamo() const;

    int dia_prestamo() const;

    string toString();
};



#endif //MATERIALDIGITAL_H
