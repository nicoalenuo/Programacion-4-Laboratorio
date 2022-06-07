#include "../include/usuario/empleado.h"
#include "../../include/fabrica.h"

DTEmpleado* empleado::darDatos(){
    DTEmpleado* resultado=new DTEmpleado((*this).nombre , (*this).email , (*this).password , (*this).TipoCargo);
    return resultado;
}

void empleado::suscribirse(){
    fabrica* f = fabrica::getInstance();
    IControladorCalificacion* cc = (*f).getIControladorCalificacion();
    (*cc).agregarSuscripto(this);
}

void empleado::desuscribirse(){
    fabrica* f = fabrica::getInstance();
    IControladorCalificacion* cc = (*f).getIControladorCalificacion();
    (*cc).eliminarSuscripto(this);
}

set<DTNotificacion*> empleado::darNotificaciones(){
    set<DTNotificacion*> nots;
    set<notificacion*>::iterator it;
    for (it=notificaciones.begin() ; it!=notificaciones.end() ; it++){
        nots.insert((*(*it)).darDatos());
        notificacion* aBorrar = (*it);
        notificaciones.erase(aBorrar);
        delete aBorrar;
    }
    return nots;
}

void empleado::notificar(string nombreAutor,int puntuacion,string comentario){
    notificacion* noti=new notificacion(nombreAutor,puntuacion,comentario);
    notificaciones.insert(noti);
}