#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <iostream>
#include <stdio.h>
using namespace std;

class DTNotificacion{
    private:
    string NombreAutor;
    string Comentario;
    int Puntuacion;

    public:
        ~DTNotificacion();
        string getNombreAutor() {
            return (*this).NombreAutor;
        }

        void setNombreAutor(string NombreAutor) {
            (*this).NombreAutor = NombreAutor;
        }

        string getComentario() {
            return (*this).Comentario;
        }

        void setComentario(string Comentario) {
            (*this).Comentario = Comentario;
        }

        int getPuntuacion() {
            return (*this).Puntuacion;
        }

        void setPuntuacion(int Puntuacion) {
            (*this).Puntuacion = Puntuacion;
        }

};

#endif