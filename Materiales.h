//
// Created by bryan on 25/03/2025.
//

#ifndef MATERIALES_H
#define MATERIALES_H
#include "Utilities.h"

class Materiales {
private:
    int numCalificacion;
    int numCatalogo;
    string titulo;
    string autor;
    string palabrasClaves;//usar getline luego
    string estado;
public:
    Materiales();
    Materiales(int, int, string, string, string,string);
    ~Materiales();

    int get_num_calificacion() const;

    void set_num_calificacion(int num_calificacion);

    int get_num_catalogo() const;

    void set_num_catalogo(int num_catalogo);

    string get_titulo() const;

    void set_titulo(const string &titulo);

    string get_autor() const;

    void set_autor(const string &autor);

    string get_palabras_claves() const;

    void set_palabras_claves(string);

    string get_estado() const;

    void set_estado(string estado);

    virtual string getTipo() = 0;

    virtual string toString();

    virtual string toCSV();

    virtual int diasPrestamo() = 0;
};



#endif //MATERIALES_H
