#include "../../include/DTyEnum/DTReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal(int Codigo,Date CheckIn,Date CheckOut,EstadoReserva e,float Costo,int CantHues){
    this->codigo = Codigo;
    this->checkIn = CheckIn;
    this->checkOut = CheckOut;
    this->estado = e;
    this->costo = Costo;
    this->CantHuespedes = CantHues;
}

int DTReservaGrupal::getCodigo() {
    return (*this).codigo;
}

void DTReservaGrupal::setCodigo(int codigo) {
    (*this).codigo = codigo;
}

Date DTReservaGrupal::getCheckIn() {
    return (*this).checkIn;
}

void DTReservaGrupal::setCheckIn(Date checkIn) {
    (*this).checkIn = checkIn;
}

Date DTReservaGrupal::getCheckOut() {
    return (*this).checkOut;
}

void DTReservaGrupal::setCheckOut(Date checkOut) {
    (*this).checkOut = checkOut;
}

EstadoReserva DTReservaGrupal::getEstado() {
    return (*this).estado;
}

void DTReservaGrupal::setEstado(EstadoReserva estado) {
    (*this).estado = estado;
}

int DTReservaGrupal::getCantHuespedes() {
    return (*this).CantHuespedes;
}

void DTReservaGrupal::setCantHuespedes(int CantHuespedes) {
    (*this).CantHuespedes = CantHuespedes;
}

float DTReservaGrupal::getCosto() {
    return (*this).costo;
}

void DTReservaGrupal::setCosto(float Costo) {
    (*this).costo = Costo;
}

DTReservaGrupal::~DTReservaGrupal(){
   // [FATLTA HACER]
}