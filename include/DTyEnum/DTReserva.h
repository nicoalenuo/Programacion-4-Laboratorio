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
        EstadoReserva estado;
        float costo;
    public:
        virtual ~DTReserva()=0;
        
        virtual int getCodigo()=0;
        virtual void setCodigo(int codigo)=0;
        virtual Date getCheckIn()=0;
        virtual void setCheckIn(Date checkIn)=0;
        virtual Date getCheckOut()=0;
        virtual void setCheckOut(Date checkOut)=0;
        virtual EstadoReserva getEstado()=0;
        virtual void setEstado(EstadoReserva estado)=0;
        virtual float getCosto()=0;
        virtual void setCosto(float Costo)=0;
};

#endif