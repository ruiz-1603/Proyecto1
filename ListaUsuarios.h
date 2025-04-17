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
    void setUsuarios(Lista<Usuario>* nuevaLista);
    Lista<Usuario>* getCatalogoUsuarios() {return usuarios;}

};

#endif //LISTAUSUARIOS_H
