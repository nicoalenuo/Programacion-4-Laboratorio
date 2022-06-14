#include "../include/DTyEnum/DTCalificacion.h"
#include "../include/calificacion.h"

DTCalificacion* calificacion::darDatos(){
    DTCalificacion* resultado = new DTCalificacion((*this).id,(*this).puntuacion,(*this).comentario,(*this).fecha);
    return resultado;
}

calificacion::calificacion(int id,int puntuacion,string comentario,Date fecha){
    (*this).id=id;
    (*this).puntuacion=puntuacion;
    (*this).comentario=comentario;
    (*this).fecha=fecha;
    (*this).respuestaAsoc=NULL;
}

bool calificacion::sinRespuesta(){
    return (getRespuesta()==NULL);
}

calificacion::~calificacion(){
}