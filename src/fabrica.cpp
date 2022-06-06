#include "../include/fabrica.h"

fabrica* fabrica::instancia = NULL;

fabrica::fabrica(){
}

fabrica* fabrica::getInstance(){
    if (instancia == NULL)
        instancia = new fabrica();
    return instancia;
}

IControladorHostal* fabrica::getIControladorHostal(){
    return ControladorHostal::getInstance();
}

IControladorReserva* fabrica::getIControladorReserva(){
    return ControladorReserva::getInstance();
}

IControladorCalificacion* fabrica::getIControladorCalificacion(){
    return ControladorCalificacion::getInstance();
}

IControladorUsuario* fabrica::getIControladorUsuario(){
    return ControladorUsuario::getInstance();
}