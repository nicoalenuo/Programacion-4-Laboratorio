#include "../../include/DTyEnum/DTRespuesta.h"

DTRespuesta::DTRespuesta(string comentario){
    (*this).comentario=comentario;
}

string DTRespuesta::getComentario() {
    return (*this).comentario;
}

void DTRespuesta::setComentario(string comentario) {
    (*this).comentario = comentario;
}

DTRespuesta::~DTRespuesta(){
}