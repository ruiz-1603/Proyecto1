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
    static void guardarPrestamos(Lista<Prestamo>* , const string& );
    static void cargarPrestamos(Lista<Prestamo>* , const string& );

    // idUsuario,nombreCompleto,estado
    static void guardarUsuarios(Lista<Usuario>* usuarios, const string& );
    static void cargarUsuarios(Lista<Usuario>* usuarios, const string& );

    // Video,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,tipoMaterial,formatoMaterial,estadoAcceso
    // Revista,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,direccion
    static void guardarMateriales(Lista<Materiales>*, const string&);
    static void cargarMateriales(Lista<Materiales>* , const string&);
};



#endif //GESTORARCHIVOS_H
