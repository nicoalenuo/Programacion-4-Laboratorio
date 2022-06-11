#include "../include/DTyEnum/DTCalificacion.h"
#include "../include/calificacion.h"

DTCalificacion* calificacion::darDatos(){
    DTCalificacion* resultado = new DTCalificacion((*this).id,(*this).puntuacion,(*this).comentario,(*this).fecha);
    return resultado;
}