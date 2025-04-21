cmake_minimum_required(VERSION 3.30)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1 main.cpp
        Materiales.cpp
        Materiales.h
        Libro.cpp
        Libro.h
        Revista.cpp
        Revista.h
        Articulo.cpp
        Articulo.h
        Video.cpp
        Video.h
        MaterialDigital.cpp
        MaterialDigital.h
        Utilities.cpp
        Utilities.h
        MaterialFisico.cpp
        MaterialFisico.h
        Usuario.cpp
        Usuario.h
        Biblioteca.cpp
        Biblioteca.h
        ListaUsuarios.cpp
        ListaUsuarios.h
        Prestamo.cpp
        Prestamo.h
        Coleccion.cpp
        Coleccion.h
        GestorPrestamos.h
        GestorPrestamos.cpp
        Lista.h
        GestorArchivos.cpp
        GestorArchivos.h
        Menu.cpp
        Menu.h
        Limpieza.cpp
        Limpieza.h
        Exception.cpp
        Exception.h)
