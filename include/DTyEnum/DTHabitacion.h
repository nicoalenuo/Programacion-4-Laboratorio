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
        int getNumero(){
            return numero;
        }
        float getPrecio(){
            return precio;
        }
        int getCapacidad(){
            return capacidad;
        }
        void setNumero(int n){
            numero=n;
        }
        void setPrecio(float p){
            precio=p;
        }
        void setCapacidad(int c){
            capacidad=c;
        }
};

#endif