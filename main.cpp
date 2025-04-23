
#include "Menu.h"

int main() {
      /*Coleccion* coleccion = new Coleccion();
      coleccion->cargarDatos();
      coleccion->reporteMaterialesPrestados();*/

      //delete coleccion;

    Menu* interfaz = new Menu();
    interfaz->menuPrincipal();
    delete interfaz;
/*
    Usuario* u1 = new Usuario(1,"Juan",1);
    Usuario* u2 = new Usuario(2,"Carlos",0);
    Usuario* u3 = new Usuario(3,"Marcela",1);
    Usuario* u4 = new Usuario(4,"Kimberly",1);
    Usuario* u5 = new Usuario(5,"Naomi",1);
    Usuario* u6 = new Usuario(6,"Josselyn",1);
    Usuario* u7 = new Usuario(7,"Priscila",2);
    Usuario* u8 = new Usuario(8,"Paulina",1);


    Lista<Usuario>* listaUsuarios = new Lista<Usuario>();
    listaUsuarios->agregarALista(u1);
    listaUsuarios->agregarALista(u2);
    listaUsuarios->agregarALista(u3);
    listaUsuarios->agregarALista(u4);
    listaUsuarios->agregarALista(u5);
    listaUsuarios->agregarALista(u6);
    listaUsuarios->agregarALista(u7);
    listaUsuarios->agregarALista(u8);

    Materiales* libro1 = new Libro(101, 5, "Cien Años de Soledad", "Gabriel Garcia Marquez", "Disponible", "Realismo Magico", "Estanteria A");
    Materiales* libro2 = new Libro(102, 6, "El Principito", "Antoine de Saint-Exupery", "Prestado", "Fabula", "Estanteria B");

    Materiales* revista1 = new Revista(201, 7, "National Geographic", "Varios Autores", "Disponible", "Ciencia", "Estanteria C", 145, 12);
    Materiales* revista2 = new Revista(202, 8, "Time", "Equipo Editorial", "Disponible", "Actualidad", "Estanteria D", 567, 48);

    Materiales* video1 = new Video(301, 9, "Planeta Tierra", "BBC", "Naturaleza", "Disponible", "Documental", "MP4", true);
    Materiales* video2 = new Video(302, 10, "Aprendiendo C++", "CodeAcademy", "Programación", "Disponible", "Tutorial", "AVI", true);

    Materiales* articulo1 = new Articulo(85, 1001, "Inteligencia Artificial en la Educación", "María Rodríguez", "Disponible", "IA educación tecnología", "Aula 203 Edificio B");
    Materiales* articulo2 = new Articulo(92, 1002, "Impacto del Cambio Climático en la Biodiversidad", "Carlos Méndez", "Prestado", "ecología sostenibilidad medio ambiente", "Sección C Biblioteca Central");

    Lista<Materiales>* listaMateriales = new Lista<Materiales>();
    listaMateriales->agregarALista(libro1);
    listaMateriales->agregarALista(libro2);
    listaMateriales->agregarALista(revista1);
    listaMateriales->agregarALista(revista2);
    listaMateriales->agregarALista(video1);
    listaMateriales->agregarALista(video2);
    listaMateriales->agregarALista(articulo1);
    listaMateriales->agregarALista(articulo2);

    Lista<Prestamo>* listaPrestamos = new Lista<Prestamo>();
    Prestamo* p1 = new Prestamo(1, u1, libro1, "2025-04-01", "2025-04-15");
    Prestamo* p2 = new Prestamo(2, u2, libro2, "2025-04-03", "2025-04-17");
    Prestamo* p3 = new Prestamo(3, u3, revista1, "2025-04-05", "2025-04-19");
    Prestamo* p4 = new Prestamo(4, u4, revista2, "2025-04-07", "2025-04-21");
    Prestamo* p5 = new Prestamo(5, u5, video1, "2025-04-09", "2025-04-23");
    Prestamo* p6 = new Prestamo(6, u6, video2, "2025-04-11", "2025-04-25");
    Prestamo* p7 = new Prestamo(7, u6, articulo1, "2025-04-11", "2025-04-25");
    Prestamo* p8 = new Prestamo(8, u6, articulo2, "2025-04-11", "2025-04-25");

    listaPrestamos->agregarALista(p1);
    listaPrestamos->agregarALista(p2);
    listaPrestamos->agregarALista(p3);
    listaPrestamos->agregarALista(p4);
    listaPrestamos->agregarALista(p5);
    listaPrestamos->agregarALista(p6);
    listaPrestamos->agregarALista(p7);
    listaPrestamos->agregarALista(p8);

    GestorArchivos<Usuario>::guardarUsuarios(listaUsuarios,"Usuarios.csv");
    GestorArchivos<Materiales>::guardarMateriales(listaMateriales,"Materiales.csv");
    GestorArchivos<Prestamo>::guardarPrestamos(listaPrestamos,"Prestamos.csv");
    delete listaUsuarios;
    delete listaMateriales;
    delete listaPrestamos;
*/
    return 0;
}