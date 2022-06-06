#include "../../include/usuario/huesped.h"

DTHuesped huesped::darDatos(){
    DTHuesped resultado = DTHuesped((*this).nombre , (*this).email , (*this).password , (*this).esFinger);
    return resultado;
}