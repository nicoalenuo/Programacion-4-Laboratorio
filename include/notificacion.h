#ifndef NOTIFICACION
#define NOTIFICACION

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

        string getNombreAutor(){
            return (*this).nombreAutor;
        }
        int getPuntuacion(){
            return (*this).puntuacion;
        }
        string getComentario(){
            return (*this).comentario;
        }
        void setNombreAutor(string nA){
            (*this).nombreAutor=nA;
        }
        void setPuntuacion(int p){
            (*this).puntuacion=p;
        }
        void setComentario(string com){
            (*this).comentario=com;
        }        
};

#endif