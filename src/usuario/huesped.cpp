#include "../../include/usuario/huesped.h"

huesped::~huesped(){

}

string huesped::getNombre(){
    return nombre;
}

string huesped::getEmail(){
    return email;
}

string huesped::getPassword(){
    return password;
}

bool huesped::getEsFinger(){
    return esFinger;
}

void huesped::setNombre(string n){
    nombre=n;
}

void huesped::setEmail(string e){
    email=e;
}

void huesped::setPassword(string p){
    password=p;
}

void huesped::setEsFinger(bool ef){
    esFinger=ef;
}

huesped::huesped(string nombre, string email, string password, bool esFinger){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).esFinger=esFinger;
}

DTHuesped* huesped::darDatos(){
    DTHuesped* resultado = new DTHuesped((*this).nombre , (*this).email , (*this).password , (*this).esFinger);
    return resultado;
}