#include "../../include/reserva/Huesped-Grupal.h"

void huespedGrupal::finalizarEstadiaActiva(string emailHuesped){
    huesped* hus=getHuesped();
    string emailHus = (*hus).getEmail();
    if (emailHuesped==emailHus){
        estadia* es=getEstadia();
        if (es!=NULL){
            (*es).finalizarEstadiaActiva();
        }
    }
}

DTEstadia* huespedGrupal::obtenerEstadia(){
    DTEstadia* pDTe;
    DTEstadia dte= DTEstadia(estadiaAsoc->getFechaEntrada(),estadiaAsoc->getFechaSalida(),estadiaAsoc->getCodigo());
    (*pDTe) = dte;
    return pDTe;
}