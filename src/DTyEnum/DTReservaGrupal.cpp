#include "../../include/DTyEnum/DTReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal(int Codigo,Date CheckIn,Date CheckOut,EstadoReserva e,float Costo,int CantHues){
    this->codigo = Codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = e;
    this->costo = Costo;
    this->CantHuespedes = CantHues;
}

DTReservaGrupal::~DTReservaGrupal(){
   // [FATLTA HACER]
}