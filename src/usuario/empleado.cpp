#include "../../include/fabrica.h"

empleado::~empleado(){
    set<notificacion*>::iterator it;
    for (it=notificaciones.begin() ; it!=notificaciones.end() ; it++){
        delete (*it);
    }
}

empleado::empleado(string nombre, string email, string password,Cargo c){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).TipoCargo=c;
}

string empleado::getNombre(){
    return nombre;
}

string empleado::getEmail(){
    return email;
}

string empleado::getPassword(){
    return password;
}

Cargo empleado::getTipoCargo(){
    return TipoCargo;
}

void empleado::setNombre(string n){
    nombre=n;
}

void empleado::setEmail(string e){
    email=e;
}

void empleado::setPassword(string p){
    password=p;
}

void empleado::setTipoCargo(Cargo c){
    TipoCargo=c;
}

void empleado::agregarNotificacionASet(notificacion * n){
    notificaciones.insert(n);
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
        notificacion* aBorrar = (*it);
        delete aBorrar;
    }
    return nots;
}

void empleado::notificar(string nombreAutor,int puntuacion,string comentario){
    notificacion* noti=new notificacion(nombreAutor,puntuacion,comentario);
    notificaciones.insert(noti);
}