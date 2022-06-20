#include "../../include/fabrica.h"

empleado::~empleado(){
    set<notificacion*>::iterator itN;
    for (itN=notificaciones.begin() ; itN!=notificaciones.end() ; itN++){
        delete (*itN);
    }
}

empleado::empleado(string nombre, string email, string password,Cargo c){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).TipoCargo=c;
}

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
<<<<<<< Updated upstream
        notificacion* aBorrar = (*it);
        notificaciones.erase(aBorrar);
        delete aBorrar;
=======
        delete (*it);
>>>>>>> Stashed changes
    }
    notificaciones.clear();
    return nots;
}

void empleado::notificar(string nombreAutor,int puntuacion,string comentario){
    notificacion* noti=new notificacion(nombreAutor,puntuacion,comentario);
    notificaciones.insert(noti);
}