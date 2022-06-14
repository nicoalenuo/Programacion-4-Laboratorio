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

DTEstadia* huespedGrupal::obtenerEstadia(){
    DTEstadia* pDTe= NULL;
    if(estadiaAsoc!=NULL){
        pDTe= new DTEstadia(estadiaAsoc->getFechaEntrada(),estadiaAsoc->getFechaSalida(),estadiaAsoc->getCodigo());
    }
    return pDTe;
}

bool huespedGrupal::tieneEstadia(DTEstadia* dte){
    return (*estadiaAsoc).getCodigo() == (*dte).getCodigo();
}

DTHuesped* huespedGrupal::darDatosHuesped(){
    DTHuesped* resultado = new DTHuesped((*huespedAsoc).getNombre() , (*huespedAsoc).getEmail() , (*huespedAsoc).getPassword() , (*huespedAsoc).getEsFinger());
    return resultado;
}

bool huespedGrupal::tieneEstFinalizadaDeHus(string email){
    if(huespedAsoc != NULL and estadiaAsoc != NULL and huespedAsoc->getEmail() == email){
        return estadiaAsoc->estaActiva();
    }else{ return false; }
}

bool huespedGrupal::esDeHuesped(string email){
    return huespedAsoc->getEmail() == email;
}

void huespedGrupal::darBaja(){
    estadia* es = estadiaAsoc;
    if(es!= NULL){
        es->eliminarEstadia();
        delete estadiaAsoc;
    }
    estadiaAsoc = NULL;
}

huespedGrupal::~huespedGrupal(){
   
}