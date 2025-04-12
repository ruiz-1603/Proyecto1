#include "GestorArchivos.cpp"
#include "Menu.h"

int main() {
/*
    Lista<Prestamo>* listaPrestamos = new Lista<Prestamo>();

    Usuario* u1 = new Usuario(1,"Karla",1);
    Usuario* u2 = new Usuario(2,"Johanna",1);
    Usuario* u3 = new Usuario(2,"Johanna",0);



    Materiales* libro = new Libro(101, 201, "Cien Años de Soledad", "García Márquez", "Disponible", "Literatura", "Estante A1");
    Materiales* revista = new Revista(102, 202, "National Geographic", "Varios", "Disponible", "Ciencia", "Estante B2", 34, 5);
    Materiales* video = new Video(103, 203, "La Teoría del Todo", "James Marsh", "Física, Biografía", "Disponible", "Cine", "MP4", true);

    Prestamo* p1 = new Prestamo(1,u1,libro,"15/15/45","15/78/87");
    Prestamo* p2 = new Prestamo(2,u2,revista,"15/15/45","15/78/87");
    Prestamo* p3 = new Prestamo(3,u3,video,"15/15/45","15/78/87");
    listaPrestamos->agregarALista(p1);
    listaPrestamos->agregarALista(p2);
    listaPrestamos->agregarALista(p3);


    GestorArchivos<Prestamo>::guardarPrestamos(listaPrestamos, "prestamos.csv");


    delete listaPrestamos;

    cout << "Archivo 'prestamos.csv' creado correctamente con los datos de los préstamos." << endl;

    */

    Lista<Prestamo>* lista = GestorArchivos<Prestamo>::cargarPrestamos("prestamos.csv");
   cout<<lista->mostrar();
delete lista;


    return 0;
}