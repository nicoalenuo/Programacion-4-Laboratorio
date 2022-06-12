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
        hostal* darHostal();
        DTHabitacion* darDatos();
        void agregarReserva(reserva*);
        bool perteneceAHostal(DTHostal*);
        bool disponibleEn(Date,Date);
        map<int, DTReserva*> obtenerReservas();
        map<int, DTEstadia*> obtenerEstadias();
        DTDatosEstadia* obtenerDatos();
        DTReserva* obtenerReservaDeEstadia();
        void agregarReservaAMap(reserva * );
       
};    

#endif