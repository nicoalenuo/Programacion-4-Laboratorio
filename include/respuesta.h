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

        string getComentario(){
            return (*this).comentario;
        }
        void setComentario(string com){
            (*this).comentario=com;
        }

        DTRespuesta* darDatos();
};

#endif