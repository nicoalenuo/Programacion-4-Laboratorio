#include "../../include/DTyEnum/DTEmpleado.h"

DTEmpleado::~DTEmpleado(){
}

string DTEmpleado::getNombre() {
    return (*this).nombre;
}

void DTEmpleado::setNombre(string nombre) {
    (*this).nombre = nombre;
}

string DTEmpleado::getEmail() {
    return (*this).email;
}

void DTEmpleado::setEmail(string email) {
    (*this).email = email;
}

string DTEmpleado::getPassword() {
    return (*this).password;
}

void DTEmpleado::setPassword(string password) {
    (*this).password = password;
}

Cargo DTEmpleado::getTipoCargo(){
    return (*this).TipoCargo;
}

void DTEmpleado::setTipoCargo(Cargo c){
    (*this).TipoCargo=c;
}

DTEmpleado::DTEmpleado(string nombre,string email,string password,Cargo TipoCargo){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).TipoCargo=TipoCargo;
}