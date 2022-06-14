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

        respuesta* getRespuesta(){
            return respuestaAsoc;
        } 
        int getId(){
            return id;
        }
        int getPuntuacion(){
            return puntuacion;
        }
        string getComentario(){
            return comentario;
        }
        Date getFecha(){
            return fecha;
        }
        void setRespuesta(respuesta* r){
            respuestaAsoc=r;
        }
        void setId(int i){
            id=i;
        }
        void setPuntuacion(int p){
            puntuacion=p;
        }
        void setComentario(string c){
            comentario=c;
        }
        void setFecha(Date d){
            fecha=d;
        }

        DTCalificacion* darDatos();
        bool sinRespuesta();
        void removerCalificacion();
        void eliminarCalificacion();
        DTRespuesta* obtenerRespuesta();
        void ingresarRespuesta(string);
        DTCalificacion* getDatosCalificacion(); 
};
#endif