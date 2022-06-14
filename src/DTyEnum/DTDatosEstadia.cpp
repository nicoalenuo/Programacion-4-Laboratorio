#include "../../include/DTyEnum/DTDatosEstadia.h"

DTDatosEstadia::~DTDatosEstadia(){
}

DTDatosEstadia::DTDatosEstadia(DTHostal* hostal, DTHabitacion* habitacion, DTHuesped* huesped, Date checkIn, Date* CheckOut){
    (*this).hostal = hostal;
    (*this).habitacion = habitacion;
    (*this).huesped = huesped;
    (*this).checkIn = checkIn;
    (*this).checkOut = checkOut;
}