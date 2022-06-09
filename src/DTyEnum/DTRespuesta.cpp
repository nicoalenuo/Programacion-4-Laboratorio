#include "../../include/DTyEnum/DTRespuesta.h"

DTRespuesta::DTRespuesta(string nombre,string email,string password){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
}
DTRespuesta::~DTRespuesta(){
}