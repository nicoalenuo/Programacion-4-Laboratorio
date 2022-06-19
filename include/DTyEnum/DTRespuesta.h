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
        
        string getComentario();
        void setComentario(string);

};

#endif