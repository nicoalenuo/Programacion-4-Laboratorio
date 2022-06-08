#include "../include/habitacion.h"
void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}
void habitacion::guij(){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}