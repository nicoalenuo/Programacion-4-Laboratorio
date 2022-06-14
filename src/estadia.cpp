#include "../include/estadia.h"
#include "../include/FechaSistema.h"

estadia::estadia(DTEstadia* est){
    this->fechaEntrada = est->getFechaEntrada();
    this->fechaSalida = est->getFechaSalida();
    this->codigo = est->getCodigo();
}

bool estadia::estaActiva(){
    return false;
}

void estadia::finalizarEstadiaActiva(){
    FechaSistema* fs=FechaSistema::getInstance();
    Date* fechaActual;
    (*fechaActual)=(*fs).getFechaActual();
    if (estaActiva()){
        setFechaSalida(fechaActual);
    }
}