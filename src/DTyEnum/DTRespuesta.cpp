#include "../../include/DTyEnum/DTRespuesta.h"

DTRespuesta::~DTRespuesta(){
}

DTRespuesta::DTRespuesta(string respuesta){
    (*this).respuesta = respuesta;
}