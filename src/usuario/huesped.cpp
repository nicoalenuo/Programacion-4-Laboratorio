#include "../../include/usuario/huesped.h"

DTHuesped* huesped::darDatos(){
    DTHuesped* resultado = new DTHuesped((*this).nombre , (*this).email , (*this).password , (*this).esFinger);
    return resultado;
}
huesped::huesped(string nombre, string email, string password, bool esFinger){
    (*this).nombre = nombre;
    (*this).email = email;
    (*this).password = password;
    (*this).esFinger = esFinger;
}