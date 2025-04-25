//
// Created by bryan on 20/4/2025.
//

#include "Limpieza.h"
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void Limpieza::limpiarPantalla() {
    for (int i = 0; i < 100; ++i) std::cout << '\n';
}

void Limpieza::pausar() {
    std::cout << "\nPresione ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
} 