#include "../../include/DTyEnum/DTHuesped.h"

DTHuesped::~DTHuesped(){
}

string DTHuesped::getNombre() {
    return (*this).nombre;
}

void DTHuesped::setNombre(string nombre) {
    (*this).nombre = nombre;
}

string DTHuesped::getEmail() {
    return (*this).email;
}

void DTHuesped::setEmail(string email) {
    (*this).email = email;
}

string DTHuesped::getPassword() {
    return (*this).password;
}

void DTHuesped::setPassword(string password) {
    (*this).password = password;
}

bool DTHuesped::getEsFinger() {
    return (*this).esFinger;
}

void DTHuesped::setEsFinger(bool esFinger) {
    (*this).esFinger = esFinger;
}

DTHuesped::DTHuesped(string nombre,string email,string password,bool esFinger){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).esFinger=esFinger;
}