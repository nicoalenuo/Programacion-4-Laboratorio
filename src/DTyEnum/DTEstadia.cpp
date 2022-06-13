#include "../../include/DTyEnum/DTEstadia.h"

DTEstadia::DTEstadia(Date fechaEntrada, Date* fechaSalida, int codigo){
    (*this).fechaEntrada=fechaEntrada;
    (*this).fechaSalida=fechaSalida;
    (*this).codigo=codigo;
}
DTEstadia::~DTEstadia(){
}