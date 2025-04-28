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
bool ListaUsuarios::eliminarUsuarioPorId(int id) {
    return usuarios->eliminar(id);
}

void ListaUsuarios::setUsuarios(Lista<Usuario> *nuevaLista) {
    delete usuarios;  // libera la lista anterior para evitar memory leak
    usuarios = nuevaLista;
}
