#include "../../include/reserva/Huesped-Individual.h"

void huespedIndividual::finalizarEstadiaActiva(string emailHuesped){
    huesped* hus=getHuesped();
    string emailHus = (*hus).getEmail();
    if (emailHuesped==emailHus){
        estadia* es=getEstadia();
        if (es!=NULL){
            (*es).finalizarEstadiaActiva();
        }
    }
}

DTEstadia* huespedIndividual::obtenerEstadia(){
    DTEstadia* pDTe;
    DTEstadia dte= DTEstadia(estadiaAsoc->getFechaEntrada(),estadiaAsoc->getFechaSalida(),estadiaAsoc->getCodigo());
    (*pDTe)= dte;
    return pDTe;
}