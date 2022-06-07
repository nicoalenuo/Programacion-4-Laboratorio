#include "../../include/DTyEnum/DTEmpleado.h"

DTEmpleado::~DTEmpleado(){
}

DTEmpleado::DTEmpleado(string nombre,string email,string password,Cargo TipoCargo){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).TipoCargo=TipoCargo;
}