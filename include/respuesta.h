#ifndef RESPUESTA
#define RESPUESTA

#include "DTyEnum/DTRespuesta.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class respuesta{
    private:
        string comentario;
    public:
        respuesta(string);
        ~respuesta();

        string getComentario();
        void setComentario(string);

        DTRespuesta* darDatos();
};

#endif