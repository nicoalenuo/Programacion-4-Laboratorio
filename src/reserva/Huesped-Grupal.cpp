#include "../../include/reserva/Huesped-Grupal.h"

huespedGrupal::huespedGrupal(){
    (*this).estadiaAsoc=NULL;
    (*this).huespedAsoc=NULL;
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
DTEstadia* huespedGrupal::darDatosEstadia(){
    DTEstadia* send = estadiaAsoc->darDatos();
    return NULL;
}
DTReserva* huespedGrupal::obtenerReserva(){//cambiar por huesped
    return NULL;
}
void huespedGrupal::DarBaja(){
}
bool huespedGrupal::tieneEstFinalizadaDeHus(string email){
    if(huespedAsoc != NULL and estadiaAsoc != NULL and huespedAsoc->getEmail() == email){
        return estadiaAsoc->estaActiva();
    }else{ return false; }
}
bool huespedGrupal::esDeHuesped(string){
    return false;
}