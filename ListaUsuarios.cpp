//
// Created by bryan on 05/04/2025.
//

#include "ListaUsuarios.h"
ListaUsuarios::ListaUsuarios() {
    usuarios = new Lista<Usuario>();
}

void ListaUsuarios::agregarUsuario(Usuario* usuario) {
    usuarios->agregarALista(usuario);
}

void ListaUsuarios::mostrarUsuarios() {
    cout << usuarios->mostrar() << endl;
}
Usuario* ListaUsuarios::buscarUsuarioPorId(int id) {
    return usuarios->buscarEnListaUsua(id);
}
void ListaUsuarios::eliminarUsuarioPorId(int id) {
    usuarios->eliminarEnListaUsua(id);
}