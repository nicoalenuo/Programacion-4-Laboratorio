#ifndef DTCALIFICACION
#define DTCALIFICACION

#include "Date.h" //Agregado

#include <iostream>
#include <stdio.h>
using namespace std;

class DTCalificacion {
    private:
        int id;
        int puntuacion;
        string comentario;
        Date fecha;
    public:
        DTCalificacion(int,int,string,Date);
        ~DTCalificacion();
        
        int getId();
        void setId(int);
        int getPuntuacion();
        void setPuntuacion(int);
        string getComentario();
        void setComentario(string);
        Date getFecha();
        void setFecha(Date);
};

#endif