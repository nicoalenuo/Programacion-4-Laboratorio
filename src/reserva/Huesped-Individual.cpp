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

bool huespedIndividual::tieneEstFinalizadaDeHus(string email){
    if(estadiaAsoc !=NULL and huespedAsoc !=NULL and huespedAsoc->getEmail() == email){
        return estadiaAsoc->estaActiva();
    }
    else{ return false; }
}

bool huespedIndividual::esDeHuesped(string email){
    return huespedAsoc->getEmail()==email;
}

void huespedIndividual::darBaja(){
    estadia* es = estadiaAsoc;
    if(es!= NULL){
        es->eliminarEstadia();
        delete estadiaAsoc;
    }
    estadiaAsoc = NULL;
}

huespedIndividual::~huespedIndividual(){
   
}