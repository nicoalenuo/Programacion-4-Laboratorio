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
    bool t=estaActiva();
    FechaSistema* fs=FechaSistema::getInstance();
    Date fechaActual = (*fs).getFechaActual();
    if (t){
        setFechaSalida(fechaActual);
    }
}