#include "../../include/DTyEnum/DTEmpleado.h"

DTEmpleado::DTEmpleado(string nombre,string email,string password,Cargo TipoCargo){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).TipoCargo=TipoCargo;
}

DTEmpleado::DTEmpleado(){
    (*this).nombre="0";
    (*this).email="0";
    (*this).password="0";
    (*this).TipoCargo=Limpieza;
}