#ifndef NOTIFICACION
#define NOTIFICACION

#include "DTyEnum/DTNotificacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class notificacion{
    private:
        string nombreAutor;
        int puntuacion;
        string comentario;
    public:
        notificacion(string,int,string); 
        ~notificacion();

        string getNombreAutor();
        int getPuntuacion();
        string getComentario();
        void setNombreAutor(string);
        void setPuntuacion(int);
        void setComentario(string);    

        DTNotificacion* darDatos();
};

#endif