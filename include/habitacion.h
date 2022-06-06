#ifndef HABITACION
#define HABITACION

#include "reserva/reserva.h"
#include "DTyEnum/DTHostal.h"
#include "DTyEnum/DTEstadia.h"
#include "DTyEnum/DTDatosEstadia.h"

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
        ~habitacion();

        void agregarReserva(reserva* r);
        bool perteneceAHostal(DTHostal* h);
        map<int, DTReserva*> obtenerReservas();
        virtual map<int, DTEstadia*> obtenerEstadias();
        DTDatosEstadias* obtenerDatos();
        DTReserva* obtenerReservaDeEstadia();
};    

#endif