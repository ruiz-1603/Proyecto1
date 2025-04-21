//
// Created by bryan on 20/4/2025.
//

#include "Exception.h"

Exception::Exception(string men) :mensaje(men){
}
const char *Exception::what() const noexcept {
    return mensaje.c_str();
}