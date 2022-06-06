#ifndef RESPUESTA
#define RESPUESTA

#include <iostream>
#include <stdio.h>
using namespace std;

class respuesta{
    private:
        string comentario;
    public:
        string getComentario(){
            return (*this).comentario;
        }
        void setComentario(string com){
            (*this).comentario=com;
        }
        ~respuesta();
        
};

#endif