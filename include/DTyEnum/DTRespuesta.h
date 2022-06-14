#ifndef DTRESPUESTA
#define DTRESPUESTA

#include <iostream>
#include <stdio.h>
using namespace std;

class DTRespuesta {
    private:
        string respuesta;
    public:
        DTRespuesta(string);
        ~DTRespuesta();
        
        string getRespuesta() {
            return (*this).respuesta;
        }

        void setRespuesta(string respuesta) {
            (*this).respuesta = respuesta;
        }
};

#endif