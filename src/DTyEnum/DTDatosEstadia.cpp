#include "../../include/DTyEnum/DTDatosEstadia.h"


DTDatosEstadia::DTDatosEstadia(DTHostal* hostal,DTHuesped* huesped,DTHabitacion* habitacion,Date checkIn,Date checkOut){
    (*this).hostal=hostal;
    (*this).huesped=huesped;
    (*this).habitacion=habitacion;
    (*this).checkIn=checkIn;
    (*this).checkOut=checkOut;
}
DTDatosEstadia::~DTDatosEstadia(){
}