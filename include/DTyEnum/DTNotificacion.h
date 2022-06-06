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

        string getNombreAutor() {
            return (*this).nombreAutor;
        }

        void setNombreAutor(string nombreAutor) {
            (*this).nombreAutor = nombreAutor;
        }

        string getComentario() {
            return (*this).comentario;
        }

        void setComentario(string comentario) {
            (*this).comentario = comentario;
        }

        int getPuntuacion() {
            return (*this).puntuacion;
        }

        void setPuntuacion(int puntuacion) {
            (*this).puntuacion = puntuacion;
        }

};

#endif