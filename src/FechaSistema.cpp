#include "../include/FechaSistema.h"

FechaSistema* FechaSistema::instancia = NULL;

FechaSistema::FechaSistema(){
    FechaActual=Date();
}

void FechaSistema::setFechaActual(Date fecha){
    (*this).FechaActual=fecha;
}

Date FechaSistema::getFechaActual(){
    return (*this).FechaActual;
}

FechaSistema* FechaSistema::getInstance(){
    if (instancia == NULL)
        instancia = new FechaSistema();
    return instancia;
}
