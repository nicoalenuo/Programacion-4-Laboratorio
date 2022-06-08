#include "../../include/DTyEnum/DTNotificacion.h"

DTNotificacion::~DTNotificacion(){
}

DTNotificacion::DTNotificacion(string nombreAutor,string comentario, int puntuacion){
    (*this).nombreAutor=nombreAutor;
    (*this).comentario=comentario;
    (*this).puntuacion=puntuacion;
}