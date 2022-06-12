#include "../../include/DTyEnum/DTReservaGrupal.h"

DTReservaGrupal::~DTReservaGrupal(){
}

DTReservaGrupal::DTReservaGrupal(int codigo,Date checkIn,Date checkOut,EstadoReserva estado,float costo,int cantHuespedes){
    (*this).codigo=codigo;
    (*this).checkIn=checkIn;
    (*this).checkOut=checkOut;
    (*this).estado=estado;
    (*this).costo=costo;
    (*this).cantHuespedes=cantHuespedes;
}
