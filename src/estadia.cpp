#include "../include/estadia.h"
#include "../include/FechaSistema.h"

bool estadia::estaActiva(){
    return fechaSalida!=NULL;
}

void estadia::finalizarEstadiaActiva(){
    bool t=estaActiva();
    FechaSistema* fs=FechaSistema::getInstance();
    Date* fechaActual;
    (*fechaActual)= (*fs).getFechaActual();
    if (t){
        setFechaSalida(fechaActual);
    }
}