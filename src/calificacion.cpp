#include "../include/DTyEnum/DTCalificacion.h"
#include "../include/calificacion.h"
#include "../include/fabrica.h"

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

void calificacion::ingresarRespuesta(string res){
    respuesta* set = new respuesta(res);
    setRespuesta(set);
}

calificacion::~calificacion(){
}

void calificacion::eliminarCalificacion(){
    fabrica* f = fabrica::getInstance();
    IControladorHostal* ch = (*f).getIControladorHostal();
    IControladorCalificacion* cc = (*f).getIControladorCalificacion();
    (*ch).quitarCalificacionDeHostal(id);
    cc->eliminarCalificacion(id);
    if(respuestaAsoc!=NULL){
        delete respuestaAsoc;
    }
 }