#include "../../include/reserva/Huesped-Individual.h"
#include "../../include/DTyEnum/DTEstadia.h"

huespedIndividual::huespedIndividual(){
    (*this).huespedAsoc=NULL;
    (*this).estadiaAsoc=NULL;
}
huespedIndividual::~huespedIndividual(){
}
void huespedIndividual::huespedIndividual::finalizarEstadiaActiva(string emailHuesped){
    huesped* hus=getHuesped();
    string emailHus = (*hus).getEmail();
    if (emailHuesped==emailHus){
        estadia* es=getEstadia();
        if (es!=NULL){
            (*es).finalizarEstadiaActiva();
        }
    }
}
DTEstadia* huespedIndividual::darDatosEstadia(){
    DTEstadia* send = estadiaAsoc->darDatos();
    return send;
}
DTReserva* huespedIndividual::obtenerReserva(){//cambiar reserva por huesped
    
    return NULL;
}
void huespedIndividual::DarBaja(){
}
bool huespedIndividual::tieneEstFinalizadaDeHus(string email){
    if(estadiaAsoc !=NULL and huespedAsoc !=NULL and huespedAsoc->getEmail() == email){
        return estadiaAsoc->estaActiva();
    }
    else{ return false; }
}

bool huespedIndividual::esDeHuesped(string){
    return false;
}