#include "../../include/reserva/Huesped-Grupal.h"
huespedGrupal::huespedGrupal(huesped* u){
    this->estadiaAsoc = NULL;
    this->huespedAsoc = u;
}
huespedGrupal::~huespedGrupal(){
   
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

void huespedGrupal::DarBaja(){
    estadia* es = estadiaAsoc;
    if(es!= NULL){
        es->eliminarEstadia();
        delete estadiaAsoc;
    }
    estadiaAsoc = NULL;

}