#include "../include/notificacion.h"

notificacion::~notificacion(){
}

string notificacion::getNombreAutor(){
    return (*this).nombreAutor;
}

int notificacion::getPuntuacion(){
    return (*this).puntuacion;
}

string notificacion::getComentario(){
    return (*this).comentario;
}

void notificacion::setNombreAutor(string nA){
    (*this).nombreAutor=nA;
}

void notificacion::setPuntuacion(int p){
    (*this).puntuacion=p;
}

void notificacion::setComentario(string com){
    (*this).comentario=com;
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