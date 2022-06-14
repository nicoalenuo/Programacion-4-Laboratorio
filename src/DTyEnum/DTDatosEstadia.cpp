#include "../../include/DTyEnum/DTDatosEstadia.h"

DTDatosEstadia::DTDatosEstadia(DTHostal* dth,DTHabitacion* dthab,DTHuesped* dthus,Date fe,Date* fs){
    (*this).hostal=dth;
    (*this).habitacion=dthab;
    (*this).huesped=dthus;
    (*this).checkIn=fe;
    (*this).checkOut=fs;
}