#ifndef DTHABITACION
#define DTHABITACION

#include <iostream>
#include <stdio.h>
using namespace std;

class DTHabitacion {
    private:
        int numero;
        float precio;
        int capacidad;
    public:
        ~DTHabitacion();
        DTHabitacion(int,float,int);
        
        int getNumero();
        float getPrecio();
        int getCapacidad();
        void setNumero(int);
        void setPrecio(float);
        void setCapacidad(int);
};

#endif