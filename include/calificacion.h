#ifndef CALIFICACION
#define CALIFICACION

#include "DTyEnum/Date.h"
#include "respuesta.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class calificacion{
    private:
        respuesta* respuesta;

        int id;
        int puntuacion;
        string comentario;
        Date fecha;
    public:
        int getId();
        int getPuntuacion();
        string getComentario();
        Date getFecha();
        void setId(int);
        void setPuntuacion(int);
        void setComentario(string);
        void setFecha(Date); 
        bool sinRespuesta();
        void removerCalificacion();
        DTRespuesta* obtenerRespuesta();
        void ingresarRespuesta(string);
        DTCalificacion* getDatosCalificacion();
        ~calificacion();  
};

#endif