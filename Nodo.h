#ifndef NODO_H
#define NODO_H

template <class Tipo>
class Nodo {
private:
    Tipo* dato;
    Nodo* siguiente;

public:
    Nodo();
    Nodo(Tipo*,Nodo<Tipo>* sig = nullptr);
    ~Nodo();

    Tipo* getDato() const;
    void setDato(Tipo* nuevoDato);

    Nodo<Tipo>* getSiguiente() const;
    void setSiguiente(Nodo<Tipo>* nuevoSiguiente);
};

template <class Tipo>
Nodo<Tipo>::Nodo() : dato(nullptr), siguiente(nullptr) {}

template <class Tipo>
Nodo<Tipo>::Nodo(Tipo* dato,Nodo<Tipo>* sig) : dato(dato), siguiente(sig) {}

template <class Tipo>
Nodo<Tipo>::~Nodo() {
}

template <class Tipo>
Tipo* Nodo<Tipo>::getDato() const {
    return dato;
}

template <class Tipo>
void Nodo<Tipo>::setDato(Tipo* nuevoDato) {
    dato = nuevoDato;
}

template <class Tipo>
Nodo<Tipo>* Nodo<Tipo>::getSiguiente() const {
    return siguiente;
}

template <class Tipo>
void Nodo<Tipo>::setSiguiente(Nodo<Tipo> *nuevoSiguiente) {
    siguiente = nuevoSiguiente;
}
#endif // NODO_H
