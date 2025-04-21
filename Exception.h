//
// Created by bryan on 20/4/2025.
//

#ifndef EXCEPTION_H
#define EXCEPTION_H



#include <exception>
#include <string>

using namespace std;
class Exception : public exception{
private:
    string mensaje;
public:
    explicit Exception(string mensaje = "Error en sistema");
    const char* what() const noexcept override;
};


#endif //EXCEPTION_H
