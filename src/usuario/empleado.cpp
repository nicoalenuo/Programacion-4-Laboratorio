#include "../include/usuario/empleado.h"

DTEmpleado* empleado::darDatos(){
    DTEmpleado* resultado=new DTEmpleado((*this).nombre , (*this).email , (*this).password , (*this).TipoCargo);
    return resultado;
}