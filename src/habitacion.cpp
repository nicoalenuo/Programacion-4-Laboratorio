#include "../include/habitacion.h"
void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}
void habitacion::hola(){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}