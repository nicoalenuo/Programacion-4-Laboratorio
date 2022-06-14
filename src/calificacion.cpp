#include "../include/DTyEnum/DTCalificacion.h"
#include "../include/calificacion.h"
#include "../include/fabrica.h"

DTCalificacion* calificacion::darDatos(){
    DTCalificacion* resultado = new DTCalificacion((*this).id,(*this).puntuacion,(*this).comentario,(*this).fecha);
    return resultado;
}
calificacion::~calificacion(){}
 void calificacion::eliminarCalificacion(){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    IControladorCalificacion* cc = (*f).getIControladorCalificacion();
    hostal* hos = ch->hostalQuePoseeCal(this);
    cc->eliminarCalificacion(this);
    if(respuestaAsoc!=NULL){
        delete respuestaAsoc;
    }
 }
