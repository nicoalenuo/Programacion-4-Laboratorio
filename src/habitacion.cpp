#include "../include/habitacion.h"

habitacion::habitacion(int numero, float precio, int capacidad){
        (*this).numero = numero;
        (*this).precio = precio;
        (*this).capacidad = capacidad;
}
void habitacion::agregarReservaAMap(reserva * r){
        (*this).reservas.insert(pair<int,reserva*>((*r).getCodigo(),r));
}
