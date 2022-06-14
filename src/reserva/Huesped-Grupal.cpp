#include "../../include/reserva/Huesped-Grupal.h"

huespedGrupal::huespedGrupal(huesped* u){
    this->estadiaAsoc = NULL;
    this->huespedAsoc = u;
}

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