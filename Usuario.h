//
// Created by bryan on 26/03/2025.
//

#ifndef USUARIO_H
#define USUARIO_H

#include "Utilities.h"

class Usuario {
private:
    int id;
    string nombreCompleto; //usar gerline luego
    bool estado;
public:
    Usuario();
    Usuario(int, string, bool);

    int getId() const;

    void set_id(int id);

    string get_nombre_completo() const;

    void set_nombre_completo(const string &nombre_completo);

    bool is_estado() const;

    void set_estado(bool estado);

    string toString();
};



#endif //USUARIO_H
