#include "../include/usuario/empleado.h"

DTEmpleado empleado::darDatos(){
    DTEmpleado resultado=DTEmpleado((*this).nombre , (*this).email , (*this).password , (*this).TipoCargo);
    return resultado;
}