#ifndef DTCALIFICACION
#define DTCALIFICACION

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
        
        int getIc(){
            return (*this).id;
        }
        void setId(int id){
            (*this).id = id;
        }
        int getPuntuacion(){
            return (*this).puntuacion;
        }
        void setPuntuacion(int puntuacion){
            (*this).puntuacion = puntuacion;
        }
        string getComentario(){
            return (*this).comentario;
        }
        void setComentario(string comentario){
            (*this).comentario = comentario;
        }
        Date getFecha(){
            return (*this).fecha;
        }
        void setFecha(Date fecha){
            (*this).fecha = fecha;
        }
};

#endif