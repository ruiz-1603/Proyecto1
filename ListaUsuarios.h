//
// Created by bryan on 05/04/2025.
//

#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include "Lista.h"
#include "Usuario.h"

class ListaUsuarios {
private:
    Lista<Usuario>* usuarios;
public:
    ListaUsuarios();
    void agregarUsuario(Usuario*);
    void mostrarUsuarios();
    Usuario* buscarUsuarioPorId(int);
   // Usuario* buscarUsuarioPorNumero(int); No creo utilizarla, quiza en el Menu
    void eliminarUsuarioPorId(int);
    Lista<Usuario>* getCatalogoUsuarios() {return usuarios;}

};

#endif //LISTAUSUARIOS_H
