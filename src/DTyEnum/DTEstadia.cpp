#include "../../include/DTyEnum/DTEstadia.h"

DTEstadia::~DTEstadia(){
}

Date DTEstadia::getFechaEntrada(){
    return fechaEntrada;
}

Date* DTEstadia::getFechaSalida(){
    return fechaSalida;
}

int DTEstadia::getCodigo(){
    return codigo;
}

void DTEstadia::setFechaEntrada(Date fe){
    fechaEntrada=fe;
}

void DTEstadia::setFechaSalida(Date* fs){
    fechaSalida=fs;
}

void DTEstadia::setCodigo(int c){
    codigo=c;
}

DTEstadia::DTEstadia(Date fechaEntrada, Date* fechaSalida, int codigo){
    (*this).fechaEntrada= fechaEntrada;
    (*this).fechaSalida= fechaSalida;
    (*this).codigo = codigo;
}