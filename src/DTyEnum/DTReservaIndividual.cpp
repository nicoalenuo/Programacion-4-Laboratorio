#include "../../include/DTyEnum/DTReservaIndividual.h"

DTReservaIndividual::~DTReservaIndividual(){
}

DTReservaIndividual::DTReservaIndividual(int codigo,Date checkIn,Date checkOut,EstadoReserva estado,float costo){
    (*this).codigo=codigo;
    (*this).checkIn=checkIn;
    (*this).checkOut=checkOut;
    (*this).estado=estado;
    (*this).costo=costo;
}