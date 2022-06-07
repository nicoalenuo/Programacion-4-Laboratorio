#include "../../include/DTyEnum/DTHostal.h"

DTHostal::~DTHostal(){
}

DTHostal::DTHostal(string nombre,string direccion,string telefono, float calificacionPromedio){
    (*this).nombre=nombre;
    (*this).direccion=direccion;
    (*this).telefono=telefono;
    (*this).calificacionPromedio=calificacionPromedio;
}