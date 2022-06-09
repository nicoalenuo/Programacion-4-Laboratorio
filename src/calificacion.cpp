#include "../include/calificacion.h"
#include "../include/DTyEnum/DTCalificacion.h"

calificacion::calificacion(int id,int puntuacion,string comentario,Date fecha){
    (*this).id=id;
    (*this).puntuacion=puntuacion;
    (*this).comentario=comentario;
    (*this).fecha=fecha;
}
calificacion::~calificacion(){
}
DTCalificacion* calificacion::darDatos(){
    DTCalificacion* resultado = new DTCalificacion((*this).id,(*this).puntuacion,(*this).comentario,(*this).fecha);
    return resultado;
}
bool calificacion::sinRespuesta(){
    return (getRespuesta==NULL) ? true:false;
}
void calificacion::removerCalificacion(){

}
DTRespuesta* calificacion::obtenerRespuesta(){
    DTRespuesta* send = (*this).respuestaAsoc->darDatos();
    return send;
}
void calificacion::ingresarRespuesta(string){

}
DTCalificacion* calificacion::getDatosCalificacion(){
    return NULL;
}
