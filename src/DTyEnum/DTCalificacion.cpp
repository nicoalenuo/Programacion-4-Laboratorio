#include "../../include/DTyEnum/DTCalificacion.h"

DTCalificacion::~DTCalificacion(){
}

int DTCalificacion::getId(){ //ACA DECIA GETIC
    return (*this).id;
}
void DTCalificacion::setId(int id){
    (*this).id = id;
}
int DTCalificacion::getPuntuacion(){
    return (*this).puntuacion;
}
void DTCalificacion::setPuntuacion(int puntuacion){
    (*this).puntuacion = puntuacion;
}
string DTCalificacion::getComentario(){
    return (*this).comentario;
}
void DTCalificacion::setComentario(string comentario){
    (*this).comentario = comentario;
}
Date DTCalificacion::getFecha(){
    return (*this).fecha;
}
void DTCalificacion::setFecha(Date fecha){
    (*this).fecha = fecha;
}

DTCalificacion::DTCalificacion(int id, int puntuacion, string comentario, Date fecha){
    (*this).id=id;
    (*this).puntuacion=puntuacion;
    (*this).comentario=comentario;
    (*this).fecha=fecha;
}