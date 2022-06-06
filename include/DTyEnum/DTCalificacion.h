#ifndef DTCALIFICACION
#define DTCALIFICACION

#include <iostream>
#include <stdio.h>
using namespace std;

class DTCalificacion {
    private:
        int ID;
        int Puntuacion():int
        string Comentario();
        Date Fecha;

    public:
        ~DTCalificacion();
        int getID() {
            return (*this).ID;
        }

        void setID(int ID) {
            (*this).ID = ID;
        }

        int getPuntuacion():Int() {
            return (*this).Puntuacion():int;
        }

        void setPuntuacion():Int(int Puntuacion():int) {
            (*this).Puntuacion():int = Puntuacion():int;
        }

        string getComentario() {
            return (*this).Comentario();
        }

        void setComentario()(string Comentario()) {
            (*this).Comentario() = Comentario();
        }

        Date getFecha() {
            return (*this).Fecha;
        }

        void setFecha(Date Fecha) {
            (*this).Fecha = Fecha;
        }
};

#endif