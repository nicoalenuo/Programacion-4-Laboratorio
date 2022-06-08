#include "../include/notificacion.h"

notificacion::~notificacion(){
}

notificacion::notificacion(string nombreAutor,  int puntuacion,string comentario){
    (*this).nombreAutor=nombreAutor;
    (*this).puntuacion=puntuacion;
    (*this).comentario=comentario;
}

DTNotificacion* notificacion::darDatos(){
    DTNotificacion* resultado = new DTNotificacion((*this).nombreAutor,(*this).comentario,(*this).puntuacion);
    return resultado;
}