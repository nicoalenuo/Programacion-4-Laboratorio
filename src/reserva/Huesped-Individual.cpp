#include "../../include/reserva/Huesped-Individual.h"
#include "../../include/fabrica.h"
huespedIndividual::huespedIndividual(huesped* hues){
    this->estadiaAsoc = NULL; //Inicialmente no existe una estadia
    this->huespedAsoc = hues;
}

huespedIndividual::~huespedIndividual(){
   
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
void huespedIndividual::darBaja(){
    estadia* es = estadiaAsoc;
    if(es!= NULL){
        es->eliminarEstadia();
        delete estadiaAsoc;
    }
    estadiaAsoc = NULL;

}