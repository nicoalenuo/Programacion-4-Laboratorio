#include "../include/estadia.h"
#include "../include/FechaSistema.h"

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