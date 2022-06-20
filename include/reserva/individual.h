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
        individual(DTReservaIndividual*, habitacion*,DTHuesped*);

        habitacion* getHabitacion();
        int getCodigo();
        Date getCheckIn();
        Date getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        void setHabitacion(habitacion*);
        void setCodigo(int);
        void setCheckIn(Date);
        void setCheckOut(Date);
        void setEstado(EstadoReserva);
        void setCosto(float);
        void finalizarSiEsReservaBuscada(string, string);
        bool perteneceHusped(string);
        void darBajaReserva();
        map<int, DTEstadia*> obtenerEstadias();
        bool tieneEstadiaFinalizadaDeHuespedEnHostal(string);
        DTEstadia* darEstadiaDeHuesped(string);
        huespedIndividual* getHuespedIndividual();
        void setHuespedIndividual(huespedIndividual*);
        DTHostal* getDTHostal();
        DTReserva* getDTReserva();
        bool tieneEstadia(DTEstadia*);
        DTHuesped* darHuespedConEstadia(DTEstadia*);
        DTHabitacion* darDatosHabitacion();
};

#endif