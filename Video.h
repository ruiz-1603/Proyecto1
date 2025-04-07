//
// Created by bryan on 25/03/2025.
//

#ifndef VIDEO_H
#define VIDEO_H

#include "MaterialDigital.h"

class Video : public MaterialDigital {
private:

public:
    Video();
    // numCal, numCat, titulo, autor, PalabrasClave, estado, tipoMaterial, formatoMaterial, estado
    Video(int, int, string, string, string, string, string, string, bool);
    ~Video();

    string getTipo() override;

    string toString() override;

    int diasPrestamo() override;
};

#endif //VIDEO_H
