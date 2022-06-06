#ifndef HABITACION
#define HABITACION

#include "reserva/reserva.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class habitacion{
    private:
        map<int,reserva*> reservas;

        int numero;
        float precio;
        int capacidad;
    public:
        int getNumero(){
            return (*this).numero;
        }
        float getPrecio(){
            return (*this).precio;
        }
        int getCapacidad(){
            return (*this).capacidad;
        }
        void setNumero(int n){
            (*this).numero=n;
        }
        void setPrecio(float p){
            (*this).precio=p;
        }
        void setCapacidad(int c){
            (*this).capacidad=c;
        }
        ~habitacion();
        
};

#endif