//
// Created by RuizM on 4/7/2025.
//
#include"Lista.h"
#include"Articulo.h"
#include"Libro.h"
#include"Video.h"
#include"Revista.h"
#include"ListaUsuarios.h"
#include"MaterialDigital.h"
#include"MaterialFisico.h"
#include"Prestamo.h"
#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
template <class Tipo>
class GestorArchivos {
public:
    // Formato de cada línea:
    // idPrestamo,idUsuario,tituloMaterial,fechaPrestamo,fechaVencimiento
    void guardarPrestamos(Lista<Prestamo>& catalogo, const string& nombreArchi);
    void cargarPrestamos(Lista<Prestamo>& catalogo, const string& nombreArchi);

    // idUsuario,nombreCompleto,estado
    void guardarUsuarios(Lista<Usuario>& catalogo, const string& nombreArchi);
    void cargarUsuarios(Lista<Usuario>& catalogo, const string& nombreArchi);

    // Video,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,tipoMaterial,formatoMaterial,estadoAcceso
    // Revista,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,direccion
    void guardarMateriales(Lista<Materiales>& catalogo, const string& nombreArchi);
    void cargarMateriales(Lista<Materiales>& catalogo, const string& nombreArchi);
};



#endif //GESTORARCHIVOS_H
