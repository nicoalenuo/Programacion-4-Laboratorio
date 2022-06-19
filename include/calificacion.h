#ifndef CALIFICACION
#define CALIFICACION

#include "DTyEnum/Date.h"
#include "DTyEnum/DTCalificacion.h"
#include "respuesta.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class calificacion{
    private:
        respuesta* respuestaAsoc;

        int id;
        int puntuacion;
        string comentario;
        Date fecha;
    public:
        calificacion(int,int,string,Date);
        ~calificacion();

        respuesta* getRespuesta();
        int getId();
        int getPuntuacion();
        string getComentario();
        Date getFecha();
        void setRespuesta(respuesta*);
        void setId(int);
        void setPuntuacion(int);
        void setComentario(string);
        void setFecha(Date);
        
        DTCalificacion* darDatos();
        bool sinRespuesta();
        void removerCalificacion();
        void eliminarCalificacion();
        DTRespuesta* obtenerRespuesta();
        void ingresarRespuesta(string);
        DTCalificacion* getDatosCalificacion(); 
};
#endif