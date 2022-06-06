#ifndef RESPUESTA
#define RESPUESTA

#include <iostream>
#include <stdio.h>
using namespace std;

class respuesta{
    private:
        string comentario;
    public:
        string getComentario();
        void setComentario(string);
        
};

#endif