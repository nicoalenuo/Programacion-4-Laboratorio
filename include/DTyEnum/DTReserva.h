#ifndef DTRESERVA
#define DTRESERVA

#include "EstadoReserva.h"
#include "Date.h"

#include <iostream>
#include <stdio.h>
using namespace std;

class DTReserva {
    protected:
        int codigo;
        Date checkIn;
        Date checkOut;
        float costo;
        EstadoReserva estado;
    public:
        virtual ~DTReserva()=0;
        
        virtual int getCodigo()=0;
        virtual void setCodigo(int)=0;
        virtual Date getCheckIn()=0;
        virtual void setCheckIn(Date)=0;
        virtual Date getCheckOut()=0;
        virtual void setCheckOut(Date)=0;
        virtual float getCosto()=0;
        virtual void setCosto(float)=0;
        virtual EstadoReserva getEstado()=0;
        virtual void setEstado(EstadoReserva)=0;
};

#endif