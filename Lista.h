#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Materiales.h"
#include "Usuario.h"
#include"Prestamo.h"

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

    tipo *buscarEnListaPrestamo(int id);

    bool eliminar(int);
    bool eliminarEnListaPrestamo(int);
    bool eliminarEnLista(const string& nombre);
    void eliminarEnListaUsua(int);
    void eliminarPrimero();
    Nodo<tipo>* obtenerPrimero();
    tipo* buscarPorNumero(int num);
    string mostrarMenu();
    bool estaVacia() const;
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
    string nom = nombre;

    for (char& c : nom) {
        c = tolower(c);
    }
    while (actual != nullptr) {
        string tituloLower = actual->getDato()->get_titulo();
        for (char& c : tituloLower) {
            c = tolower(c);
        }
        if (tituloLower == nom) {
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
        if (actual->getDato()->getId() == id) {
            aux = actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return aux;
}
template<class tipo>
tipo* Lista<tipo>::buscarEnListaPrestamo(int id) {
    actual = primero;
    Prestamo* aux = nullptr;
    while (actual != nullptr) {
        if (actual->getDato()->getId() == id) {
            aux = actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return aux;
}
template<class tipo>
bool Lista<tipo>::eliminarEnLista(const string& nombre) {
    Nodo<Materiales>* temp = primero;
    Nodo<Materiales>* anterior = nullptr;
    string nom = nombre;

    for (char& c : nom) {
        c = tolower(c);
    }

    while (temp) {
        string tituloLower = temp->getDato()->get_titulo();
        for (char& c : tituloLower) {
            c = tolower(c);
        }
        if (tituloLower == nom) {
            if (anterior) {
                anterior->setSiguiente(temp->getSiguiente());
            } else {
                primero = temp->getSiguiente();
            }
            delete temp;
            return true;
        }
        anterior = temp;
        temp = temp->getSiguiente();
    } return false;
}
template<class tipo>
void Lista<tipo>::eliminarEnListaUsua(int id) {
    Nodo<Usuario>* temp = primero;
    Nodo<Usuario>* anterior = nullptr;

    while (temp) {
        if (temp->getDato()->getId() == id) {
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
bool Lista<tipo>::eliminar(int id) {
    Nodo<tipo>* temp = primero;
    Nodo<tipo>* anterior = nullptr;

    while (temp) {
        if (temp->getDato()->getId() == id) {
            if (anterior) {
                anterior->setSiguiente(temp->getSiguiente());
            } else {
                primero = temp->getSiguiente();
            }
            delete temp->getDato();
            delete temp;
            return true;
        }
        anterior = temp;
        temp = temp->getSiguiente();
    }
    return false;
}
template<class tipo>
bool Lista<tipo>::eliminarEnListaPrestamo(int id) {
    Nodo<tipo>* temp = primero;
    Nodo<tipo>* anterior = nullptr;

    while (temp) {
        if (temp->getDato()->getId() == id) {
            if (anterior) {
                anterior->setSiguiente(temp->getSiguiente());
            } else {
                primero = temp->getSiguiente();
            }
            delete temp;
            return true;
        }
        anterior = temp;
        temp = temp->getSiguiente();
    }
    return false;
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
template<class tipo>
bool Lista<tipo>::estaVacia() const {
    return primero == nullptr;
}

#endif // LISTA_H
