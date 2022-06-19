#include "../include/respuesta.h"

respuesta::respuesta(string comentario){
    (*this).comentario=comentario;
}

string respuesta::getComentario(){
    return (*this).comentario;
}

void respuesta::setComentario(string com){
    (*this).comentario=com;
}

respuesta::~respuesta(){
}

DTRespuesta*  respuesta::darDatos(){
    DTRespuesta* send = new DTRespuesta((*this).comentario);
    return send;
}