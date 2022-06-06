#ifndef RESERVA
#define RESERVA

#include "../DTyEnum/EstadoReserva.h"
#include "../habitacion.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class reserva{
    protected:
        habitacion* habitacion;

        int codigo;
        Date checkIn;
        Date checkOut;
        EstadoReserva estado;
        float Costo;
    public:
        virtual int getCodigo()=0;
        virtual Date getCheckIn()=0;
        virtual Date getCheckOut()=0;
        virtual EstadoReserva getEstado()=0;
        virtual float getCosto()=0;
        virtual void setCodigo(int)=0;
        virtual void setCheckIn(Date)=0;
        virtual void setCheckOut(Date)=0;
        virtual void setEstado(EstadoReserva)=0;
        virtual void setCosto(float)=0;
        virtual ~reserva()=0;
};

#endif