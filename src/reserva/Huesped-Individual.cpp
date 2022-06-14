#include "../../include/reserva/Huesped-Individual.h"

huespedIndividual::huespedIndividual(huesped* hues){
    this->estadiaAsoc = NULL; //Inicialmente no existe una estadia
    this->huespedAsoc = hues;
}

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