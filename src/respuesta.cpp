#include "../include/respuesta.h"

respuesta::respuesta(string comentario){
    (*this).comentario=comentario;
}

respuesta::~respuesta(){
}

DTRespuesta*  respuesta::darDatos(){
    DTRespuesta* send = new DTRespuesta((*this).comentario);
    return send;
}