#ifndef DTRESPUESTA
#define DTRESPUESTA

#include <iostream>
#include <stdio.h>
using namespace std;

class DTRespuesta {
    private:
        string comentario;
    public:
        DTRespuesta(string);
        ~DTRespuesta();
        
        string getComentario() {
            return (*this).comentario;
        }

        void setComentario(string comentario) {
            (*this).comentario = comentario;
        }

};

#endif