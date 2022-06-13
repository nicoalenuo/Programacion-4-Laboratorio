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
    DTEstadia* pDTe= NULL;
    if(estadiaAsoc!=NULL){
        pDTe= new DTEstadia(estadiaAsoc->getFechaEntrada(),estadiaAsoc->getFechaSalida(),estadiaAsoc->getCodigo());
    }
    return pDTe;
}

bool huespedIndividual::tieneEstadia(DTEstadia* dte){
    return (*estadiaAsoc).getCodigo() == (*dte).getCodigo();
}

DTHuesped* huespedIndividual::darDatosHuesped(){
    DTHuesped* resultado = new DTHuesped((*huespedAsoc).getNombre() , (*huespedAsoc).getEmail() , (*huespedAsoc).getPassword() , (*huespedAsoc).getEsFinger());
    return resultado;
}