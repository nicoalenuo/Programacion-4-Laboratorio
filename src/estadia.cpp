#include "../include/estadia.h"
#include "../include/FechaSistema.h"

estadia::estadia(Date fechaEntrada,Date* fechaSalida,int codigo){
    (*this).fechaEntrada=fechaEntrada;
    (*this).fechaSalida=fechaSalida;
    (*this).codigo=codigo;
}
estadia::~estadia(){
}
DTEstadia* estadia::darDatos(){
    return NULL;
}
bool estadia::estaActiva(){
    return (fechaSalida == NULL) ? true:false;
}
void estadia::finalizarEstadiaActiva(){
    if (estaActiva()){
        FechaSistema* fs=FechaSistema::getInstance();
        Date* fechaActual = &(*fs).getFechaActual();
        setFechaSalida(fechaActual);
    }
}
void estadia::eliminarEstadia(){

}
DTCalificacion* estadia::obtenerCalificacionDeEstadia(){
    return NULL;
}