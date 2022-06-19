#include "../../include/DTyEnum/DTNotificacion.h"

DTNotificacion::~DTNotificacion(){
}

string DTNotificacion::getNombreAutor() {
    return (*this).nombreAutor;
}

void DTNotificacion::setNombreAutor(string nombreAutor) {
    (*this).nombreAutor = nombreAutor;
}

string DTNotificacion::getComentario() {
    return (*this).comentario;
}

void DTNotificacion::setComentario(string comentario) {
    (*this).comentario = comentario;
}

int DTNotificacion::getPuntuacion() {
    return (*this).puntuacion;
}

void DTNotificacion::setPuntuacion(int puntuacion) {
    (*this).puntuacion = puntuacion;
}

DTNotificacion::DTNotificacion(string nombreAutor,string comentario, int puntuacion){
    (*this).nombreAutor=nombreAutor;
    (*this).comentario=comentario;
    (*this).puntuacion=puntuacion;
}