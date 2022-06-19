#include "../../include/DTyEnum/DTHostal.h"

DTHostal::~DTHostal(){
}

string DTHostal::getNombre() {
    return (*this).nombre;
}

void DTHostal::setNombre(string nombre) {
    (*this).nombre = nombre;
}

string DTHostal::getDireccion() {
    return (*this).direccion;
}

void DTHostal::setDireccion(string direccion) {
    (*this).direccion = direccion;
}

string DTHostal::getTelefono() {
    return (*this).telefono;
}

void DTHostal::setTelefono(string telefono) {
    (*this).telefono = telefono;
}

float DTHostal::getCalificacionPromedio() {
    return (*this).calificacionPromedio;
}

void DTHostal::setCalificacionPromedio(float calificacionPromedio) {
    (*this).calificacionPromedio = calificacionPromedio;
}

DTHostal::DTHostal(string nombre,string direccion,string telefono, float calificacionPromedio){
    (*this).nombre=nombre;
    (*this).direccion=direccion;
    (*this).telefono=telefono;
    (*this).calificacionPromedio=calificacionPromedio;
}