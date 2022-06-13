#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "reserva.h"
//Cosas que agregue
#include "Huesped-Individual.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class individual:public reserva{
    private:
        huespedIndividual* huesInd;
    public:
        ~individual();
        individual(int,Date,Date,EstadoReserva,float);

        habitacion* getHabitacion(){
            return habitacionAsoc;
        }
        int getCodigo(){
            return codigo;
        }
        Date getCheckIn(){
            return checkIn;
        }
        Date getCheckOut(){
            return checkOut;
        }
        EstadoReserva getEstado(){
            return estado;
        }
        float getCosto(){
            return costo;
        }
        void setHabitacion(habitacion* h){
            habitacionAsoc=h;
        }
        void setCodigo(int c){
            codigo=c;
        }
        void setCheckIn(Date ci){
            checkIn=ci;
        }
        void setCheckOut(Date co){
            checkOut=co;
        }
        void setEstado(EstadoReserva e){
            estado=e;
        }
        void setCosto(float c){
            costo=c;
        }
        
        DTReservaIndividual* darDatos();
        void finalizarSiEsReservaBuscada(string, string);
        bool perteneceHusped(string);
        string getTipoReserva();
        void darBajaReserva();
        map<int, DTEstadia*> obtenerEstadias();
        bool tieneEstadia(DTEstadia*);
        bool tieneEstadiaFinalizadaDeHuesped(string);
        DTEstadia* darEstadiaDeHuesped(string);

        //Cosas que agregue
        huespedIndividual* getHuespedIndividual(){
            return huesInd;
        }
        void setHuespedIndividual(huespedIndividual* hi){
            huesInd = hi;
        }
        DTHuesped* darHuespedConEstadia(DTEstadia*);
        DTHabitacion* darDatosHabitacion();
};

#endif