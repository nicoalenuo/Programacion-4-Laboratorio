#include "../../include/DTyEnum/DTReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int Codigo, Date CheckIn, Date CheckOut,EstadoReserva e, float Costo){
    (*this).codigo = Codigo;
    (*this).checkIn = CheckIn;
    (*this).checkOut =checkOut;
    (*this).costo= Costo;
}

DTReservaIndividual::~DTReservaIndividual(){
   // [FATLTA HACER]
}