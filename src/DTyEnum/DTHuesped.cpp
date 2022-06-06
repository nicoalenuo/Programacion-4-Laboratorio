#include "../../include/DTyEnum/DTHuesped.h"

DTHuesped::DTHuesped(string nombre,string email,string password,bool esFinger){
    (*this).nombre=nombre;
    (*this).email=email;
    (*this).password=password;
    (*this).esFinger=esFinger;
}