#include "../../include/DTyEnum/DTDatosEstadia.h"

DTHostal* DTDatosEstadia::getHostalDeEstadia(){
    return (*this).hostal;
}
DTHuesped* DTDatosEstadia::getHuespedDeEstadia(){
    return (*this).huesped;
}
DTHabitacion* DTDatosEstadia::getHabitacionDeEstadia(){
    return (*this).habitacion;
}
Date DTDatosEstadia::getFechaEntradaDeEstadia(){
    return (*this).checkIn;
}
Date* DTDatosEstadia::getFechaSalidaDeEstadia(){
    return (*this).checkOut;
}

void DTDatosEstadia::setHostal(DTHostal* host){
    (*this).hostal = host;
}

void DTDatosEstadia::setHuesped(DTHuesped* hues){
    (*this).huesped = hues;
}

void DTDatosEstadia::setHabitacion(DTHabitacion* hab){
    (*this).habitacion = hab;
}

void DTDatosEstadia::setCheckIn(Date inicio){
    (*this).checkIn = inicio;
}

void DTDatosEstadia::setCheckOut(Date* final){
    (*this).checkOut = final;
}

DTDatosEstadia::DTDatosEstadia(DTHostal* dth,DTHabitacion* dthab,DTHuesped* dthus,Date fe,Date* fs){
    (*this).hostal=dth;
    (*this).habitacion=dthab;
    (*this).huesped=dthus;
    (*this).checkIn=fe;
    (*this).checkOut=fs;
}