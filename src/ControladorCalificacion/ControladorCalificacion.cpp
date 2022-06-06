#include "../../include/ControladorCalificacion/ControladorCalificacion.h"

ControladorCalificacion* ControladorCalificacion::instancia = NULL;

ControladorCalificacion::ControladorCalificacion(){
    calificaciones={};
    estadias={};
}

ControladorCalificacion* ControladorCalificacion::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorCalificacion();
    return instancia;
}
