#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Materiales.h"
#include "Usuario.h"

template<class tipo>
class Lista {
private:
    Nodo<tipo>* actual;
    Nodo<tipo>* primero;

public:
    Lista();
    ~Lista();

    void agregarALista(tipo* material);
    string mostrar();
    void limpiarLista();
    tipo* buscarEnLista(const string& nombre);
    tipo* buscarEnListaUsua(int);
    void eliminarEnLista(const string& nombre);
    void eliminarEnListaUsua(int);
    void eliminarPrimero();
    Nodo<tipo>* obtenerPrimero();
    tipo* buscarPorNumero(int num);
    string mostrarMenu();
};

template<class tipo>
Lista<tipo>::Lista() : actual(nullptr), primero(nullptr) {}

template<class tipo>
Lista<tipo>::~Lista() {
    limpiarLista();
}
template<class tipo>
void Lista<tipo>::agregarALista(tipo* material) {
    primero = new Nodo<tipo>(material,primero);
}
template<class tipo>
string Lista<tipo>::mostrar() {
    stringstream ss;
    actual = primero;
    while (actual != nullptr) {
        ss << actual->getDato()->toString() << "\n";
        actual = actual->getSiguiente();
    }
    return ss.str();
}
template<class tipo>
void Lista<tipo>::limpiarLista() {
    while (obtenerPrimero() != nullptr) {
        eliminarPrimero();
    }
}
template<class tipo>
tipo* Lista<tipo>::buscarEnLista(const string& nombre) {
    actual = primero;
    Materiales* aux = nullptr;
    while (actual != nullptr) {
        if (actual->getDato()->get_titulo() == nombre) {
            aux = actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return aux;
}
template<class tipo>
tipo* Lista<tipo>::buscarEnListaUsua(int id) {
    actual = primero;
    Usuario* aux = nullptr;
    while (actual != nullptr) {
        if (actual->getDato()->get_id() == id) {
            aux = actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return aux;
}
template<class tipo>
void Lista<tipo>::eliminarEnLista(const string& nombre) {
    Nodo<Materiales>* temp = primero;
    Nodo<Materiales>* anterior = nullptr;

    while (temp) {
        if (temp->getDato()->get_titulo() == nombre) {
            if (anterior) {
                anterior->setSiguiente(temp->getSiguiente());
            } else {
                primero = temp->getSiguiente();
            }
            delete temp;
            return;
        }
        anterior = temp;
        temp = temp->getSiguiente();
    }
}
template<class tipo>
void Lista<tipo>::eliminarEnListaUsua(int id) {
    Nodo<Usuario>* temp = primero;
    Nodo<Usuario>* anterior = nullptr;

    while (temp) {
        if (temp->getDato()->get_id() == id) {
            if (anterior) {
                anterior->setSiguiente(temp->getSiguiente());
            } else {
                primero = temp->getSiguiente();
            }
            delete temp;
            return;
        }
        anterior = temp;
        temp = temp->getSiguiente();
    }
}
template<class tipo>
Nodo<tipo>* Lista<tipo>::obtenerPrimero() {
    return primero;
}
template<class tipo>
void Lista<tipo>::eliminarPrimero() {
    if (primero) {
        Nodo<tipo>* temp = primero;
        primero = primero->getSiguiente();
        delete temp->getDato();
        delete temp;
    }
}
template<class tipo>
tipo *Lista<tipo>::buscarPorNumero(int num) {
    actual = primero;
    int contador = 1;
    while (actual != nullptr) {
        if (contador == num) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
        contador++;
    }
    return nullptr;
}
template<class tipo>
string Lista<tipo>::mostrarMenu() {
    stringstream ss;
    actual = primero;
    int conta = 1;
    while (actual != nullptr) {
        ss << conta << "--" << actual->getDato()->mostrar() << "\n";
        actual = actual->getSiguiente();
        conta++;
    }
    return ss.str();
}

#endif // LISTA_H
