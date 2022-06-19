#include "../../include/DTyEnum/DTReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int Codigo, Date CheckIn, Date CheckOut,EstadoReserva e, float Costo){
    (*this).codigo = Codigo;
    (*this).checkIn = CheckIn;
    (*this).checkOut = CheckOut;
    (*this).estado=e;
    (*this).costo= Costo;
}

int DTReservaIndividual::getCodigo() {
    return (*this).codigo;
}

void DTReservaIndividual::setCodigo(int codigo) {
    (*this).codigo = codigo;
}

Date DTReservaIndividual::getCheckIn() {
    return (*this).checkIn;
}

void DTReservaIndividual::setCheckIn(Date checkIn) {
    (*this).checkIn = checkIn;
}

Date DTReservaIndividual::getCheckOut() {
    return (*this).checkOut;
}

void DTReservaIndividual::setCheckOut(Date checkOut) {
    (*this).checkOut = checkOut;
}

EstadoReserva DTReservaIndividual::getEstado() {
    return (*this).estado;
}

void DTReservaIndividual::setEstado(EstadoReserva estado) {
    (*this).estado = estado;
}

float DTReservaIndividual::getCosto() {
    return (*this).costo;
}

void DTReservaIndividual::setCosto(float Costo) {
    (*this).costo = Costo;
}

DTReservaIndividual::~DTReservaIndividual(){
   // [FATLTA HACER]
}