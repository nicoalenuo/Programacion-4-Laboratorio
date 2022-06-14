#ifndef HABITACION
#define HABITACION

#include "reserva/reserva.h"
#include "DTyEnum/DTReserva.h" //Agregado
#include "DTyEnum/DTHostal.h"
#include "DTyEnum/DTEstadia.h"
#include "DTyEnum/DTHabitacion.h"
#include "DTyEnum/DTDatosEstadia.h"
#include "hostal.h"

#include <iostream>
#include <stdio.h>
using namespace std;
#include <map>

class reserva; //Agregado
class hostal;

class habitacion{
    private:
        map<int,reserva*> reservas;

        int numero;
        float precio;
        int capacidad;
    public:
        ~habitacion();
        habitacion(int,float,int);

        int getNumero();
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

        DTHabitacion* darDatos();
        void agregarReserva(reserva*);
        bool perteneceAHostal(DTHostal*);
        map<int, DTReserva*> obtenerReservas();
        map<int, DTEstadia*> obtenerEstadias();
        DTDatosEstadia* obtenerDatos();
        hostal* darHostal();
        void darBajaReserva(int);
        DTReserva* obtenerReservaDeEstadia();
        void agregarReservaAMap(reserva * );
        bool disponibleEn(Date,Date);
};    

#endif