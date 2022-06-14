#include "../../include/DTyEnum/DTHabitacion.h"

DTHabitacion::~DTHabitacion(){
}

DTHabitacion::DTHabitacion(  int numero, float precio,int capacidad){
    (*this).numero = numero;
    (*this).precio = precio;
    (*this).capacidad = capacidad;
}