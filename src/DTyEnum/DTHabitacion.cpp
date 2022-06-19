#include "../../include/DTyEnum/DTHabitacion.h"

DTHabitacion::~DTHabitacion(){
}

int DTHabitacion::getNumero(){
    return numero;
}

float DTHabitacion::getPrecio(){
    return precio;
}

int DTHabitacion::getCapacidad(){
    return capacidad;
}

void DTHabitacion::setNumero(int n){
    numero=n;
}

void DTHabitacion::setPrecio(float p){
    precio=p;
}

void DTHabitacion::setCapacidad(int c){
    capacidad=c;
}

DTHabitacion::DTHabitacion(  int numero, float precio,int capacidad){
    (*this).numero = numero;
    (*this).precio = precio;
    (*this).capacidad = capacidad;
}