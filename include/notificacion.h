#ifndef NOTIFICACION
#define NOTIFICACION

#include <iostream>
#include <stdio.h>
using namespace std;

class notificacion{
    private:
        string nombreAutor;
        int puntuacion;
        string comentario;
    public:
        string getNombreAutor();
        int getPuntuacion();
        string getComentario();
        void setNombreAutor(string);
        void setPuntuacion(int);
        void setComentario(string);
        
};

#endif