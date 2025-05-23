#include"Lista.h"
#include"Articulo.h"
#include"Libro.h"
#include"Video.h"
#include"Revista.h"
#include"ListaUsuarios.h"
#include"MaterialDigital.h"
#include"MaterialFisico.h"
#include"Prestamo.h"
#include "Exception.h"

#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
template <class Tipo>
class GestorArchivos {
public:
    // Formato de cada línea:
    // idPrestamo,idUsuario,tituloMaterial,fechaPrestamo,fechaVencimiento
    static void guardarPrestamos(Lista<Prestamo>*, const string&);
    static Lista<Prestamo>* cargarPrestamos(Lista<Usuario>*,Lista<Materiales>*,const string&);

    // idUsuario,nombreCompleto,estado
    static void guardarUsuarios(Lista<Usuario>*,const string&);
    static Lista<Usuario>* cargarUsuarios(const string&);

    // Video,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,tipoMaterial,formatoMaterial,estadoAcceso
    // Revista,numCalificacion,numCatalogo,titulo,autor,palabrasClaves,estado,direccion
    static void guardarMateriales(Lista<Materiales>*, const string&);
    static Lista<Materiales>* cargarMateriales(const string&);
};



#endif //GESTORARCHIVOS_H
