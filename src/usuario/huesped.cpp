#include "../../include/usuario/huesped.h"

DTHuesped* huesped::darDatos(){
    DTHuesped* resultado = new DTHuesped((*this).nombre , (*this).email , (*this).password , (*this).esFinger);
    return resultado;
}