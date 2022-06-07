#include "../../include/ControladorCalificacion/ControladorCalificacion.h"

ControladorCalificacion* ControladorCalificacion::instancia = NULL;

ControladorCalificacion::~ControladorCalificacion(){
}

ControladorCalificacion::ControladorCalificacion(){
    calificaciones={};
    estadias={};
}

ControladorCalificacion* ControladorCalificacion::getInstance(){
    if (instancia == NULL)
        instancia = new ControladorCalificacion();
    return instancia;
}

void ControladorCalificacion::agregarSuscripto(empleado* e){
    static_cast<IObserver*>(e);
    observers.insert(pair<string,IObserver*>((*e).getEmail(),e));
}

void ControladorCalificacion::eliminarSuscripto(empleado* e){
    observers.erase((*e).getEmail());
}

void ControladorCalificacion::notificarSuscriptos(string nombreAutor,int puntuacion,string comentario){
    map<string,IObserver*>::iterator it;
    for (it=observers.begin() ; it!=observers.end() ; it++){
        (*(*it).second).notificar(nombreAutor,puntuacion,comentario);
    }
}