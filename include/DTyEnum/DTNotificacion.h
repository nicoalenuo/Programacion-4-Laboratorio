#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <iostream>
#include <stdio.h>
using namespace std;

class DTNotificacion{
    private:
    string nombreAutor;
    string comentario;
    int puntuacion;

    public:
        DTNotificacion(string,string,int);
        ~DTNotificacion();

        string getNombreAutor();
        void setNombreAutor(string);
        string getComentario();
        void setComentario(string);
        int getPuntuacion();
        void setPuntuacion(int);
        
};

#endif