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
        int getNumero();
        float getPrecio();
        int getCapacidad();
        void setNumero(int);
        void setPrecio(float);
        void setCapacidad(int);
};

#endif