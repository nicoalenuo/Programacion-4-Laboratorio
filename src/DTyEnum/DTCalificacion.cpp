#include "../../include/DTyEnum/DTCalificacion.h"

DTCalificacion::~DTCalificacion(){
}

DTCalificacion::DTCalificacion(int id, int puntuacion, string comentario, Date fecha){
    (*this).id=id;
    (*this).puntuacion=puntuacion;
    (*this).comentario=comentario;
    (*this).fecha=fecha;
}