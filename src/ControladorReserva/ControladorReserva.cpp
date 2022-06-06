#include "../../include/ControladorReserva/ControladorReserva.h"

ControladorReserva* ControladorReserva::instancia = NULL;

ControladorReserva::ControladorReserva(){
    reservas={};

    datosReserva=NULL;
    datosIndividual=NULL;
    datosGrupal=NULL;
}

ControladorReserva* ControladorReserva::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorReserva();
    return instancia; 
}
