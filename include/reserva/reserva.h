#ifndef RESERVA
#define RESERVA

#include "../DTyEnum/EstadoReserva.h"
#include "../habitacion.h"
#include "../DTyEnum/DTHostal.h"
#include "../DTyEnum/DTHabitacion.h"
#include "Huesped-Individual.h"
#include "../DTyEnum/DTReservaIndividual.h"
#include "../DTyEnum/DTReservaGrupal.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class habitacion;

class reserva{
    protected:
        habitacion* habitacionAsoc;

        int codigo;
        Date checkIn;
        Date checkOut;
        EstadoReserva estado;
        float costo;
    public:
        virtual ~reserva()=0;
        virtual habitacion* getHabitacion()=0;
        virtual int getCodigo()=0;
        virtual Date getCheckIn()=0;
        virtual Date getCheckOut()=0;
        virtual EstadoReserva getEstado()=0;
        virtual float getCosto()=0;
        virtual void setHabitacion(habitacion*)=0;
        virtual void setCodigo(int)=0;
        virtual void setCheckIn(Date)=0;
        virtual void setCheckOut(Date)=0;
        virtual void setEstado(EstadoReserva)=0;
        virtual void setCosto(float)=0;
        virtual void finalizarSiEsReservaBuscada(string, string)=0;
        virtual bool perteneceHusped(string)=0;
        virtual void darBajaReserva()=0;
        virtual map<int, DTEstadia*> obtenerEstadias()=0;
        virtual DTEstadia* obtenerEstadia()=0;
        virtual DTReserva* obtenerResrvaDeEst()=0;
        virtual bool tieneEstadiaFinalizadaDeHuesped(string)=0;
        virtual DTEstadia* darEstadiaDeHuesped(string)=0;
        virtual DTHostal* getDTHostal()=0;
        virtual DTReserva* getDTReserva()=0;
        virtual bool tieneEstadia(DTEstadia*)=0;
        virtual DTHuesped* darHuespedConEstadia(DTEstadia*)=0;
        virtual DTHabitacion* darDatosHabitacion()=0;
};

#endif